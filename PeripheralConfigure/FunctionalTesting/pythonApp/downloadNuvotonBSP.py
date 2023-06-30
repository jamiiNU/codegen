import os
import webbrowser
import subprocess
import ctypes
import shutil
import zipfile
from optparse import OptionParser

def findArchivePath():
	global g_archivePath
	if is_64bit():
		g_archivePath = 'C:/Program Files (x86)/Nuvoton Tools/NuCodeGen/archive/'
	else:
		g_archivePath = 'C:/Program Files/Nuvoton Tools/NuCodeGen/archive/'

	g_archivePath += g_options.repository + '/'
	if g_options.manager.lower() == "gitlab":
		g_archivePath += "GitLab/"
	else:
		g_archivePath += "GitHub/"
	if not os.path.isdir(g_archivePath):
		os.makedirs(g_archivePath)

	if g_options.manager.lower() == "gitlab":
		file = g_archivePath + g_options.repository + "-" + g_options.commitId + ".zip"
	else:
		file = g_archivePath + g_options.commitId + ".zip"
	if os.path.isfile(file):
		return True
	else:
		return False

def wgetDownloadBSP():
	global g_options
	dirname = os.path.dirname(__file__)
	filename = os.path.join(dirname, 'wget.exe')
	numicroM23FamilyBSP = ["M2351BSP", "M2354BSP", "M251BSP", "M261BSP", "NUC1262BSP"]
	numicroM4FamilyBSP  = ["M451BSP",  "M4521BSP", "M471BSP", "M480BSP", "M472_442BSP", "NUC505BSP"]

	print("BSP is being downloaded. It may take a while...")
	wgetCommand = r' wget -P "' + g_archivePath +  '" -c -v https://'
	if g_options.manager.lower() == "gitlab":
		wgetCommand += "gitlab.com/" + g_options.organization + "/"
		if g_options.repository.upper() in numicroM23FamilyBSP:
			wgetCommand += "NuMicro-M23-Family/"
		elif g_options.repository.upper() in numicroM4FamilyBSP:
			wgetCommand += "NuMicro-M4-Family/"
		else:
			wgetCommand += "NuMicro-M0-Family/"
		wgetCommand += g_options.repository + "/-/archive/" + g_options.commitId + "/" + g_options.repository + "-" + g_options.commitId + ".zip"
	else:
		wgetCommand += "github.com/" + g_options.organization + "/" +  g_options.repository + "/archive/" + g_options.commitId + ".zip"

	wgetCommand += " -t 1"
	print(wgetCommand)
	try:
		subprocess.run(filename + wgetCommand)
		if g_options.manager.lower() == "gitlab":
			os.rename(g_archivePath + g_options.repository + "-" + g_options.commitId + ".zip", g_archivePath + g_options.repository + "-" + g_options.commitId[0:6] + ".zip")
		else:
			os.rename(g_archivePath + g_options.commitId + ".zip", g_archivePath + g_options.commitId[0:6] + ".zip")
	except Exception as e:
		print(e)
		print('something wrong when wget tried to download BSP')

def curlDownloadBSP():
	global g_options
	dirname = os.path.dirname(__file__)
	filename = os.path.join(dirname, 'curl.exe')
	numicroM23FamilyBSP = ["M2351BSP", "M2354BSP", "M251BSP", "M261BSP", "NUC1262BSP"]
	numicroM4FamilyBSP  = ["M451BSP",  "M4521BSP", "M471BSP", "M480BSP", "M472_442BSP", "NUC505BSP"]

	print("BSP is being downloaded. It may take a while...")

	additionalCommand = ""
	curlCommand = r' --output-dir "' + g_archivePath +  '" -LO "https://'
	if g_options.manager.lower() == "gitlab":
		curlCommand += "gitlab.com/" + g_options.organization + "/"
		if g_options.repository.upper() in numicroM23FamilyBSP:
			curlCommand += "NuMicro-M23-Family/"
		elif g_options.repository.upper() in numicroM4FamilyBSP:
			curlCommand += "NuMicro-M4-Family/"
		else:
			curlCommand += "NuMicro-M0-Family/"
		curlCommand += g_options.repository + "/-/archive/" + g_options.commitId + "/" + g_options.repository + "-" + g_options.commitId + ".zip"
	else:
		curlCommand += "github.com/" + g_options.organization + "/" +  g_options.repository + "/archive/" + g_options.commitId + ".zip"

	print(curlCommand)
	try:
		subprocess.run(filename + curlCommand)
	except:
		print('something wrong when wget tried to download BSP')

