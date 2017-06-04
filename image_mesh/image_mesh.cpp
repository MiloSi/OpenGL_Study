#include "image_mesh.h"


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

	if (key == 'r')
	{
		scale = 1.0;
		thetaX = 0;
		thetaY = 180;

	}


	if (key == 27) {
		exit(0);
	}
	if (scale < 0.1) scale = 0.1;
	if (scale > 1.4) scale = 1.4;
}


void display()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(0, 0, 130, 0, 0, 0, 0, 1, 0);

	glRotatef(thetaX, 0.0, 1.0, 0.0);
	glRotatef(thetaY, 1.0, 0.0, 0.0);

	glScalef(scale, scale, scale);

	glTranslatef(-208, -120, -128);


	int x;
	int y;
	int z;
	for (int j = 1; j < 240 -1; j++)
	{
		for (int i = 1; i < 416 -1; i++)
		{
			glBegin(GL_POLYGON);
			x = i; y = j;  z = data[y][x]; glColor3f((float)z / 255, (float)z / 255, (float)z / 255);
			glVertex3i(x, y, (int)z);
			x = i; y = j+1;  z = data[y][x]; glColor3f((float)z / 255, (float)z / 255, (float)z / 255);
			glVertex3i(x, y, (int)z);
			x = i+1; y = j+1;  z = data[y][x]; glColor3f((float)z / 255, (float)z / 255, (float)z / 255);
			glVertex3i(x, y, (int)z);
			x = i+1; y = j;  z = data[y][x]; glColor3f((float)z / 255, (float)z / 255, (float)z / 255);
			glVertex3i(x, y, (int)z);
		
			glEnd();
		}
	}
	
	glFlush();
	glutSwapBuffers();
}

void init() {

	FILE *fpt = fopen("testo.y", "rb");
	fread(data, 416 * 240, sizeof(GLubyte), fpt);
	fclose(fpt);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();


	glClearColor(1.0, 1.0, 1.0, 1.0);
	glOrtho(-250.0, 250.0, -250.0, 250.0, 0, 500);
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_MODELVIEW);
}

void reDisplay() {
	glutPostRedisplay();
}
