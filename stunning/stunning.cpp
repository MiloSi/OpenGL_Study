#include <gl/glut.h>
#include <gl/GLU.h>
#include <Windows.h>
#include <math.h>


int list;

class Rotate {
public:
	Rotate() : angle(0.0), x(0.0), y(0.0) {
	}

	void calculate(double i) {
		rotate = rotate + i;
		if (rotate >= 360) rotate = 0;

		angle = 2 * 3.141592 * rotate / 360;
		x = cos(angle);
		y = sin(angle);
	}
	GLdouble rotate;
	GLdouble angle;
	GLdouble x;
	GLdouble y;
};

Rotate bigRotate, smallRotate;


void drawBigSphere(const GLdouble& x,const GLdouble& y,const GLdouble& z) {
	glTranslated(x, y, z);
	glColor3f(1.0, 1.0, 1.0);
	glutWireSphere(0.04, 8, 8);
}

void drawSmallSphere(const GLdouble& rotateX, const GLdouble& rotateY, const GLdouble& translate, GLdouble rotate) {
	glRotated(rotate, rotateX, rotateY, 0);
	glTranslated(0, 0, translate);
	glColor3f(1.0, 1.0, 1.0);
	glutWireSphere(0.02, 8, 8);
}
void listHandler() {
	list = glGenLists(1);
	glNewList(list, GL_COMPILE);

	glBegin(GL_POINTS);
	glColor3f(0.3, 0.7, 0.6);
	for (double i = 0; i < 360; i += 0.1)
	{
		GLdouble angle = 2 *  3.141592 * i / 360;
		GLdouble x = cos(angle);
		GLdouble y = sin(angle);

		glVertex3f(x, 0, y);
	}
	glEnd();
	glEndList();
	
}




void displayHandler() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glCallList(list);
	glPopMatrix();



	glPushMatrix();
	drawBigSphere(bigRotate.x, 0, bigRotate.y);
	glPushMatrix();
		drawSmallSphere(1, -1, 0.08, smallRotate.rotate);
		glPopMatrix();
	glPushMatrix();
		drawSmallSphere(-1, 1, 0.08, smallRotate.rotate);
		glPopMatrix();
	glPushMatrix();
		drawSmallSphere(-1, -1, 0.08, smallRotate.rotate);
		glPopMatrix();
	glPushMatrix();
		drawSmallSphere(1, 1, 0.08, smallRotate.rotate);
		glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	drawBigSphere(bigRotate.y, 0, bigRotate.x);
		glPushMatrix();
	drawSmallSphere(1, -1, 0.08, smallRotate.rotate);
	glPopMatrix();
	glPushMatrix();
	drawSmallSphere(-1, 1, 0.08, smallRotate.rotate);
	glPopMatrix();
	glPushMatrix();
	drawSmallSphere(-1, -1, 0.08, smallRotate.rotate);
	glPopMatrix();
	glPushMatrix();
	drawSmallSphere(1, 1, 0.08, smallRotate.rotate);
	glPopMatrix();
	glPopMatrix();

	
	glutSwapBuffers();
}
void init() {

	glEnable(GL_DEPTH_TEST);
	glClearColor(0.2, 0.2, 0.2, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, -4.0, 4.0);
	gluLookAt(0, 1, -2, 0.0, 0, 1, 0, 1, 0);

}
void menuHandler() {
	
}
void timerHandler(int t) {
	bigRotate.calculate(1);
	smallRotate.calculate(4);

	glutPostRedisplay();
	glutTimerFunc(1, timerHandler, 1);
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow) {

	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutCreateWindow("STUNNING");
	init();

	glutDisplayFunc(displayHandler);
	glutTimerFunc(1, timerHandler, 1);
	listHandler();

	glutMainLoop();


	return 0;

}