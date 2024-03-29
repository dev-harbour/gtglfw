# Text environment based on GLFW

## List of GLFW releases

   [Releases](https://github.com/glfw/glfw/releases)

## Installing on Windows

This project uses a Makefile to build the library. To execute the Makefile on Windows, you must install a version of GNU make,
which is available in toolkits such as MSYS2, Cygwin, Git Bash, MinGW, or through the Windows Subsystem for Linux (WSL).

- MSYS2

Before installing the packages, make sure you're running the MinGW 64-bit shell.

   ```
   pacman -S mingw-w64-x86_64-gcc
   pacman -S mingw-w64-x86_64-glfw
   pacman -S mingw-w64-x86_64-glew
   pacman -S make
   ```

- To build the static library, execute:

   ```
   make
   ```

- To build and run samples and test code, navigate to the tests directory and execute:

   ```
   cd tests
   make
   ```
   or single build:
   ```
   gcc main.c -o main -I ../include -L ../lib -lgtglfw -lopengl32 -lglfw3 -lm
   ```

## Installing on Linux

- Debian

   ```
   sudo apt-get update
   sudo apt-get install libgl-dev
   sudo apt-get install libglfw3-dev
   ```
- To build the static library, execute:

   ```
   make
   ```

- To build and run samples and test code, navigate to the tests directory and execute:

   ```
   cd tests
   make
   ```
   or single build:
   ```
   gcc main.c -o main -I ../include -L ../lib -lgtglfw -lGL -lglfw -lm
   ```
---
