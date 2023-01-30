#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<stb/stb_image.h>
#include <Windows.h>

#include "maintenance.h"
#include"common.h"
#include"objectClass.h"
#include "draw.h"

#include "input.h"
#include "settingsMenu.h"
#include "gameplay.h"









int main()
{
	// Turn on music on the start
	playMusic();
	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// Creates window
	GLFWwindow* window = glfwCreateWindow(1920, 1080, "Disabled Stars", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwSetKeyCallback(window, key_callback);
	glfwSetMouseButtonCallback(window, mouse_callback);
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	glViewport(0, 0, 1920, 1080);



	// Generates Shader object using shaders default.vert and default.frag
	Shader shaderProgram("default.vert", "default.frag");

	// Sets menu background texture
	Object menuBackground(0, 0, 1920, 1080);
	setBackground(&shaderProgram, &menuBackground, backgroundTex);
	// Sets menu title texture
	Object menuTitle(200, 800, 1720, 1000);
	setTitle(&shaderProgram, &menuTitle, titleTex);
	// Sets play button texture
	Object playButton(850, 500, 1050, 600);
	setButton(&shaderProgram, &playButton, playTex);
	// Sets settings button texture
	Object settingsButton(750, 350, 1150, 450);
	setButton(&shaderProgram, &settingsButton, settingsTex);
	// Gets ID of uniform called "scale"
	GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");
	GLuint translateID = glGetUniformLocation(shaderProgram.ID, "translate");


	while (!glfwWindowShouldClose(window)) //main menu game loop
	{
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);
		// Tell OpenGL which Shader Program we want to use
		shaderProgram.Activate();

		// Moves center of coordinates to the left 
		glUniform3f(translateID, -1.0, -1.0, 0.0);
		// Change scale of coordinates
		glUniform3f(uniID, 2/1920.0f, 2/1080.0f, 1.0f);


		// Draws background
		menuBackground.use();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		// Draws game title
		menuTitle.use();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		// Draws play button
		playButton.use();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		// Draws settings button
		settingsButton.use();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		// Checks if buttons were pressed and calls function
		if (checkClick(window, &playButton)) { click = false; newGame(window, &shaderProgram); }
		if (checkClick(window, &settingsButton)) { click = false; settingsMenu(window, &shaderProgram); }

		// Play music if music dont't play
		checkMusic();
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();

	}
	// Destroying all objects that was created
	shaderProgram.Delete();
	glfwDestroyWindow(window);
	glfwTerminate();
	SoundEngine->drop();
	return 0;
}