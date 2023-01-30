#include "draw.h"
#include "common.h"
#include <stb_easy_font.h>

// Function that sets background object vertices  and links it with shader
void setBackground(Shader *shaderProgram, Object *background, std::string tex)
{
	background->addVertices(32,
		 background->Xl, background->Yd, 0.0f, 1.0f, 0.0f, 0.0f,		0.0f, 0.0f, // Lower left corner
		 background->Xl, background->Yu, 0.0f, 0.0f, 1.0f, 0.0f,		0.0f, 1.0f, // Upper left corner
		 background->Xr, background->Yu, 0.0f, 0.0f, 0.0f, 1.0f,		1.0f, 1.0f, // Upper right corner
		 background->Xr, background->Yd, 0.0f, 1.0f, 1.0f, 1.0f,		1.0f, 0.0f  // Lower right corner
	);
	background->addIndices(6,
		0, 2, 1,
		0, 3, 2);

	background->Link(8, shaderProgram, &tex, 0x1907);
}

// Function that sets text object vertices  and links it with shader
void setTitle(Shader* shaderProgram, Object* title, std::string tex)
{
	title->addVertices(32,
		title->Xl,  title->Yd,	0.0f, 1.0f, 0.0f, 0.0f,		0.0f, 0.0f,
		title->Xl,  title->Yu,  0.0f, 0.0f, 1.0f, 0.0f,		0.0f, 1.0f,
		title->Xr,  title->Yu,  0.0f, 0.0f, 0.0f, 1.0f,		1.0f, 1.0f,
		title->Xr,  title->Yd,  0.0f, 1.0f, 1.0f, 1.0f,		1.0f, 0.0f
	);
	title->addIndices(6,
		0, 2, 1,
		0, 3, 2);

	title->Link(8, shaderProgram, &tex, 0x1908);
}
// Function that sets button object vertices  and links it with shader
void setButton(Shader* shaderProgram, Object* button, std::string tex)
{
	button->addVertices(32,
		button->Xl, button->Yd, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
		button->Xl, button->Yu, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
		button->Xr, button->Yu, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
		button->Xr, button->Yd, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f
	);
	button->addIndices(6,
		0, 2, 1,
		0, 3, 2);

	button->Link(8, shaderProgram,&tex, 0x1908);
}
// Function that sets canvas object vertices  and links it with shader
void setCanvas(Shader* shaderProgram, Object* obj, GLfloat r , GLfloat g, GLfloat b, GLfloat fade)
{
	obj->addVertices(24,
		obj->Xl, obj->Yd, 0, r-(fade/2.0), g - (fade / 2.0), b - (fade / 2.0),
		obj->Xl, obj->Yu, 0, r, g, b,
		obj->Xr, obj->Yu, 0, r - (fade / 4.0), g - (fade / 4.0), b - (fade / 4.0),
		obj->Xr, obj->Yd, 0, r-fade, g-fade, b-fade
	);
	obj->addIndices(6,
		0, 2, 1,
		0, 3, 2);
	obj->Link(6, shaderProgram );
}