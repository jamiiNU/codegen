var http = require('http'),
	fs = require('fs'),
	S = require('string'),
	P = require('path');

function writeHeaderFile(fileName, body, fileNameCachedArray) {
	var i,
		max,
		fileNameIndex = 1,
		fileAttachmentName = '',
		fileAttachmentNameArray = ['.h', '.csv'],
		dir = P.dirname(process.execPath) + '/../result';

	fileName = fileName.replace(/[/\\?%*:|"<>]/g, '-');
	for (i = 0, max = fileAttachmentNameArray.length; i < max; i++) {
		if (fileName.indexOf(fileAttachmentNameArray[i]) !== -1) {
			fileAttachmentName = fileAttachmentNameArray[i];
			break;
		}
	}
	if (fileAttachmentName === '') {
		console.log('Failed to find a fileAttachmentName');
		return;
	}
	while (fileNameCachedArray.indexOf(fileName) !== -1 && fileNameIndex < 20) {
		fileName = S(fileName).between('', fileAttachmentName).s;
		if (fileNameIndex === 1) {
			fileName += ' - Copy' + fileAttachmentName;
		}
		else {
			fileName += ' - Copy (' + fileNameIndex + ')' + fileAttachmentName;
		}
		fileNameIndex++;
	}
	console.log('fileName: ' + fileName);
	if (!fs.existsSync(dir)){
		fs.mkdirSync(dir);
	}
	fs.writeFile(dir + '/' + fileName, body, 'utf8', function(err, result) {
		if(err) console.log('error', err);
	});
	fileNameCachedArray.push(fileName);
}

http.createServer(function (req, res) {
	var body = '',
		body1,
		whileCount = 1,
		fileName,
		fileNameCachedArray = [];

	res.writeHead(200, {
		'Context-Type': 'text/plain',
		'Access-Control-Allow-Origin': '*'
	});

	fileName = S(req.url).between('/').s;
	if (fileName === '') {
		fileName = 'dummy.txt';
	}

	req.on('data', function (chunk) {
		body += chunk;
	});
	req.on('end', function() {
		if (fileName.indexOf('AllData') == 0) {
			whileCount = 0;
			do {
				fileName = S(body).between('//fileName:', '\n').s;
				body = S(body).between('//fileName:' + fileName + '\n').s;
				if (body.indexOf('//fileName:') !== -1) {
					body1 = S(body).between('', '//fileName:').s;
				}
				else {
					// the last file
					body1 = body;
				}
				writeHeaderFile(fileName, body1, fileNameCachedArray);
			} while(body1 !== body && whileCount++ < 5000);
		}
		else {
			writeHeaderFile(fileName, body, fileNameCachedArray);
		}
		res.end('{"msg": "OK"}');
	});
}).listen(4560, '127.0.0.1');
console.log('Server running at http://127.0.0.1:4560/');
