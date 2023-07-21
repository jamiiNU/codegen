import os
import shutil

def removeRedundantFiles():
	commonPath = ''
	# remove files
	filesToRemove = \
	commonPath + 'Nu_config.cfg',\
	commonPath + 'NuToolSetup.txt',\
	commonPath + 'NuCAD.csv',\
	commonPath + 'funcunit.js',\
	commonPath + 'jquery-1.11.1.js',\
	commonPath + 'NUC_AX58200_Content.js',\
	commonPath + 'NuTool_PinConfigure_Test.htm',\
	commonPath + 'NuTool_PinConfigure_Test.js',\
	commonPath + 'qunit-1.15.0.css',\
	commonPath + 'qunit-1.15.0.js',\
	commonPath + 'Nuvoton_library.EDF',\

	notFoundList = []
	for file in filesToRemove:
		if os.path.isfile(file):
			print('remove ' + str(file))
			os.remove(file)
		else:
			notFoundList.append(str(file) + ' not found')

	# remove folders
	foldersToRemove = \
	'../.git',\
	'FunctionalTesting',\

	for folder in foldersToRemove:
		if os.path.isdir(folder):
			print('removed the folder of ' + str(folder))
			shutil.rmtree(folder, ignore_errors=True)
		else:
			notFoundList.append('the folder ' + str(folder) + ' not found')

	# print those not found
	for notFound in notFoundList:
		print(notFound)

def checkRedundantFiles():
	checkResult = True
	commonPath = ''
	# remove files
	filesToRemove = \
	commonPath + 'Nu_config.cfg',\
	commonPath + 'NuToolSetup.txt',\
	commonPath + 'NuCAD.csv',\
	commonPath + 'funcunit.js',\
	commonPath + 'jquery-1.11.1.js',\
	commonPath + 'NUC_AX58200_Content.js',\
	commonPath + 'NuTool_PinConfigure_Test.htm',\
	commonPath + 'NuTool_PinConfigure_Test.js',\
	commonPath + 'qunit-1.15.0.css',\
	commonPath + 'qunit-1.15.0.js',\
	commonPath + 'Nuvoton_library.EDF',\

	for file in filesToRemove:
		if os.path.isfile(file):
			print(str(file) + ' is still there. Please remove it manually.')
			checkResult = False

	# remove folders
	foldersToRemove = \
	'../.git',\
	'FunctionalTesting',\

	for folder in foldersToRemove:
		if os.path.isdir(folder):
			print(str(folder) + ' is still there. Please remove it manually.')
			checkResult = False

	if not checkResult:
		os.system("pause")

answer = input("Do you want to remove redundant files for the release purpose?\n\
(If you are developing the tool, please do not enter yes. Many files will be gone.)\n\
Enter yes or no:")
if answer == "yes":
	removeRedundantFiles()
	checkRedundantFiles()
elif answer == "no":
	print ('OK. Keep everything')
else:
	print("Please enter yes or no.")
