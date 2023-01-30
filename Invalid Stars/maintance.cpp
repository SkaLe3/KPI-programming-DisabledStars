#include "maintenance.h"

#include <Windows.h>
#include "common.h"


// Sound Engine object
irrklang::ISoundEngine* SoundEngine = irrklang::createIrrKlangDevice();

// Turns on music
void playMusic()
{
	SoundEngine->stopAllSounds();
	if (musicIsOn) SoundEngine->play2D(musFile[selectedMusic], false);
}
// Turns off music
void stopMusic()
{
	SoundEngine->stopAllSounds();
}

// Checks music status and turns it on when status ~ should play
void checkMusic()
{
	if (!(SoundEngine->isCurrentlyPlaying(musFile[selectedMusic])) && musicIsOn)
	{
		selectedMusic++;
		if (selectedMusic > 2) selectedMusic = 0;
		playMusic();

	}
}

// Translates input coordinates to user coordinates
void  ScreenToOpenGL(GLFWwindow* window, double x, double y, float* ox, float* oy)
{
	GLint width, height;
	glfwGetWindowSize(window, &width, &height);
	*ox =(float)( x / (float)width * 1920);
	*oy =(float)(1080 - y / (float)height * 1080);
}

// Checks click status and where
bool checkClick(GLFWwindow* window, Object* obj)
{
	if (click)
	{
		POINTFLOAT pf;
		double xpos = 1, ypos = 1;
		glfwGetCursorPos(window, &xpos, &ypos);
		ScreenToOpenGL(window, xpos, ypos, &pf.x, &pf.y);
		if (obj->Xl <= pf.x && obj->Xr >= pf.x && obj->Yd <= pf.y && obj->Yu >= pf.y)
			return true;

	}
	return false;
}

