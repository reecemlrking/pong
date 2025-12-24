#ifndef GLAD
#define GLAD
#include <glad/glad.h>
#endif

#ifndef GLFW
#define GLFW
#include <GLFW/glfw3.h>
#endif

#ifndef STDIO
#define STDIO
#include <stdio.h>
#endif

#ifndef STDBOOL
#define STDBOOL
#include <stdbool.h>
#endif

#ifndef SCR_WIDTH
#define SCR_WIDTH 800
#endif

#ifndef SCR_HEIGHT
#define SCR_HEIGHT 600
#endif

void framebuffer_size_callback(GLFWwindow*, int, int);
void processInput(GLFWwindow*);
