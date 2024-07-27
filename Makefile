framebuffer: framebuffer.c framebuffer.h
  gcc -c framebuffer.c

memory: memory.c memory.h
  gcc -c memory.c

gpu: gpu.c gpu.h
  gcc -c gpu.c
  gcc -c main.c # assuming a specific GPU-based recompile

main: framebuffer.o memory.o gpu.o main.o
  gcc framebuffer.o memory.o gpu.o main.o -o main
