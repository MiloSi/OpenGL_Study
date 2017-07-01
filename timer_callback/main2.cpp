#include <gl\glut.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <time.h>


const unsigned char PALETTE[17][3] = {
	{ 255, 255, 255 },
	{ 0, 255, 255 },
	{ 255, 0, 255 },
	{ 0,0, 255 },
	{192, 192, 192 },
	{ 128, 128, 128 },
	{0, 128, 128 },
	{ 128, 0, 128 },
	{ 0, 0, 128 },
	{ 255, 255, 0 },
	{ 0, 255,0  },
	{ 128, 128, 0 },
	{ 0, 128,  0},
	{ 255, 0, 0 },
	{128, 0,  0 },
	{ 0, 0,  0 },
	{192, 43, 143}
};

GLfloat delta = 0.0f;
GLint index = 0;
GLfloat r = 0.0f;
GLfloat g = 0.0f;
GLfloat b = 0.0f;


void myDisplay() {

	// 255를 1로 노말리제이션
	r = PALETTE[index][0] / 255.0f;
	g = PALETTE[index][1] / 255.0f;
	b = PALETTE[index][2] / 255.0f;

	glColor3f(r, g, b);

	glBegin(GL_LINES);
	glVertex3f(-1.0f + delta, 1.0f, 0.f);
	glVertex3f(1.0f - delta, -1.0f, 0.f);
	glVertex3f(-1.0 , -1.0 + delta, 1.0);
	glVertex3f(1.0 , 1.0 - delta, 1.0);
	glEnd();
	glutSwapBuffers();

}
void myTimer(int value) {

	if (delta < 2.0f)
		delta = delta + 0.01;
	else
	{
		delta = 0;
		if (++index >= 16) {
			index = 0;
			glClear(GL_COLOR_BUFFER_BIT);
		}
	}
	glutPostRedisplay();
	glutTimerFunc(10, myTimer, 1);
}

void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, 1.0, 1.0, -1.0, 1.0);

}

int main(int argc, char ** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("OpenGL Drawing Example");

	init();
	glutDisplayFunc(myDisplay);
	glutTimerFunc(10, myTimer, 1);
	
	
	glutMainLoop();
	return 0;
}
