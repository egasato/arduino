## Arduino Starter Kit Projects
Here you can find all the code needed to complete the 15 awesome Arduino Starter
Kit projects. The master branch itself doesn't contain any code but the
necessary files used to start a new one from scratch. Each project has an
associated branch, and some of them even have more than one revision where the
behaviour differs from the proposed by the Arduino team.

## Dependencies
To build or run each project yur system must satisfy this dependencies:
* Python 2.7 (pyenv is compatible also)
* PlatformIO
* IDE compatible with PlatoformIO

## How to build
This repo is compatible with CLion and the Arduino Uno board but it is compatible
with other IDEs and boards. If you want to create the project files for other
IDEs/boards run the following command.
```bash
platformio init --ide <YOUR IDE> --board <YOUR BOARD>
```
When you have your Arduino board connected run one of the patch scripts to
automatically detect the port and update the platformio.ini file. To build and
run the projects either use the GUI of your favorite IDE or the PlatformIO
commands.
```bash
platformio run --target upload
```
More information about supported [IDEs][platformio-ides],
[boards][platformio-boards] and [commands][platformio-commands] available in the
official PlatformIO [website][platformio].

## The MIT License
Copyright &copy; 2017 Esaú García Sánchez-Torija & contributors.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

## Trademark notice
ARDUINO®, ![Arduino's logo][logo] and other Arduino brands and logos published
in the website are Trademarks of Arduino AG. To the extent a brand, name or
logo does not appear on the website does not constitute a waiver of any and all
intellectual property rights that Arduino AG has established in any of its
product or service names or logos. All Arduino AG Trademarks cannot be used
without owner’s formal permission. For information and more details about the
proper use of our trademarks, please write to [trademark@arduino.cc][mail1] or
[trademark@arduino.org][mail2].

[platformio-ides]: http://docs.platformio.org/en/latest/ide.html
[platformio-boards]: http://docs.platformio.org/en/latest/platforms/embedded_boards.html#arduino
[platformio-commands]: http://docs.platformio.org/en/latest/quickstart.html#process-project
[platformio]: http://platformio.org
[logo]: https://www.arduino.cc/en/uploads/Trademark/ARDUINO_logo.jpg
[mail1]: mailto:trademark@arduino.cc?subject=Information+and+details+about+Arduino+Trademark
[mail2]: mailto:trademark@arduino.org?subject=Information+and+details+about+Arduino+Trademark