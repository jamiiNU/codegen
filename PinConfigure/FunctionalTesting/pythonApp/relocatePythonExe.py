import os
import shutil

PythonExeName = 'csvGenerator'
if os.path.isfile("../" + PythonExeName + ".exe"):
	os.remove("../" + PythonExeName + ".exe")

shutil.move("dist/" + PythonExeName + ".exe", "../" + PythonExeName + ".exe")
print('the ' + PythonExeName + '.exe has been relocated to the right place.')