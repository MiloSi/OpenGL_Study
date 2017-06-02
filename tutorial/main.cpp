#include <gl\glut.h>



void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);

	glVertex3f(-0.5, -0.5,  0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(-0.5, 0.5, 0.0);


	glEnd();
	glFlush();
}


int main()
{
	glutCreateWindow("OPENGL");
	glutDisplayFunc(MyDisplay);
	glutMainLoop();

	return 0;
}