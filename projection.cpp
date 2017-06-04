#include "projection.h"


void mouseHandler(int btn, int state, GLint x, GLint y)
{


	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (!flag) {
			fromX = x;
			fromY = y;
			flag = true;
		}


	}

	else if (btn == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		flag = false;
	}

}

void motionHandler(GLint x, GLint y)
{
	if (flag)
	{
		thetaX += (x - fromX);
		thetaY += (y - fromY);


		fromX = x;
		fromY = y;

		if (thetaX > 360)  thetaX = -360;
		if (thetaX < -360) thetaX = 360;

		if (thetaY > 360)  thetaY = -360;
		if (thetaY < -360)  thetaY = 360;

	}
}


void keyboardHandler(GLubyte key, GLint x, GLint y)
{
	if (key == 'u') scale += 0.01;
	if (key == 'U') scale += 0.1;

	if (key == 'd') scale -= 0.01;
	if (key == 'D') scale -= 0.1;

	if (key == 'o' || key == 'O')
		projectionMode = 0;
	else if (key == 'f' || key == 'F')
		projectionMode = 1;
	else if (key == 'p' || key == 'P')
		projectionMode = 2;

	if (key == 27) {
		exit(0);
	}
	if (scale < 0.1) scale = 0.1;
	if (scale > 1.4) scale = 1.4;
}


void display()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (projectionMode == 0)
		glOrtho(-2.0, 2.0, -2.0, 2.0, -10, 10);

	else if (projectionMode == 1) {
	
		glFrustum(-2.0, 2.0, -2.0, 2.0, 2.0, 20.0);

	}
	else if (projectionMode == 2) {
		gluPerspective(80, 1, 2, 20);
	}

	glMatrixMode(GL_MODELVIEW);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(1, 1, 4, 0, 0, 0, 0, 1, 0);

	glRotatef(thetaX, 0.0, 1.0, 0.0);
	glRotatef(thetaY, 1.0, 0.0, 0.0);

	glScalef(scale, scale, scale);


	glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, indices);

	glFlush();
	glutSwapBuffers();
}

void init() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();


	glClearColor(1.0, 1.0, 1.0, 1.0);
	glOrtho(-2.0, 2.0, -2.0, 2.0, -10, 10);
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_MODELVIEW);
}

void reDisplay() {
	glutPostRedisplay();
}
