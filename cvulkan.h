#pragma once

#include <GLFW/glfw3.h>

#include <stdbool.h>

bool cvk_init(GLFWwindow* window);

void cvk_cleanup(void);

void cvk_draw(void* image);