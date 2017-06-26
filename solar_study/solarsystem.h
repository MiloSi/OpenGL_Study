#pragma once
#include<gl\glut.h>
#include<gl\GL.h>


class SolarSystem {

public: SolarSystem();
		void showWindow();

		static GLfloat Day;
		static GLfloat Time;
		static GLfloat Hour;
	
};


void timerHandler(const GLint);
void displayHandler();
void mouseHandler();
void keyboardHandler();
void menuHandler();


