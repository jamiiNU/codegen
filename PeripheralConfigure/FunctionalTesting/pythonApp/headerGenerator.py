import os
import json
import webbrowser
import subprocess
import threading
import winreg
import time
from optparse import OptionParser
from http.server import BaseHTTPRequestHandler, HTTPServer
from urllib.parse import urlparse

def find_between( s, first, last ):
	try:
		start = s.index( first ) + len( first )
		end = s.index( last, start )
		return s[start:end]
	except ValueError:
		return ""

def closeBrowserIE():
	try:
		os.system("taskkill /im iexplore.exe /f")
	except:
		print('something wrong when taskkill /im iexplore.exe /f')

def closeHttpServer():
	try:
		os.system("taskkill /im createHttpServer.exe /f")
	except:
		print('something wrong when taskkill /im createHttpServer.exe /f')

def startFunctionalTesting(bFirstTime = True):
	global g_options
	headerGeneratorInput = json.dumps({'chipName': g_options.chipName, 'fileName': g_options.fileName, 'tagId': g_options.tagId, 'runNumber': g_options.runNumber, 'server': g_options.server, 'forBaseIndex': str(g_forBaseIndex)})
	try:
		if os.path.isfile('headerGenerator.txt'):
			os.remove("headerGenerator.txt")
		text_file = open("headerGenerator.txt", "w+")
		text_file.write(headerGeneratorInput)
		text_file.close()
	except:
		print('something wrong when updating headerGenerator.txt')
	# print a warning while using the test server
	bExit = False
	if (g_options.passIE == "0") and (g_options.server != "d0") and (g_options.server != "d1") and bFirstTime:
		res = subprocess.check_output(['tasklist'])
		if 'iexplore.exe' in str(res):
			answer = input("Your IE is running, but the test server will close it. Do you want to continue the functional testing?\nEnter yes(y) or no(n):")
			if answer == "yes" or answer == "y":
				print ('OK. Let\'s go.')
				closeBrowserIE()
			elif answer == "no" or answer == "n":
				print ('The functional testing is being closed. See you next time.')
				bExit = True
			else:
				print("Your answer is ambiguous. Please enter yes(y) or no(n).")
				bExit = True
	if not bExit:
		if bFirstTime:
			bExit = True
			# launch a http server from Node.js and a test server from pythonApp
			subprocess.Popen("nodejsApp/createHttpServer.exe")
			print ('\nwaiting for the launch of nodejsApp...')
			timeout = time.time() + 60 * 1 # 1 minutes from now
			while True:
				res = subprocess.check_output(['tasklist'])
				if 'createHttpServer.exe' in str(res):
					bExit = False
					break
				if time.time() > timeout:
					break
				time.sleep(2)
				print (str(timeout - time.time()) + ' left')
			if not bExit:
				httpd = testServer()
				httpd.start()
			else:
				print('the test server was closed because the nodejsApp failed to launch')
		# run functional test
		webbrowser.open('file://' + os.path.realpath("../NuTool_PeripheralConfigure_Test.htm"))

def set_reg(name, value):
	REG_PATH = r"SOFTWARE\Microsoft\Internet Explorer\Main\FeatureControl\FEATURE_LOCALMACHINE_LOCKDOWN"
	try:
		winreg.CreateKey(winreg.HKEY_CURRENT_USER, REG_PATH)
		registry_key = winreg.OpenKey(winreg.HKEY_CURRENT_USER, REG_PATH, 0,
									  winreg.KEY_WRITE)
		winreg.SetValueEx(registry_key, name, 0, winreg.REG_DWORD, value)
		winreg.CloseKey(registry_key)
		return True
	except WindowsError:
		return False

