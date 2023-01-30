#include "objectClass.h"

void Object::Link(int st, Shader *shaderProgram, const std::string *textureName, int rgb)
{

	GLsizeiptr stride = (GLsizeiptr)st;
	// Generates Vertex Array Object and binds it
	curVAO.Bind();

	// Generates Vertex Buffer Object and links it to vertices
	curVBO.add(vertices.data(), vertices.size()*sizeof(GLfloat));
	// Generates Element Buffer Object and links it to indices
	curEBO.add(indices.data(), indices.size()*sizeof(GLuint));

	// Links VBO attributes such as coordinates and colors to VAO
	curVAO.LinkAttrib(curVBO, 0, 3, GL_FLOAT, stride * sizeof(float), (void*)0);
	curVAO.LinkAttrib(curVBO, 1, 3, GL_FLOAT, stride * sizeof(float), (void*)(3 * sizeof(float)));
	if (stride == (GLsizeiptr)8)
	curVAO.LinkAttrib(curVBO, 2, 2, GL_FLOAT, stride * sizeof(float), (void*)(6 * sizeof(float)));
	// Unbind all to prevent accidentally modifying them
	curVAO.Unbind();
	curVBO.Unbind();
	curEBO.Unbind();
	// Adding texture
	if (stride == (GLsizeiptr)8)
	{
		std::cout << (texPath + *textureName).c_str() << std::endl;
		curTex.tex((texPath + *textureName).c_str(), GL_TEXTURE_2D, GL_TEXTURE0, rgb, GL_UNSIGNED_BYTE);
		curTex.texUnit(*shaderProgram, "tex0", 0);

	}
}
// Default constructor 
Object::Object()
{
	this->Xl = 0;
	this->Yd = 0;
	this->Xr = 0;
	this->Yu = 0;
}

//Constructor that takes coordinates
Object::Object(double X1, double Y1, double X2, double Y2)
{
	this->Xl = X1;
	this->Yd = Y1;
	this->Xr = X2;
	this->Yu = Y2;

}
// Destructor
Object::~Object()
{
	curVAO.Delete();
	curVBO.Delete();
	curEBO.Delete();
	curTex.Delete();
}

// Binds current object to draw it
void Object::use()
{
	curTex.Bind();
	curVAO.Bind();
}

// Adding object vertices (positions, color, texCoord)
void Object::addVertices(int n, ...)
{
	va_list factor;
	va_start(factor, n);

	for (int i = 0; i < n; i++)
	{

		vertices.push_back((GLfloat)va_arg(factor, double));
	}
	va_end(factor);
}

// Addings object indices (vertices order)
void Object::addIndices(int n, ...) 
{
	va_list factor;
	va_start(factor, n);

	for (int i = 0; i < n; i++)
	{

		indices.push_back((GLuint)va_arg(factor, int));

	}
	va_end(factor);
}