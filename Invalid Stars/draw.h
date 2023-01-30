#ifndef DRAW_H
#define DRAW_H

#include "objectClass.h"
#include "shaderClass.h"
#include <stb/stb_image.h>

void setBackground(Shader* shaderProgram, Object*, std::string);
void setTitle(Shader* shaderProgram, Object* title, std::string);
void setButton(Shader* shaderProgram, Object* button, std::string tex);

void setCanvas(Shader* shaderProgram, Object* obj, GLfloat r = 0, GLfloat g = 0, GLfloat b = 0, GLfloat fade = 0);


#endif