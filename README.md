# Kan

[![Build](https://github.com/brobeson/kan/actions/workflows/build.yaml/badge.svg)](https://github.com/brobeson/kan/actions/workflows/build.yaml)

## Building

### Install Dependencies

```bash
sudo apt install freeglut3-dev libglew-dev
```

### Configure and Build

```bash
cmake -B build/ -S .
cmake --build build/
```

### Run the Demo

```bash
build/demo/demo
```
