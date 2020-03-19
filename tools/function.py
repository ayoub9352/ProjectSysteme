import os

include_gtk = False
add_exucute = True
outPut  = open("tools/functions.h", "w+")
head = "#ifndef FUNCTIONS\n#define FUNCTIONS\n\n"
include = "\t#include <gtk/gtk.h>\n\t#include <cairo.h>\n\n"
footer = "\n\n#endif"

folderList = [
    "functions"
]

if(include_gtk) :
    folderList = folderList + ["graphic_gtk"]


files = []
for folder in folderList :
    getedFiles = os.listdir(folder)
    for fl in getedFiles :
        newFile = folder + "/" + fl
        files.append(newFile)

outPut.write(head)
if(include_gtk) :
    outPut.write(include)

write = True
for fl in files :
    thefile = open(fl, "r")
    outPut.write("\t// +----> " + fl + "\n\n")
    for line in thefile :
        endOfLine = line[len(line) - 2]
        startOfLine = line[0]
        if len(line) > 2 :
            comment = "" + line[0] + line[1]
            if(comment == "/*") :
                write = False
            if(comment == "*/") :
                write = True
            if (write == True) :
                if(startOfLine != " " and endOfLine == "{") :
                    outPut.write("\t" + line.replace("{", ";", 1))
    outPut.write("\n\n")
    thefile.close()
outPut.write(footer)

outPut.close()

#compiler
compiler = open("tools/compiler.cmd", "w+")
commade = "gcc -g main.c "
for fl in files :
    commade = commade + fl + " "
commade = commade + "-o systemeProject "
if include_gtk :
    commade = commade + "%gtk_includes% %gtk_libs% "
if add_exucute :
    commade = commade + "\n systemeProject.exe "
compiler.write(commade)
compiler.close()