def unzipArchiveAndOpenBSPFolder():
	print("BSP is being unzipped. It may take a while...")
	unzippedFolder = g_archivePath + g_options.repository + "-" + g_options.commitId
	if os.path.isdir(unzippedFolder):
		print('removed the previous unzipped folder of ' + str(unzippedFolder))
		shutil.rmtree(unzippedFolder, ignore_errors=True)
	if g_options.manager.lower() == "gitlab":
		file = g_archivePath + g_options.repository + "-" + g_options.commitId[0:6] + ".zip"
	else:
		file = g_archivePath + g_options.commitId[0:6] + ".zip"

	with ZipfileLongPaths(file, 'r', allowZip64=True) as zip_ref:
		try:
			zip_ref.extractall(g_archivePath)
			zip_ref.close()
		except Exception as e:
			print(e)

	if is_64bit():
		moveToPath = 'C:/Program Files (x86)/Nuvoton Tools/NuCodeGen/'
	else:
		moveToPath = 'C:/Program Files/Nuvoton Tools/NuCodeGen/'
	moveToPath += g_options.version + '/BSP/'
	if not os.path.isdir(moveToPath):
		os.makedirs(moveToPath)
	if not os.path.isdir(moveToPath + g_options.repository):
		renamedRepository = g_options.repository
	elif not os.path.isdir(moveToPath + g_options.repository + " - Copy"):
		renamedRepository = g_options.repository + " - Copy"
	else:
		for i in range(2, 10000):
			if not os.path.isdir(moveToPath + g_options.repository + " - Copy (" + str(i) + ")"):
				renamedRepository = g_options.repository + " - Copy (" + str(i) + ")"
				break
	folder = g_archivePath + renamedRepository
	if os.path.isdir(folder):
		print('removed the previous renamed folder of ' + str(folder))
		shutil.rmtree(folder, ignore_errors=True)
	os.rename(unzippedFolder, g_archivePath + renamedRepository)
	shutil.move(g_archivePath + renamedRepository, moveToPath)
	os.startfile(moveToPath + renamedRepository)

class ZipfileLongPaths(zipfile.ZipFile):
	def _extract_member(self, member, targetpath, pwd):
		targetpath = winapi_path(targetpath)
		return zipfile.ZipFile._extract_member(self, member, targetpath, pwd)

def winapi_path(dos_path, encoding=None):
	path = os.path.abspath(dos_path)

	if path.startswith("\\\\"):
		path = "\\\\?\\UNC\\" + path[2:]
	else:
		path = "\\\\?\\" + path

	return path

def is_64bit():
	try:
		os.environ["PROGRAMFILES(X86)"]
		return True
	except:
		return False

def browseBSPWebsites():
	global g_browserName
	findBrowserInstalledPaths()
	if (g_browserName != "") and (g_browserInstalledPaths != ""):
		openURLs(g_browserName, g_browserInstalledPaths)
	else:
		if g_options.language.lower() == 't':
			ctypes.windll.user32.MessageBoxW(0, "請至下面網站下載新唐BSP。\n" + openURLs("", ""), "下載新唐BSP", 0)
		elif g_options.language.lower() == 'c':
			ctypes.windll.user32.MessageBoxW(0, "请至下面网站下载新唐BSP。\n" + openURLs("", ""), "下载新唐BSP", 0)
		else:
			ctypes.windll.user32.MessageBoxW(0, "Please go to the following website to download Nuvoton BSP.\n" + openURLs("", ""), "Download Nuvoton BSP", 0)

def findBrowserInstalledPaths():
	global g_browserName
	global g_browserInstalledPaths
	browserInstalledPaths = \
	"C:\Program Files (x86)\Google\Chrome\Application\chrome.exe",\
	"C:\Program Files\Google\Chrome\Application\chrome.exe",\
	"%AppData%\Local\Google\Chrome\Application\chrome.exe",\
	"C:\Program Files (x86)\Google\Application\chrome.exe",\
	"C:\Program Files\Google\Application\chrome.exe",\
	"C:\Program Files (x86)\Mozilla Firefox\\firefox.exe",\
	"C:\Program Files\Mozilla Firefox\\firefox.exe",\

	for path in browserInstalledPaths:
		if os.path.isfile(path):
			g_browserInstalledPaths = path
			if path.find("chrome.exe") != -1:
				g_browserName = "chrome"
			else:
				g_browserName = "firefox"
			break

def openURLs(browserName, browserPath):
	global g_options
	returnURL = ""
	numicroLowerCaseBSP = ["NUC1262BSP"]
	numicroM23FamilyBSP = ["M2351BSP", "M2354BSP", "M251BSP", "M261BSP", "NUC1262BSP"]
	numicroM4FamilyBSP  = ["M451BSP",  "M4521BSP", "M471BSP", "M480BSP", "M472_442BSP", "NUC505BSP"]
	urlToOpen = \
	"https://github.com/OpenNuvoton/",\
	"https://gitee.com/OpenNuvoton/",\
	"https://gitlab.com/OpenNuvoton/",\

	if (browserName != "") and (browserPath != ""):
		webbrowser.register(browserName,
			None,
			webbrowser.BackgroundBrowser(browserPath))

	for url in urlToOpen:
		if "gitlab" in url:
			file = g_archivePath + g_options.repository + "-" + g_options.commitId + ".zip"
			if g_options.repository.upper() in numicroM23FamilyBSP:
				url += "NuMicro-M23-Family/"
			elif g_options.repository.upper() in numicroM4FamilyBSP:
				url += "NuMicro-M4-Family/"
			else:
				url += "NuMicro-M0-Family/"
		if "gitee" in url and g_options.repository.upper() in numicroLowerCaseBSP:
			url += g_options.repository.lower() + "/tree/" + g_options.commitId
		else:
			url += g_options.repository + "/tree/" + g_options.commitId
		if (g_options.manager.lower() in url) or (g_options.manager.lower() == "browse"):
			returnURL = url
			if (browserName != "") and (browserPath != ""):
				webbrowser.get(browserName).open(url)
	return returnURL

