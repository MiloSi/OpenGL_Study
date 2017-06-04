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


void polygon(int a, int b, int c, int d)
{
	glBegin(GL_POLYGON);
	glColor3fv(colors[a]);
	glVertex3fv(vertices[a]);
	glColor3fv(colors[b]);
	glVertex3fv(vertices[b]);
	glColor3fv(colors[c]);
	glVertex3fv(vertices[c]);
	glColor3fv(colors[d]);
	glVertex3fv(vertices[d]);
	glEnd();
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	glRotatef(thetaX, 0.0, 1.0, 0.0);
	glRotatef(thetaY, 1.0, 0.0, 0.0);


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
