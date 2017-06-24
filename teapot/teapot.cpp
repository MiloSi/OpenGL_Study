#include "teapot.h"

TEAPOT::TEAPOT(int argc, char** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);


	/*
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
	*/
}

GLboolean TEAPOT::setWindowSize(const GLint& width, const GLint& height)
{
	//glutInitWindowSize(x, y);

	this->width = width;
	this->height = height;


	isSetSize = true;
	return true;
}
GLboolean TEAPOT::setWindowPosition(const GLint& x, const GLint& y)
{
	//glutInitWindowPosition(x, y);

	this->position_x = x;
	this->position_y = y;

	isSetPosition = true;
	return true;
}

GLboolean TEAPOT::setTimer(const GLint time) {
	this->time = time;

	isSetTimer = true;
	return true;
}

void TEAPOT::init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glEnable(GL_DEPTH_TEST | GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1, 1, -1, 1, -1, 1);
}

GLboolean TEAPOT::show() {

	if(isSetPosition)
		glutInitWindowPosition(position_x, position_y);
	else
		glutInitWindowPosition(0, 0);

	if(isSetSize)
		glutInitWindowSize(width, height);
	else
		glutInitWindowSize(400, 400);


	glutCreateWindow("HELLO WORLD");
	init();
	glutDisplayFunc(display);

	if (isSetTimer) glutTimerFunc(time, timer, 1);

	glutMainLoop();

	return 1;

}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glColor3f(1.0, 0.0, 0.0);

	gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 1.0, 0.0);

	glutSolidTeapot(0.2);
	glutSwapBuffers();

}

void timer(const GLint time)
{
	glutPostRedisplay();
	glutTimerFunc(time, timer, 1);
}

