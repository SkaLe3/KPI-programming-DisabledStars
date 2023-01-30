#ifndef MAINTANCE_H
#define MAINTANCE_H



#include "objectClass.h"
#include <GLFW/glfw3.h>

#include <irrklang/irrKlang.h>

extern irrklang::ISoundEngine* SoundEngine;

void playMusic();

void stopMusic();
void checkMusic();

void  ScreenToOpenGL(GLFWwindow* window, double x, double y, float* ox, float* oy);
bool checkClick(GLFWwindow* window, Object* obj);


#endif