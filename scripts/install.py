import os

print("Installation working...")

chdirSTATUS = os.chdir("/home/kenny/Code/c_files/goweb/")
createSTATUS = os.system("gcc -o gowebBETA main.c")
mvSTATUS = os.system("sudo mv gowebBETA /usr/local/bin/")

if chdirSTATUS != -1 and createSTATUS != -1 and mvSTATUS != -1:
    print("Installation done.")
else:
    print("Some wrong!")
