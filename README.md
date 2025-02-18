# Virtual Rover

Simple app made in w C++ and gnuplot.

![Virtual Rover](img/Rover.png) <!-- Change this to the correct image filename -->

## Contents
- [Info](#Info)
- [Tech](#Tech)
- [Building](#ustawianie)
- [Sources](#sources)

## Info

The goal of this project is to familiarize users with object-oriented programming in C++ and the graphical capabilities of gnuplot.
This application provides a simple interface for controlling a virtual rover that navigates across a generated terrain, and has build in collision detection.

## Tech

- C++11
- gnuplot version 5.4

## Building

Build by making a build directory (i.e. `build/`), run `cmake` in that dir, and then use `make` to build the desired target.

Requirements: cmake, gnuplot, doxygen + dot (in graphviz library)

Example:

``` bash
> mkdir build && cd build
> cmake .. #### options: -DCMAKE_BUILD_TYPE=[Debug | Coverage | Release], Debug is default
> make     #### compilation
> ./main   #### main() from app
```
The main loop of the program is in the `app` folder.

## Sources

The project was developed as part of coursework under Dr. Bogdan Kreczmer, utilizing a proprietary file that facilitates communication between the application and the gnuplot software (file: /prj/src/lacze_do_gnuplota.cpp).
