import os
import shutil
import mmap
import ctypes

def removeRedundantFiles():
	global g_filesToRemove
	global g_filesToRemove
	notFoundList = []

	for file in g_filesToRemove:
		if os.path.isfile(file):
			print('remove ' + str(file))
			os.remove(file)
		else:
			notFoundList.append(str(file) + ' not found')

	for folder in g_foldersToRemove:
		if os.path.isdir(folder):
			print('removed the folder of ' + str(folder))
			shutil.rmtree(folder, ignore_errors=True)
		else:
			notFoundList.append('the folder ' + str(folder) + ' not found')

	# print those not found
	for notFound in notFoundList:
		print(notFound)

def checkRedundantFiles():
	global g_filesToRemove
	global g_filesToRemove
	checkResult = True
	commonPath = ''

	for file in g_filesToRemove:
		if os.path.isfile(file):
			print(str(file) + ' is still there. Please remove it manually.')
			checkResult = False

	for folder in g_foldersToRemove:
		if os.path.isdir(folder):
			print(str(folder) + ' is still there. Please remove it manually.')
			checkResult = False

	if not checkResult:
		os.system("pause")

def checkGoogleClosureCompiler():
	commonPath = ''
	# check files
	filesToCheck = \
	commonPath + 'PinConfigure/NUC_Pin_Configuration.js',\
	commonPath + 'ClockConfigure/NUC_Clock_Configuration.js',\
	commonPath + 'PeripheralConfigure/NUC_Peripheral_Configuration.js',\
	commonPath + 'PeripheralConfigure/NUC_Peripheral_DrawCanvas.js',\

	for file in filesToCheck:
		with open(file, 'rb', 0) as file1, \
			mmap.mmap(file1.fileno(), 0, access=mmap.ACCESS_READ) as s:
			if s.find(b'g_bReadyForRelease') != -1 or s.find(b'Pin_Waveform') != -1:
				ctypes.windll.user32.MessageBoxW(0, file + u" was not complied, so please do not release.", u"Error", 0)

# main function
# remove files
g_filesToRemove = \
'../.gitignore',\
'jquery-1.11.1.js',\
'PeripheralConfigure/NuTool_PeripheralConfigure_Test.htm',\
'PeripheralConfigure/NuTool_PeripheralConfigure_Test.js',\
'PeripheralConfigure/jquery-1.11.1.js',\
'PeripheralConfigure/funcunit.js',\
'PeripheralConfigure/qunit-1.15.0.css',\
'PeripheralConfigure/qunit-1.15.0.js',\
'PeripheralConfigure/NuToolSetup.txt',\
'Nu_config.cfg',\
'NuToolSetup.txt',\
'.wget-hsts',\
'PinConfigure/NuCAD_OrCAD.exe',\
'PinConfigure/NuCAD_Protel.exe',\
'../UserManual/IP config template guideline of NuCodeGen Tool.pptx',\
'../UserManual/NuCodeGenTool的基礎知識.pdf',\
'../UserManual/projfile_cppcmd_rename.ppt',\
# remove folders
g_foldersToRemove = \
'../.git',\
'../NuTool - TagCreator',\
'PeripheralConfigure/FunctionalTesting',\
'PeripheralConfigure/DEMO',\

answer = input("Do you want to remove redundant files for the public release purpose?\n\
(If you are developing the tool, please do not enter yes. Many files will be gone.)\n\
Enter yes or no:")
if answer == "yes":
	removeRedundantFiles()
	checkRedundantFiles()
	checkGoogleClosureCompiler()
elif answer == "no":
	print ('OK. Keep everything')
else:
	print("Please enter yes or no.")
