#ifndef OBJECT_CLASS_H
#define OBJECT_CLASS_H

#include "glad/glad.h"
#include "EBO.h"
#include "VAO.h"
#include "VBO.h"
#include "Texture.h"
#include "shaderClass.h"
#include <iostream>
#include <stdarg.h>
#include <vector>


class Object
{



	// Vertices coordinates
	std::vector<GLfloat> vertices;
	// Indices for vertices order
	std::vector<GLuint> indices;

	VAO curVAO;
	VBO curVBO;
	EBO curEBO;

	const std::string texPath = "Textures/";
	Texture curTex;


public:

	double Xl;
	double Xr;
	double Yd;
	double Yu;

	Object();
	Object(double X1, double Y1, double X2, double Y2);
	~Object();
	void use();
	void Link(int st, Shader* shaderProgram,  const std::string* textureName = (std::string*)"", int rgb = 0x1907);
	void addVertices(int vert, ...);
	void addIndices(int ind, ...);

};


#endif