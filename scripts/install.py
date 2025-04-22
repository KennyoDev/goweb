import os

print("Installation working...")

#//enter here the location where you git cloned the project
#//example:
os.chdir("/home/user/Docs/goweb")
createSTATUS = os.system("gcc -o goweb main.c cJson/cJSON.c")
mvSTATUS = os.system("sudo mv goweb /usr/local/bin/")

if (createSTATUS == 0 and mvSTATUS == 0):
    print("Installation done.")
else:
    print("Some wrong!")