# parse tool arguments
parser = OptionParser()
parser.add_option("-v", "--version",       action="store", type="string", dest="version",       help="specify NuCodeGen version, e.g. V0.41.0006(default).",                        default="V0.41.0006")
parser.add_option("-m", "--manager",       action="store", type="string", dest="manager",       help="specify Git manager. e.g, GitHub(default).",                                  default="GitHub")
parser.add_option("-o", "--organization",  action="store", type="string", dest="organization",  help="specify Git organization. e.g. OpenNuvoton(default).",                        default="OpenNuvoton")
parser.add_option("-r", "--repository",    action="store", type="string", dest="repository",    help="specify Git repository. e.g. Nuvoton_Tools(default).",                        default="Nuvoton_Tools")
parser.add_option("-c", "--commitId",      action="store", type="string", dest="commitId",      help="specify Git commit id. e.g. 0036977efea213d058b6640852fe947d73574332.",       default="0036977efea213d058b6640852fe947d73574332")
parser.add_option("-f", "--forceDownload", action="store", type="string", dest="forceDownload", help="specify 1 means always download BSP; 0 means download when not exists",       default="1")
parser.add_option("-w", "--whichTool",     action="store", type="string", dest="whichTool",     help="specify 0 means curl; 1 means wget",                                          default="1")
parser.add_option("-d", "--debugMode",     action="store", type="string", dest="debugMode",     help="specify 1 means debug mode",                                                  default="0")
parser.add_option("-l", "--language",      action="store", type="string", dest="language",      help="specify language: e(English), t(Traditional Chinese); c(Simplified Chinese)", default="e")
# global variables
(g_options, args) = parser.parse_args()
g_archivePath = ""
g_browserName = ""
g_browserInstalledPaths = ""
# main function
res = subprocess.check_output(['tasklist'])
if str(res).count('downloadNuvotonBSP.exe') > 2:
	if g_options.language.lower() == 't':
		ctypes.windll.user32.MessageBoxW(0, "BSP正在下載中，請稍待片刻以至前次下載完成...", "下載新唐BSP", 0)
	elif g_options.language.lower() == 'c':
		ctypes.windll.user32.MessageBoxW(0, "BSP正在下载中，请稍待片刻以至前次下载完成...", "下载新唐BSP", 0)
	else:
		ctypes.windll.user32.MessageBoxW(0, "BSP is being downloaded. Please wait it until the previous download is finished...", "Download Nuvoton BSP", 0)
else:
	if g_options.manager.lower() == "gitee" or g_options.manager.lower() == "browse":
		browseBSPWebsites()
	else:
		if (not findArchivePath()) or g_options.forceDownload == '1':
			if g_options.manager.lower() == "gitlab":
				file = g_archivePath + g_options.repository + "-" + g_options.commitId[0:6] + ".zip"
			else:
				file = g_archivePath + g_options.commitId[0:6] + ".zip"
			if os.path.isfile(file):
				print('remove the previous downloaded file of ' + str(file))
				os.remove(file)

			if (g_options.whichTool == "1"):
				wgetDownloadBSP()
			else:
				curlDownloadBSP()
		if g_options.debugMode == '1':
			unzipArchiveAndOpenBSPFolder()
		elif g_options.debugMode == '2':
			os.startfile(g_archivePath)
		else:
			try:
				unzipArchiveAndOpenBSPFolder()
			except:
				file = g_archivePath + g_options.commitId + ".zip"
				if os.path.isfile(file):
					print('remove the incorrect downloaded file of ' + str(file))
					os.remove(file)
				if g_options.language.lower() == 't':
					ctypes.windll.user32.MessageBoxW(0, "無法從" + g_options.manager + "下載新唐BSP。請確認你的網路連線或暫時關閉防火牆然後再試一次。", "下載新唐BSP", 0)
				elif g_options.language.lower() == 'c':
					ctypes.windll.user32.MessageBoxW(0, "无法从" + g_options.manager + "下载新唐BSP。请确认你的网路连线或暂时关闭防火牆然后再试一次。", "下载新唐BSP", 0)
				else:
					ctypes.windll.user32.MessageBoxW(0, "Failed to download Nuvoton BSP from " + g_options.manager + ". Please check your network connection, temporarily close firewall, and try again.", "Download Nuvoton BSP", 0)

		browseBSPWebsites()
