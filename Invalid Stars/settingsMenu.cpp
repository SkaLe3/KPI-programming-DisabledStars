#include "settingsMenu.h"
#include "common.h"
#include "objectClass.h"
#include "draw.h"
#include "maintenance.h"

void settingsMenu(GLFWwindow* window, Shader* shaderProgram)
{
	// Background
	Object settingsBackground(0, 0, 1920, 1080);
	setBackground(shaderProgram, &settingsBackground, settingsBGTex);

	// Back Button
	Object goBackButton(70, 70, 375.18, 190);
	setButton(shaderProgram, &goBackButton, backTex);

	// Title
	Object settingsTitle(700, 850, 1180, 970);
	setTitle(shaderProgram, &settingsTitle, settingsTex);

	// Help Button
	Object helpButton(850, 600, 1050, 700);
	setButton(shaderProgram, &helpButton, helpTex);

	// Change music on previous
	Object musicPrevButton(575, 480, 670, 561);
	setButton(shaderProgram, &musicPrevButton, musicPrevTex);

	// Music Title
	Object musicTitle(700, 500, 1240, 590);
	setTitle(shaderProgram, &musicTitle, musicAtDoomsGateTex);

	// Change music on next
	Object musicNextButton(1230, 480, 1325, 561);
	setButton(shaderProgram, &musicNextButton, musicNextTex);

	// Rules of the game
	Object rules(0, 0, 1920, 1080);
	setTitle(shaderProgram, &rules, rulesTex);

	// Turn on/off music
	Object musicOnButton(1400, 480, 1570, 568);
	setButton(shaderProgram, &musicOnButton, musicOnTex);


	while (!glfwWindowShouldClose(window))// settings game loop
	{
		// Clears window
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Draws background
		settingsBackground.use();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		// Draws back button
		goBackButton.use();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		// Draws title
		settingsTitle.use();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		// Draws help button
		helpButton.use();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		// Draws music change on previous button
		musicPrevButton.use();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		// Draws music change on next button
		musicNextButton.use();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		// Draws song title
		musicTitle.use();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		// Draws music turn on/off button
		musicOnButton.use();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		// Checks if help button were pressed and calls function
		if (checkClick(window, &helpButton))
		{
			click = false;
			// help screen loop
			while (!glfwWindowShouldClose(window) && !click)
			{
				// Clears window
				glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

				// Draws settings background 
				settingsBackground.use();
				glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
				// Draws rules of the game
				rules.use();
				glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
				glfwSwapBuffers(window);
				glfwPollEvents();
			}
		}

		// Checks if previous button were pressed and calls function
		if (checkClick(window, &musicPrevButton))
		{
			click = false;
			selectedMusic--;
			if (selectedMusic < 0) selectedMusic = 2;
			playMusic();
			setTitle(shaderProgram, &musicTitle, musName[selectedMusic]);
			musicTitle.use();
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		}
		// Checks if next button were pressed and calls function
		if (checkClick(window, &musicNextButton))
		{
			click = false;
			selectedMusic++;
			if (selectedMusic > 2) selectedMusic = 0;
			playMusic();
			setTitle(shaderProgram, &musicTitle, musName[selectedMusic]);
			musicTitle.use();
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		}

		// Checks if music turn on/off button were pressed and calls function
		if (checkClick(window, &musicOnButton))
		{
			click = false;
			// Turns on music if music status is true
			if (!musicIsOn)
			{
				musicIsOn = true;
				playMusic();
				setButton(shaderProgram, &musicOnButton, musicOnTex);
				musicOnButton.use();
				glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
				glfwSwapBuffers(window);

			}
			// Turns off music if music status is false
			else
			{
				musicIsOn = false;
				stopMusic();
				setButton(shaderProgram, &musicOnButton, musicOffTex);
				musicOnButton.use();
				glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
				glfwSwapBuffers(window);

			}
		}
		// Checks if go back button were pressed
		if (checkClick(window, &goBackButton)) return;

		checkMusic();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}