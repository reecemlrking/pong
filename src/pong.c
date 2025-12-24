#include "pong.h"

// Main pong entrypoint
int main() {
	// init glfw
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__ 
	glfwWindwowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	// create glfw window 
	GLFWwindow * window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "PONG", NULL, NULL);

	if (window == NULL) {
		printf("Failed to create GLFW window\n");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// load OpenGL function pointers
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		printf("Failed to initialize GLAD\n");
		return -1;
	}

	// main render loop
	while (!glfwWindowShouldClose(window)) {
		// process user input
		processInput(window);
		
		// swap buffers and poll IO events
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
	glfwTerminate();
	return 0;
}


// Callback called on window size change
void framebuffer_size_callback(GLFWwindow * window, int width, int height) {
	glViewport(0, 0, width, height);
}

// Process User Input
void processInput(GLFWwindow * window) {
	
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}
