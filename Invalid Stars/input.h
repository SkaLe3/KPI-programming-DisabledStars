#ifndef INPUT_H
#define INPUT_H


#include <GLFW/glfw3.h>
#include "common.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouse_callback(GLFWwindow* window, int button, int action, int mods);
#endif