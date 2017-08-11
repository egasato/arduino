# -*- coding: utf-8 -*-
# importamos "re" para compilar expresiones regulares
# import "re" to compile regular expressions
import re

# importamos "os" para renombrar archivos y manejar rutas
# import "os" to rename files and handle paths
import os

# importamos "ConfigParser" para editar archivos .ini
# import "ConfigParser" to edit .ini files
import ConfigParser

# importamos "serial.tools.list_ports" para obtener todos los puertos conectados
# import "serial.tools.list_ports" to get all connected ports
import serial.tools.list_ports

# importamos "sys" para poder terminar el programa
# import "sys" to terminate the program
import sys

# obtenemos una lista con todos los puertos
# get a list of all ports
ports = list(serial.tools.list_ports.comports())
port = None

# buscamos el que contiene la palabra Arduino (si existe)
# find the one that contains the word Arduino (if any)
for p in ports:
    if "Arduino" in p[1]:
        port = p[0]
        break

# si no encontramos ninguno usamos el primero, sino terminamos el programa
# if we cannot find any use the first one, otherwise we terminate the program
if not port:
    if ports:
        port = ports[0][0]
    else:
        print "No hay ningún puerto conectado"
        print "No ports connected"
        sys.exit()

# creamos el modificador de configuración, leemos el archivo y lo actualizamos
# start the configuration parser, parse the file and update it
config = ConfigParser.RawConfigParser()
config.read("platformio.ini")
config.set("env:uno", "upload_port", port)

# escribimos los cambios en el disco
# write changes to disk
with open("platformio.ini", "wb") as configfile:
    config.write(configfile)

# leemos el archivo de nuevo y lo convertimos en una lista de lineas
# read the file again into a list of lines
with open("platformio.ini") as configfile:
    content = configfile.readlines()

# compilamos la expresión regular para detectar lineas que solo contengan
# carácteres no visibles y buscamos empezando por el final la primera linea que
# que no coincide con esa expresión regular
# compile the regex to detect whitespace-only lines and search from the end the
# first line that does not match
p = re.compile("^[\s \n\r]*$")
i = 0
for e in reversed(content):
    if not p.match(e):
        break
    i += 1

# escribimos el archivo sin modificar hasta la línea detectada anteriormente
# write everything but the everything after the line detected above
with open("platformio.ini.new", "w") as output:
    output.write("".join(content[:-i]))

# eliminamos el archivo viejo, renombramos el actual a .old y el nuevo como el actual
# remove old files, rename the current to .old and the new as the current
if os.path.exists("platformio.ini.old"):
    os.unlink("platformio.ini.old")
os.rename("platformio.ini", "platformio.ini.old")
os.rename("platformio.ini.new", "platformio.ini")