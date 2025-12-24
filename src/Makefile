CC = gcc
CFLAGS = -Wall -std=c99
INCLUDE = -lglfw -lGLU # -lGL -ldl -lX11 -lXrandr -lrt -lXxf86vm

pong.out: pong.c pong.h ../glad/glad.c 
	$(CC) $(CFLAGS) -o $@ $^ $(INCLUDE)
