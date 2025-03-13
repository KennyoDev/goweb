import os

print("Installation working...")

os.chdir("/home/kenny/Code/c_files/goweb/")
createSTATUS = os.system("gcc -o gowebBETA main.c")
mvSTATUS = os.system("sudo mv gowebBETA /usr/local/bin/")

if (createSTATUS == 0 and mvSTATUS == 0):
    print("Installation done.")
else:
    print("Some wrong!")
