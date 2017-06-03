#include <iostream>
#include <gl\glut.h>


void init();
void display();

void recursiveTriangle(GLfloat x, GLfloat y, GLfloat length, int r);
void mouseHandler(int btn, int state, int x, int y);

static int recursive = 2;


int main(int argc, char * argv[])
{

	//in glut version, it should 
	glutInit(&argc, (char**)argv);
	glutInitWindowSize(500, 500);


	glutCreateWindow("Bouncing pixel");
	glutDisplayFunc(display);

	glutMouseFunc(mouseHandler);
	init();
	glutMainLoop();

	return 0;
}


void mouseHandler(int btn, int state, int x, int y)
{
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) recursive++;
	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) recursive--;

	if (recursive < 1) recursive = 1;
	if (recursive > 6) recursive = 6;

	if(state == GLUT_DOWN)
		glutPostRedisplay();
}


void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	gluOrtho2D(0.0, 100.0, 0.0, 100.0);
	//glClear(GL_COLOR_BUFFER_BIT);
}

void recursiveTriangle(GLfloat x, GLfloat y, GLfloat length, int r)
{


	if (r == recursive) {

		glBegin(GL_TRIANGLES);
		glVertex2f(x, y);
		glVertex2f(x + length / 2, y + length);
		glVertex2f(x + length, y);
		glEnd();
		return;
	}
	length = length / 2;

	recursiveTriangle(x, y, length, r+1);
	recursiveTriangle(x + length, y, length, r + 1);
	recursiveTriangle(x + length / 2 , y + length, length, r + 1);



}

void display()
{

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0, 0);


	glBegin(GL_TRIANGLES);

	recursiveTriangle(0, 0, 100, 1);
	


	glFlush();
}