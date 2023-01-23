## :black_large_square: retrocube :white_large_square: 

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)  
---
Spinning cube animation via very basic ray tracing on the terminal. Rendered in ASCII.
```
                    +==
                ++======
             +============
          ==================
      ========================
   +===========================..
   ||+=====================.......
    ||+=================..........
    +||||===========...............
     +||||||==+.....................
      +||||||........................
       +||||||.......................
       +||||||~.......................
        +||||||....................~.%
           |||||...............~.
            ||||~..........~..
               ||.........
                ||....~

```

### 1. This implementation

In human language, the graphics are rendered by the following algorithm:
```
rows <- terminal's height
columns <- terminal's width
// a face (surface) is a plane segment (x, y, z) restricted within 4 cube vertices
initialise a cube (6 faces)
for (r in rows):
    for (c in columns):
        z_rendered <- +inf
        for (surface in cube's faces):
            find z(c, r)
            if (z < z_rendered) and ((c, r, z) in surface):
                z_rendered <- z
                draw(c, r)
```

### 2. Requirements

1. **ncurses**  
On Debian-based systems it's installed with:
```
apt-get install libncurses-dev
```
On Arch-based systems it's installed with:
```
pacman -S ncurses
```
2. **gcc**

### 3. Development and installation

#### 3.1 Development

The naming convention follows the one of [stb](https://github.com/nothings/stb).  
Source files are found in `src` and headers in `include`.

You can compile the project with:
```
make
```
You can run the binary with (a list of command line arguments is provided in the next section):
```
./cube
```
You can delete the binary and object files with:
```
make clean
```

#### 3.2 General installation

The `Makefile` includes an installation command. The binary will be installed at `/usr/bin/cube` as:
```
sudo make install
```
Similarly, you can uninstall it from `/usr/bin` as:
```
sudo make uninstall
```

#### 3.3 Installation as Nix package

On Nix (with flakes enabled) you don't need to install it and you can directly run it with:
```
nix run github:leonmavr/retrocube
```
Credits for the Nix packaging to [Peter Marreck (pmarreck)](https://github.com/pmarreck).

### 4. Usage

By default the program runs forever so you can stop it with `Ctr+C`. Below are the command line arguments it accepts.


| Short specifier | Long specifier            | Argument type | Default | Description                                                                              |
|:--------------- |:--------------------------|:--------------|:--------|:-----------------------------------------------------------------------------------------|
| -sx             | --speedx                  | float         | 0.7     |Rotational speed around the x axis (-1 to 1)                                              |   
| -sy             | --speedy                  | float         | 0.4     |Rotational speed around the y axis (-1 to 1)                                              |   
| -sz             | --speedz                  | float         | 0.6     |Rotational speed around the z axis (-1 to 1)                                              |   
| -f              | --fps                     | int           | 40      |Maximum fps at which the graphics can be rendered (lower it if high CPU usage)            |   
| -r              | --random                  | no argument   | Off     |If disabled, rotate at constant speed around each axis. Else randomly and sinusoidally.   |   
| -cx             | --cx                      | int           | 0       |x-coordinate of the cube's center in pixels                                               |   
| -cy             | --cy                      | int           | 0       |y-coordinate of the cube's center in pixels                                               |   
| -cz             | --cz                      | int           | 0       |z-coordinate of the cube's center in pixels                                               |   
| -s              | --size                    | int           | 24      |Length of cube's sides in pixels                                                          |   
| -mi             | --maximum-iterations      | int           | Inf/ty  |How many frames to run the program for                                                    |   

This is what it looks like on the command line:

random speed | constant speed
:-------------------------:|:-------------------------:
![](https://github.com/leonmavr/retrocube/blob/master/assets/demo_constant.gif?raw=true)  |  ![](https://raw.githubusercontent.com/leonmavr/retrocube/master/assets/demo_random.gif)


### 5. Contributing

If you'd like to contribute, please follow the codiing guidelines (section 3.1) and make sure that it builds and runs.
I'll be happy to merge new changes.  

List of contributors:
* [pmarreck](https://github.com/pmarreck) - Nix packaging
