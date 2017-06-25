#include "teapot.h"

GLint TEAPOT::width = 0;
GLint TEAPOT::height = 0;
GLboolean isWhite = false;

TEAPOT::TEAPOT() {
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
}


TEAPOT::TEAPOT(int argc, char** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
}

GLboolean TEAPOT::setWindowSize(const GLint& width, const GLint& height)
{


	this->width = width;
	this->height = height;


	isSetSize = true;
	return true;
}
GLboolean TEAPOT::setWindowPosition(const GLint& x, const GLint& y)
{

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
	glClearColor(0.0, 0.0, 0.0, 1.0);
	
	GLfloat mat_diffuse[] = { 0.5, 0.4, 0.3, 1.0 };
	GLfloat mat_specular[] = { 1.0 , 1.0, 1.0, 1.0 };
	GLfloat mat_ambient[] = { 0.5, 0.4, 0.3, 1.0 };
	GLfloat mat_shininess[] = { 15.0 };

	GLfloat light_specular[] = { 1.0, 1.0, 1.0,1.0 };
	GLfloat light_diffuse[] = { 0.8, 0.8, 0.8,1.0 };
	GLfloat light_ambient[] = { 0.3, 0.3, 0.3, 1.0 };
	GLfloat light_position[] = { -3.0, 6.0, 3.0, 0.0 };

	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);

	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	

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
		glutInitWindowSize(800, 800);


	glutCreateWindow("HELLO WORLD");
	init();

	glutCreateMenu(menu);
	glutAddMenuEntry("White", 0);
	glutAddMenuEntry("Black", 1);
	glutAddMenuEntry("Exit", 2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutDisplayFunc(display);

	if (isSetTimer) glutTimerFunc(time, timer, 1);

	glutMainLoop();

	return 1;

}

void display()
{
	if (isWhite)
		glClearColor(1.0, 1.0, 1.0, 1.0);
	else
		glClearColor(0.0, 0.0, 0.0, 1.0);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	
	glColor3f(1.0, 0.0, 0.0);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
		
	glViewport(0, 0, TEAPOT::width / 2, TEAPOT::height /2);
	gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 1.0, 0.0);
	glutSolidTeapot(0.5);


	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHTING);

	glColor3f(1.0, 1.0, 0.0);

	glViewport(TEAPOT::width / 2, 0, TEAPOT::width / 2, TEAPOT::height / 2);
	gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 1.0, 0.0);
	glutWireTeapot(0.5);


	glColor3f(0.0, 1.0, 1.0);


	glViewport(0, TEAPOT::height / 2, TEAPOT::width / 2, TEAPOT::height / 2);
	gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 1.0, 0.0);
	glutSolidTeapot(0.5);



	glColor3f(0.0, 0.0, 1.0);

	glViewport(TEAPOT::width / 2, TEAPOT::height / 2,TEAPOT::width / 2, TEAPOT::height / 2);
	gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 1.0, 0.0);
	glutSolidTeapot(0.5);
	glutSwapBuffers();

}

void timer(const GLint time)
{
	glutPostRedisplay();
	glutTimerFunc(time, timer, 1);
}

void menu(const GLint entryId) {

	if (entryId == WHITE) {
		isWhite = true;
	}
	else if (entryId == BLACK) {
		isWhite = false;
	}
	else if (entryId == EXIT) {
		exit(1);
	}
	glutPostRedisplay();
}

