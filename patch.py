# import re to compile regexp
import re

# import os to rename files
import os

# import ConfigParser to edit platformio.ini
import ConfigParser

# import serial.tools.list_ports to get all connected ports
import serial.tools.list_ports

# get a list of all ports
ports = list(serial.tools.list_ports.comports())
port  = None

# find the one that contains the word Arduino
for p in ports:
    if "Arduino" in p[1]:
        port = p[0]
        break

# print the first one if none was found
if ports and not port:
    port = ports[0][0]

# start the configuration parser, parse the file and update it
config = ConfigParser.RawConfigParser()
config.read("platformio.ini")
config.set("env:uno", "target_upload", port)

# write changes to disk
with open("platformio.ini", "wb") as configfile:
    config.write(configfile)

# read the file again into a list of lines
with open("platformio.ini") as configfile:
    content = configfile.readlines()

# compile the regex to detect whitespace-only lines and search from the end the first line that is not whitespace
p = re.compile("^[\s \n\r]*$")
i = 0
for e in reversed(content):
    if not p.match(e):
        break
    i += 1

# write everything until that one line
with open("platformio.ini.new", "w") as output:
    output.write("".join(content[:-i]))

# rename files and remove files
if os.path.exists("platformio.ini.old"):
    os.unlink("platformio.ini.old")
os.rename("platformio.ini",     "platformio.ini.old")
os.rename("platformio.ini.new", "platformio.ini")