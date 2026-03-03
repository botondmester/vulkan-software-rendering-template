#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <GLFW/glfw3.h>

#include "cvulkan.h"

int main() {
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	glfwInit();

	GLFWwindow* window = glfwCreateWindow(800, 600, "ui test", NULL, NULL);

	void* image = malloc(4 * 800 * 600);
	for (int i = 0; i < 800*600; i++) {
		((uint32_t*)image)[i] = 0xFF00FF00;
	}

	assert(cvk_init(window));

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		cvk_draw(image);
	}

	cvk_cleanup();

	glfwTerminate();

	return 0;
}
