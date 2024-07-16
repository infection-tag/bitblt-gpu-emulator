# Simple GPU Emulator

This GPU is based on a simple BitBlt emulator.

## Repository Manifesto

```
gpu_emulator
├── include
│   ├── gpu.h
│   └── types.h
├── src
│   ├── main.c
│   ├── framebuffer.c
│   ├── graphics.c
│   └── memory.c
└── Makefile
```

### Here's what each file does:

* gpu.h: Main header file for the GPU emulator, providing public API and global definitions.
* types.h: Defines custom data types used throughout the project 
* main.c: Entry point of the program, handles initialization, rendering loop, and input/output.
* framebuffer.c: Manages the framebuffer, including creation, clearing, and pixel writes.
* graphics.c: Implements core graphics functions like rasterization, shading, and transformations.
* memory.c: Handles memory allocation and management for the emulator.

## Run

The project has barely taken off. However, once its done, all you need to do is:

```sh
git clone https://github.com/infection-tag/bitblt-gpu-emulator/
cd bitblt-gpu-emulator
make
```
