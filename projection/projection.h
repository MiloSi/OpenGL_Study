#pragma once
#include <gl\glut.h>

void init();
void display();
void mouseHandler(int btn, int state, GLint x, GLint y);
void motionHandler(GLint x, GLint y);
void reDisplay();





static GLfloat vertices[][3] = { { -1.0,-1.0,-1.0 },{ 1.0,-1.0,-1.0 },{ 1.0,1.0,-1.0 },{ -1.0,1.0,-1.0 },
{ -1.0,-1.0, 1.0 },{ 1.0,-1.0, 1.0 },{ 1.0,1.0, 1.0 },{ -1.0,1.0, 1.0 } };
static GLfloat colors[][3] = { { 0.0, 0.0, 0.0 },{ 1.0, 0.0, 0.0 },{ 1.0,1.0, 0.0 },{ 0.0,1.0, 0.0 },
{ 0.0, 0.0, 1.0 },{ 1.0, 0.0, 1.0 },{ 1.0,1.0, 1.0 },{ 0.0,1.0, 1.0 } };

static GLubyte indices [] = { 0,3,2,1, 2,3,7,6, 0,4,7,3,
1,2,6,5, 4,5,6,7, 0,1,5,4 };
static GLint fromX;
static GLint fromY;

static GLboolean flag = false;
static GLfloat thetaX = 0;
static GLfloat thetaY = 0;

