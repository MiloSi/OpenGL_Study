#include <iostream>
#include <gl\glut.h>
#include <ctime>
#include <cstdlib>

void init();
void display();
void timer(int t);

#define DELAY 10
#define CLEAR 1000


double move_x = 0.1;
double move_y = 0.1;

double position_x;
double position_y;

int count = 0;



int main(int argc, char * argv[])
{
	
	//in glut version, it should 
	glutInit(&argc, (char**)argv);
	glutInitWindowSize(500, 500);


	glutCreateWindow("Bouncing pixel");
	glutDisplayFunc(display);
	glutTimerFunc(DELAY, timer, 0);

	init();
	glutMainLoop();

	return 0;
}

void timer(int t)
{
	
	count++;
	if (count == CLEAR) {
		glClear(GL_COLOR_BUFFER_BIT);
		count = 0;
	}
	glutPostRedisplay();
	glutTimerFunc(DELAY, timer, t);
}

void init() {
	srand(time(0));
	position_x = rand() % 50;
	position_y = rand() % 50;

	glClearColor(1.0, 1.0, 1.0, 1.0);

	gluOrtho2D(0.0, 50.0, 0.0, 50.0);




	glClear(GL_COLOR_BUFFER_BIT);
}

void display()
{

	glColor3f((GLfloat) position_x / 50, (GLfloat)position_y / 50, 0.0);


	if (position_x >= 50 || position_x <= 0)
		move_x = -move_x;
	if (position_y >= 50 || position_y <= 0)
		move_y = -move_y;

	position_x = position_x + move_x;
	position_y = position_y + move_y;

	glBegin(GL_POINTS);
		glVertex2f(position_x, position_y);


	glEnd();
	glFlush();
}