![](https://github.com/senselogic/CHOP/blob/master/LOGO/chop.png)

# Chop

Cross-platform file splitter and joiner.

![](https://github.com/senselogic/CHOP/blob/master/SCREENSHOT/screenshot_linux.png)
![](https://github.com/senselogic/CHOP/blob/master/SCREENSHOT/screenshot_windows.png)

## Installation

### Linux

#### Manually

```bash
sudo apt install git build-essential g++ libgtkmm-3.0-dev
git clone https://github.com/senselogic/CHOP.git
cd CHOP/CODE
cd CODE
g++ -std=c++11 MODEL/file_table.cpp VIEW/application_view.cpp VIEW/button_view.cpp VIEW/file_view.cpp chop.cpp $(pkg-config gtkmm-3.0 --cflags --libs | sed 's/ -I/ -isystem /g') -o chop
```

#### Using CMake

```bash
sudo apt install git cmake build-essential g++ libgtkmm-3.0-dev
git clone https://github.com/senselogic/CHOP.git
cd CHOP/CODE/CMAKE
cmake ..
make
```

### Windows

Install [MSYS2](https://www.msys2.org/).

Open a `MSYS2 MinGW 64-bit` shell from Start menu and build the executable with the following commands :

```bash
pacman -S git base-devel mingw-w64-x86_64-toolchain mingw-w64-x86_64-gcc mingw-w64-x86_64-gtkmm3
git clone https://github.com/senselogic/CHOP.git
cd CHOP/CODE
g++ -std=c++11 MODEL/file_table.cpp VIEW/application_view.cpp VIEW/button_view.cpp VIEW/file_view.cpp chop.cpp $(pkg-config gtkmm-3.0 --cflags --libs | sed 's/ -I/ -isystem /g') -o chop.exe
```

## Version

0.1

## Author

Eric Pelzer (ecstatic.coder@gmail.com).

## License

This project is licensed under the GNU General Public License version 3.

See the [LICENSE.md](LICENSE.md) file for details.
