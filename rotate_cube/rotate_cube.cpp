#include <iostream>
#include <gl\glut.h>

void init();
void display();
void mouseHandler(int btn, int state, GLint x, GLint y);
void motionHandler(GLint x, GLint y);
void reDisplay();

GLfloat theta = 0.0;

static GLint fromX;
static GLint fromY;

static GLboolean flag = false;
static GLfloat thetaX = 0;
static GLfloat thetaY = 0;




GLfloat vertices[][3] = { { -1.0,-1.0,-1.0 },{ 1.0,-1.0,-1.0 },{ 1.0,1.0,-1.0 },{ -1.0,1.0,-1.0 },
{ -1.0,-1.0, 1.0 },{ 1.0,-1.0, 1.0 },{ 1.0,1.0, 1.0 },{ -1.0,1.0, 1.0 } };
GLfloat colors[][3] = { { 0.0, 0.0, 0.0 },{ 1.0, 0.0, 0.0 },{ 1.0,1.0, 0.0 },{ 0.0,1.0, 0.0 },
{ 0.0, 0.0, 1.0 },{ 1.0, 0.0, 1.0 },{ 1.0,1.0, 1.0 },{ 0.0,1.0, 1.0 } };


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
		thetaX += (x - fromX) ;
		thetaY += (y - fromY) ;


		fromX = x;
		fromY = y;

		if (thetaX > 360)  thetaX = -360;
		if (thetaX < -360) thetaX =  360;

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


	polygon(0, 3, 2, 1);
	polygon(2, 3, 7, 6);
	polygon(0, 4, 7, 3);
	polygon(1, 2, 6, 5);
	polygon(4, 5, 6, 7);
	polygon(0, 1, 5, 4);
	glFlush();
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


int main(int argc, char * argv[])
{

	glutInit(&argc, (char**)argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);

	

	glutCreateWindow("ROTATE CUBE");
	glutDisplayFunc(display);
	glutIdleFunc(reDisplay);
	glutMouseFunc(mouseHandler);
	glutMotionFunc(motionHandler);
	
	init();
	glutMainLoop();

	return 0;
}