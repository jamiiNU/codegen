import os
import json
import webbrowser
import subprocess
import threading
from optparse import OptionParser
from http.server import BaseHTTPRequestHandler, HTTPServer
from urllib.parse import urlparse
import shutil
import time

def find_between( s, first, last ):
	try:
		start = s.index( first ) + len( first )
		end = s.index( last, start )
		return s[start:end]
	except ValueError:
		return ""

def startFunctionalTesting():
	global g_options
	csvGeneratorInput = json.dumps({'chipSeries': g_options.chipSeries, 'partNumber': g_options.partNumber})
	try:
		if os.path.isfile('csvGenerator.txt'):
			os.remove("csvGenerator.txt")
		text_file = open("csvGenerator.txt", "w+")
		text_file.write(csvGeneratorInput)
		text_file.close()
	except:
		print('something wrong when updating csvGenerator.txt')
	# print a warning while using the test server
	bExit = False
	res = subprocess.check_output(['tasklist'])
	if 'iexplore.exe' in str(res):
		answer = input("Your IE is running, but the test server will close it. Do you want to continue the functional testing?\nEnter yes(y) or no(n):")
		if answer == "yes" or answer == "y":
			print ('OK. Let\'s go.')
		elif answer == "no" or answer == "n":
			print ('The functional testing is being closed. See you next time.')
			bExit = True
		else:
			print("Your answer is ambiguous. Please enter yes(y) or no(n).")
			bExit = True
	if not bExit:
		# launch a http server from Node.js and a test server from pythonApp
		subprocess.Popen("nodejsApp/createHttpServer.exe")
		time.sleep(3)
		httpd = testServer()
		httpd.start()
		# run functional test
		webbrowser.open('file://' + os.path.realpath("../NuTool_PinConfigure_Test.htm"))

def addNecessaryFiles():
	filesToAdd = \
	'funcunit.js',\
	'jquery-1.11.1.js',\
	'NuTool_PinConfigure_Test.htm',\
	'NuTool_PinConfigure_Test.js',\
	'qunit-1.15.0.css',\
	'qunit-1.15.0.js',\

	for file in filesToAdd:
		# remove old files
		if os.path.isfile('../' + file) and os.path.isfile("csvGeneratorRequiredFiles/" + file):
			os.remove('../' + file)
			shutil.copyfile("csvGeneratorRequiredFiles/" + file , "../" + file)
		elif not os.path.isfile('../' + file) and os.path.isfile("csvGeneratorRequiredFiles/" + file):
			shutil.copyfile("csvGeneratorRequiredFiles/" + file , "../" + file)

# HTTPRequestHandler class
class testHTTPServer_RequestHandler(BaseHTTPRequestHandler):
	def do_POST(self):
		global g_options
		global g_showErrorMessage
		content_length = int(self.headers['Content-Length'])
		body = self.rfile.read(content_length)
		bodyMessage = str(urlparse(body))
		print(bodyMessage)
		self.send_response(200)
		self.end_headers()
		if 'showErrorMessage' in bodyMessage:
			g_showErrorMessage = True
		# decide next step
		if 'shutdown' in bodyMessage:
			if (not g_showErrorMessage):
				try:
					os.system("taskkill /im iexplore.exe /f")
				except:
					print('something wrong when taskkill /im iexplore.exe /f')
			try:
				os.system("taskkill /im createHttpServer.exe /f")
			except:
				print('something wrong when taskkill /im createHttpServer.exe /f')
			print('the test server was closed because the functional testing was done')
			self.server.running = False
			return

class testServer:
	global g_options
	def __init__(self, port = 8081):
		self._server = HTTPServer(('127.0.0.1', port), testHTTPServer_RequestHandler)
		self._thread = threading.Thread(target=self.run)
		self._thread.deamon = True

	def run(self):
		self._server.running = True
		while self._server.running:
			self._server.handle_request()

	def start(self):
		print('\nrunning a test server...')
		self._thread.start()

	def shut_down(self):
		self._thread.close()
# main function
# parse tool arguments
parser = OptionParser()
parser.add_option("-c", "--chip", action="store", type="string", dest="chipSeries", help="specify a chip series. e.g. M251(default).", default="M251")
parser.add_option("-p", "--part", action="store", type="string", dest="partNumber", help="specify a part number. e.g. ALL(default).",  default="ALL")
# global variables
(g_options, args) = parser.parse_args()
# added necessary files
addNecessaryFiles()
# start running the testing
g_showErrorMessage = False
startFunctionalTesting()
