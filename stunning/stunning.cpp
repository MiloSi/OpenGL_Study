#include <gl/glut.h>
#include <gl/GLU.h>
#include <Windows.h>
#include <math.h>


int list;
int time = 3;
GLdouble starsVertex[10][2];

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

		glVertex3f(x ,1, y );
	}
	

	glEnd();
	glEndList();
	
}


void drawVertex(int d1, int d2, int d3)
{
	glBegin(GL_QUADS);
	glColor3f(1, 1, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(starsVertex[d1][0] / 2, starsVertex[d1][1] / 2, 0);
	glVertex3f(starsVertex[d2][0], starsVertex[d2][1], 0);
	glVertex3f(starsVertex[d2][0] / 2, starsVertex[32][1] / 2, 0.3);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(starsVertex[d1][0] / 2, starsVertex[d1][1] / 2, 0);
	glVertex3f(starsVertex[d2][0], starsVertex[d2][1], 0);
	glVertex3f(starsVertex[d2][0] / 2, starsVertex[32][1] / 2, -0.3);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(starsVertex[d3][0] / 2, starsVertex[d3][1] / 2, 0);
	glVertex3f(starsVertex[d2][0], starsVertex[d2][1], 0);
	glVertex3f(starsVertex[d2][0] / 2, starsVertex[32][1] / 2, 0.3);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(starsVertex[d3][0] / 2, starsVertex[d3][1] / 2, 0);
	glVertex3f(starsVertex[d2][0], starsVertex[d2][1], 0);
	glVertex3f(starsVertex[d2][0] / 2, starsVertex[32][1] / 2, -0.3);
	glEnd();
}

void mainMenu(int id) {
	if (id == 0)
		time = 1;
	else if (id == 1)
		time = 3;
	else if (id == 2)
		time = 5;
	else if (id == 3)
		time = 8;
	else
		time = 10;
}



void star()
{
	drawVertex(9, 0, 1);
	drawVertex(1, 2, 3);
	drawVertex(3, 4, 5);
	drawVertex(5, 6, 7);
	drawVertex(7, 8, 9);
}
void drawStars(const GLdouble x, const  GLdouble y, GLdouble z) {
	glPushMatrix();
	glTranslated(x, y, z);
	glScalef(0.1, 0.1, 0.1);
	star();
	glPopMatrix();

}



void displayHandler() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glutSolidSphere(1.0, 40, 40);
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslated(0, -2, 0);
	glutSolidSphere(2.0, 40, 40);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glCallList(list);
	glPopMatrix();

	drawStars(bigRotate.y, 1, bigRotate.x);
	drawStars(bigRotate.y, 1, -bigRotate.x);
	drawStars(-bigRotate.y, 1, bigRotate.x);
	drawStars(-bigRotate.y, 1, -bigRotate.x);
	drawStars(bigRotate.x, 1, bigRotate.y);
	drawStars(-bigRotate.x, 1, bigRotate.y);
	drawStars(bigRotate.x, 1, -bigRotate.y);
	drawStars(-bigRotate.x, 1, -bigRotate.y);


	
	glutSwapBuffers();
}
void init() {

	glEnable(GL_DEPTH_TEST);
	glClearColor(0.2, 0.2, 0.2, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, -4.0, 4.0);
	gluLookAt(0, 1, -2, 0.0, 0, 1, 0, 1, 0);



	for (int i = 0; i < 10; i++)
	{
		GLdouble angle = 2 * 3.141592 * i / 10;
		starsVertex[i][0] = cos(angle);
		starsVertex[i][1] = sin(angle);
	}

}
void menuHandler() {
	
}
void timerHandler(int t) {
	bigRotate.calculate(1);
	smallRotate.calculate(4);

	glutPostRedisplay();
	glutTimerFunc(time, timerHandler, 1);
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow) {

	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutCreateWindow("STUNNING");
	init();

	glutDisplayFunc(displayHandler);
	glutTimerFunc(time, timerHandler, 1);
	listHandler();
	GLint menuId = glutCreateMenu(mainMenu);
	glutAddMenuEntry("FASTEST", 0);
	glutAddMenuEntry("FAST", 1);
	glutAddMenuEntry("NORMAL", 2);
	glutAddMenuEntry("SLOW", 3);
	glutAddMenuEntry("SLOWEST", 4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();


	return 0;

}