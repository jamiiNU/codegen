import os
import webbrowser
import ctypes

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
	urlToOpen = \
	"https://github.com/OpenNuvoton",\
	"https://gitee.com/OpenNuvoton",\
	"https://gitlab.com/OpenNuvoton",\

	webbrowser.register(browserName,
		None,
		webbrowser.BackgroundBrowser(browserPath))

	for url in urlToOpen:
		webbrowser.get(browserName).open(url)

# global variables
g_browserName = ""
g_browserInstalledPaths = ""
# main function
findBrowserInstalledPaths()
if (g_browserName != "") and (g_browserInstalledPaths != ""):
	openURLs(g_browserName, g_browserInstalledPaths)
else:
	ctypes.windll.user32.MessageBoxW(0, "Please go to the following websites to download BSP.\n1. github.com/OpenNuvoton \n2. gitee.com/OpenNuvoton \n3. gitlab.com/OpenNuvoton", "Download BSP", 0)
