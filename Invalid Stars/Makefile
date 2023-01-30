CFLAG = -Wall -g -O2
CC = cc
INCLUDES = Main.cpp EBO.cpp shaderClass.cpp stb.cpp Texture.cpp VAO.cpp VBO.cpp common.cpp draw.cpp gameplay.cpp glad.c input.cpp maintance.cpp objectClass.cpp settingsMenu.cpp EBO.h shaderClass.h Texture.h VAO.h VBO.h common.h draw.h gameplay.h input.h maintance.h objectClass.h settingsMenu.h
FLAGS = -glfw3 -irrklang  -lGL -lm -lpthread -ldl -lrt -lX11
all:
	${CC} ${INCLUDES} ${CFLAG} ${FLAGS} 

clean:
	rm -rf a.out

compile:
	${CC} ${INCLUDES} ${CFLAG} ${FLAGS} 