# HTTPRequestHandler class
class testHTTPServer_RequestHandler(BaseHTTPRequestHandler):
	def do_POST(self):
		global g_options
		global g_forBase
		global g_forBaseIndex
		global g_showErrorMessage
		content_length = int(self.headers['Content-Length'])
		body = self.rfile.read(content_length)
		bodyMessage = str(urlparse(body))
		print('bodyMessage:' + bodyMessage)
		self.send_response(200)
		self.end_headers()
		if (g_options.server == "d0") or (g_options.server == "d1") or ('showErrorMessage' in bodyMessage):
			g_showErrorMessage = True
		# decide next step
		if 'shutdown' in bodyMessage:
			if (not g_showErrorMessage):
				closeBrowserIE()
			if len(g_fileNameList) == 1:
				if (g_options.server != "d0") and (g_options.server != "d1"):
					closeHttpServer()
				print('the test server was closed because the functional testing was done')
				self.server.running = False
			else:
				g_fileNameList.remove(g_options.fileName)
				g_options.fileName = g_fileNameList[0]
				g_forBaseIndex = 0
				startFunctionalTesting(False)
			return
		elif 'forBaseIndex' in bodyMessage:
			# prepare headerGenerator.txt
			g_forBaseIndex = int(find_between(bodyMessage, 'forBaseIndex(' , ')'))
			g_forBaseIndex = g_forBaseIndex + 1
			print('tag number:' + str(g_forBaseIndex * g_forBase) + '~' + str((g_forBaseIndex + 1) * g_forBase - 1))
			headerGeneratorInput = json.dumps({'chipName': g_options.chipName, 'fileName': g_options.fileName, 'tagId': 'none', 'runNumber': g_options.runNumber, 'server': g_options.server, 'forBaseIndex': str(g_forBaseIndex)})
			try:
				if os.path.isfile('headerGenerator.txt'):
					os.remove("headerGenerator.txt")
				text_file = open("headerGenerator.txt", "w+")
				text_file.write(headerGeneratorInput)
				text_file.close()
			except:
				print('something wrong when updating headerGenerator.txt')
			# run the functional test
			if (not g_showErrorMessage):
				closeBrowserIE()
			webbrowser.open('file://' + os.path.realpath("../NuTool_PeripheralConfigure_Test.htm"))
		else:
			print('the test server was closed because the functional testing faced a problem')
			self.server.running = False
			closeHttpServer()

class testServer:
	global g_options
	global g_forBase
	def __init__(self, port = 8081):
		self._server = HTTPServer(('127.0.0.1', port), testHTTPServer_RequestHandler)
		self._thread = threading.Thread(target=self.run)
		self._thread.deamon = True

	def run(self):
		self._server.running = True
		while self._server.running:
			self._server.handle_request()

	def start(self):
		if (g_options.server == "1") or (g_options.server == "d1"):
			if g_options.tagId != "none":
				print('running a test server...\nstarted from tagId:' + g_options.tagId)
			else:
				print('running a test server...\ntag number:0~' + str(g_forBase - 1))
		else:
			print('\nrunning a test server...')
		self._thread.start()

	def shut_down(self):
		self._thread.close()
# main function
# make IE be able to run javascript files locally
if not set_reg('iexplore.exe', 0):
	print('something wrong when writing a value to registry')
# parse tool arguments
parser = OptionParser()
parser.add_option("-c", "--chip",    action="store", type="string", dest="chipName",  help="specify a chip name, e.g. M252KG6AE(default).",                       default="M252KG6AE")
parser.add_option("-t", "--txtFile", action="store", type="string", dest="fileName",  help="specify a txt  name, e.g. ACMP(default).",                            default="ACMP")
parser.add_option("-i", "--idOfTag", action="store", type="string", dest="tagId",     help="specify a tag id. e.g. UseACMP0ENBoolean. The default is none.",      default="none")
parser.add_option("-n", "--number",  action="store", type="string", dest="runNumber", help="specify how many tags to run. The default is -1. It means all.",      default="-1")
parser.add_option("-s", "--server",  action="store", type="string", dest="server",    help="specify the server mode. 0 means normal, and 1 means advanced.",      default="1")
parser.add_option("-p", "--passIE",  action="store", type="string", dest="passIE",    help="specify pass IE-running check. 0 means check, and 1 means no check.", default="0")
# global variables
(g_options, args) = parser.parse_args()
g_forBase = 10
g_forBaseIndex = 0
g_showErrorMessage = False
g_fileNameList = g_options.fileName.split('+')
# prepare headerGenerator.txt
if len(g_fileNameList) > 1:
	g_options.fileName = g_fileNameList[0]
	g_options.server = '1'
startFunctionalTesting()
