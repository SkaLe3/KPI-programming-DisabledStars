#include "input.h"
// Input processing
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);

    if ((key == GLFW_KEY_SPACE ) && action == GLFW_PRESS) {
        click = true;
        std::cout << "click" << std::endl;
    }
    if ((key == GLFW_KEY_SPACE ) && action == GLFW_RELEASE)
        click = false;

}

void mouse_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
        click = true;
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
        click = false;
}
