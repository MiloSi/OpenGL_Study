#include "solarsystem.h"

GLfloat SolarSystem::Day = 0.0f;
GLfloat SolarSystem::Time = 0.0f;
GLfloat SolarSystem::Hour = 0.0f;

SolarSystem::SolarSystem() {
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

}

void SolarSystem::showWindow() {
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Solar System");



	glClearColor(1.0, 1.0, 1.0, 1.0);
	
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2, 2, -2, 2, -2, 2);

	glutDisplayFunc(displayHandler);
	glutTimerFunc(20, timerHandler, 1);

	glutMainLoop();
}


void displayHandler() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	glColor3f(1.0, 0.3, 0.3);
	glRotatef(SolarSystem::Day, 0.0, 1.0, 0.0);
	glutWireSphere(0.2, 20, 5);

	glPopMatrix();
	glTranslated(0.0, 0.4, 0.0);
	glColor3f(0.5, 0.6, 0.7);
	glutSolidSphere(0.1, 10, 8);

	
	glPushMatrix(); {
		glRotatef(SolarSystem::Day, 1.0, 1.0, 0.0);
		glTranslated(0.0, 0.0, 1.0);
	
		glColor3f(0.7, 0.8, 0.7);
		glutWireSphere(0.1, 10, 8);

		glPushMatrix();
		{
			glRotatef((GLfloat)SolarSystem::Hour, 0.0, 1.0, 0.0);
			glTranslated(0.2, 0.0, 0.0);
			glColor3f(0.9, 0.8, 0.2);
			glutWireSphere(0.04, 10, 8);
			glPopMatrix();
		}
		glPopMatrix();
	}
	glRotatef(SolarSystem::Day, 0.0, 1.0, 0.0);
	glTranslated(1.2, 0.4, 0.0);
	glRotatef((GLfloat)SolarSystem::Time, 0.0, 1.0, 0.0);
	glColor3f(0.5, 0.6, 0.7);
	glutWireSphere(0.1, 10, 8);
	glutSwapBuffers();
}

void timerHandler(const GLint t) {
	GLfloat &day = SolarSystem::Day;
	GLfloat &time = SolarSystem::Time;
	GLfloat &hour = SolarSystem::Hour;

	day = day + 2 >= 360 ? 0 : day + 2;
	time = time + 2 >= 360 ? 0 : time + 2;
	hour = hour + 0.5 >= 360 ? 0 : hour + 0.5;
	

	glutPostRedisplay();
	glutTimerFunc(40, timerHandler, 1);
}