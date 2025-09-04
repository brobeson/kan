# Building Kan

Building Kan requires [CMake](https://cmake.org), a C++ compiler, and a handful of library dependencies.
After [installing the dependencies](#install-dependencies), the build process is essentially two steps:

1. Run CMake to [configure the build system](#configure-the-build-system).
1. Run the build system to [build the software](#build-the-software).

## Install Dependencies

Install development version of these libraries:

- [OpenGL](https://www.opengl.org/)
- [GLEW](https://github.com/nigels-com/glew/)
- [FreeGLUT](https://freeglut.sourceforge.net/) (only required to build the demo applications)
- [Catch2](https://github.com/catchorg/Catch2) (only required to build the tests)

<details>
  <summary>Install on Ubuntu</summary>

```bash
sudo apt install libglew-dev libglu1-mesa-dev mesa-common-dev
sudo apt install freeglut3-dev
sudo apt install catch2
```

</details>

## Configure the Build System

At the most basic level, you just need to run CMake and tell it where it where your source and build directories are:

```bash
cmake -S . -B build
```

Kan is designed to play nicely with CMake.
Whatever you can control on the command line or through environment variables should work fine.
For example, if you have a custom build of FreeGLUT installed in _/opt/freeglut_, you could run

```bash
cmake -S . -B build -D CMAKE_PREFIX_PATH:FILEPATH=/opt/freeglut
```

Kan provides some configure-time options; these are all prefixed with `KAN_`.
For example, to disable building Kan's tests:

```bash
cmake -S . -B build -D KAN_BUILD_TESTS:BOOL=off
```

To view the available options, use the [CMake GUI](https://cmake.org/cmake/help/latest/manual/cmake-gui.1.html), [ccmake](https://cmake.org/cmake/help/latest/manual/ccmake.1.html), or configure a build system then rerun CMake with `-L`:

```bash
$ cmake -B build -L | grep ^KAN_
KAN_BUILD_DEMOS:BOOL=ON
KAN_BUILD_DOCS:BOOL=ON
KAN_BUILD_TESTS:BOOL=ON
```

## Build the Software

After you configure the build system, run your build tool.

```bash
cmake --build build
```
