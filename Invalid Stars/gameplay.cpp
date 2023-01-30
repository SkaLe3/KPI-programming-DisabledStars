#include "gameplay.h"

#include "objectClass.h"
#include "draw.h"
#include "common.h"
#include "maintenance.h"


// Draws text with resul - win or failed
void result(GLFWwindow* window, Shader* shaderProgram, std::string res)
{
	// Sets background texture
	Object gameBackground(0, 0, 1920, 1080);
	setBackground(shaderProgram, &gameBackground, gameBGTex);
	// Sets message texture
	Object message(500, 500, 1420, 800);
	setTitle(shaderProgram, &message, res);
	while (!glfwWindowShouldClose(window))
	{
		//clear window
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		// Draw background texture
		gameBackground.use();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		// Draw message texture
		message.use();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		// Closes message
		if (click)
		{
			click = false;
			return;
		}

		click = false;
		checkMusic();
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}
}

// Function that runs all levels
void newGame(GLFWwindow* window, Shader* shaderProgram)
{
	for (int i = 0; i < 12; i++)
	{
		if (!level(window, shaderProgram, i)) {
			result(window, shaderProgram, failedTex);
			return;
		}
	}

	result(window, shaderProgram, wonTex);
}


// Function that creates level 
bool level(GLFWwindow* window, Shader* shaderProgram, int lvl)
{
	// Sets background texture
	Object gameBackground(0, 0, 1920, 1080);
	setBackground(shaderProgram, &gameBackground, gameBGTex);
	
	// Sets frame color
	Object canvasFrame(400, 30, 1200, 1050);
	setCanvas(shaderProgram, &canvasFrame, 1.0f, 1.0f, 1.0f, 0.4f);
	// Sets field color
	Object canvasFill(420, 50, 1180, 1030);
	setCanvas(shaderProgram, &canvasFill, 0.2f, 0.2f, 0.3f, 0.2f);

	// Sets constellation texture
	Object constellation(420, 50, 1180, 1030);
	setTitle(shaderProgram, &constellation, constellationTex[lvl]);

	// Back Button texture
	Object goBackButton(50, 50, 355.18, 170);
	setButton(shaderProgram, &goBackButton, backTex);

	// Sets button1 texture
	Object Button1(1250, 850, 1870, 1050);
	setTitle(shaderProgram, &Button1, buttonsTex[lvl*4]);
	// Sets button2 texture
	Object Button2(1250, 576, 1870, 776);
	setTitle(shaderProgram, &Button2, buttonsTex[lvl * 4 + 1]);
	// Sets button3 texture
	Object Button3(1250, 303, 1870, 503);
	setTitle(shaderProgram, &Button3, buttonsTex[lvl * 4 + 2]);
	// Sets button4 texture
	Object Button4(1250, 30, 1870, 230);
	setTitle(shaderProgram, &Button4, buttonsTex[lvl * 4 + 3]);



	// Game loop
	while (!glfwWindowShouldClose(window))
	{
		// Clear window
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Draw background
		gameBackground.use();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		// Draw back button
		goBackButton.use();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		// Draw frame
		canvasFrame.use();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		//Draw field
		canvasFill.use();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		// Draw buttons
		Button1.use();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		Button2.use();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		Button3.use();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		Button4.use();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		// Draw constellation
		constellation.use();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		// Checks click on button
		if (checkClick(window, &Button1))
		{
			click = false;
			if (answer[lvl] == 1) return true;
			return false;
		}
		if (checkClick(window, &Button2))
		{
			click = false;
			if (answer[lvl] == 2) return true;
			return false;
		}
		if (checkClick(window, &Button3))
		{
			click = false;
			if (answer[lvl] == 3) return true;
			return false;
		}
		if (checkClick(window, &Button4))
		{
			click = false;
			if (answer[lvl] == 4) return true;
			return false;
		}
		// Checks click on back button
		if (checkClick(window,	&goBackButton)) return false;

		click = false;
		// Play music if music dont't play
		checkMusic();
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}
	return true;

}