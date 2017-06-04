#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS 
#endif


#pragma once
#include <gl\glut.h>
#include <cstdlib>
#include <fstream>

void init();
void display();
void mouseHandler(int btn, int state, GLint x, GLint y);
void motionHandler(GLint x, GLint y);
void keyboardHandler(GLubyte key, GLint x, GLint y);
void reDisplay();



static GLint fromX;
static GLint fromY;

static GLboolean flag = false;
static GLfloat thetaX = 0;
static GLfloat thetaY = 180;

static GLfloat scale = 1.0;


static GLint projectionMode = 0;
static GLboolean isProjection = false;

static GLint windowID;

static GLubyte data[240][416];



