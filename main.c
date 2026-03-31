#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>

#include <GLFW/glfw3.h>

#include "cvulkan.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))

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

	double target_fps = 60.0;
	double delta_sec = 0.0;

	while (!glfwWindowShouldClose(window) && running) {
		printf("Delta: %f\n", delta_sec);
		double last = glfwGetTime();

		glfwPollEvents();

		for (int i = 0; i < width*height; i++) {
			// ARGB
			((uint32_t*)image)[i] = 0xFF00FF00;
		}

		cvk_draw(window, image, width, height);

		double duration = glfwGetTime() - last;
		double sleep_sec = MAX(0.0, 1.0 / target_fps - duration);
		struct timespec req = {0};
		time_t sec = sleep_sec;
		req.tv_sec = sec;
		req.tv_nsec = (sleep_sec - sec) * 1000000000L;
		nanosleep(&req, &req);

		delta_sec = glfwGetTime() - last;
	}

	cvk_cleanup();

	glfwTerminate();

	return 0;
}
