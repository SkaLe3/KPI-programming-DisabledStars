#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "shaderClass.h"
#include <GLFW/glfw3.h>

void result(GLFWwindow* window, Shader* shaderProgram);
void newGame(GLFWwindow* window, Shader* shaderProgram);

bool level(GLFWwindow* window, Shader* shaderProgram, int lvl);

#endif