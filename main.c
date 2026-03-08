#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <GLFW/glfw3.h>

#include "cvulkan.h"

int running = 1;

void handle_input(GLFWwindow *window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_Q) {
		running = 0;
	}
}

int main() {
	int width = 1280;
	int height = 720;
	assert(glfwInit());

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

	GLFWwindow* window = glfwCreateWindow(width, height, "GLFW+Vulkan for software rendering", NULL, NULL);

	void* image = malloc(4 * width * height);
	assert(image);

	assert(cvk_init(window));

	glfwSetKeyCallback(window, handle_input);

	while (!glfwWindowShouldClose(window) && running) {
		glfwPollEvents();

		for (int i = 0; i < width*height; i++) {
			// ARGB
			((uint32_t*)image)[i] = 0xFF00FF00;
		}

		cvk_draw(window, image, width, height);
	}

	cvk_cleanup();

	glfwTerminate();

	return 0;
}
