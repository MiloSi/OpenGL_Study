#include <gl\glut.h>
#include <gl\GL.h>
#include <gl\GLU.h>


GLfloat delta = 0.0f;
void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.5f, 0.8f);
	glVertex3f(-1.0f + delta, -0.5f, 0.0f);
	glVertex3f(0.0f + delta, -0.5f, 0.0f);
	glVertex3f(0.0f + delta, 0.5f, 0.0f);
	glVertex3f(-1.0f + delta, 0.5f, 0.0f);
	glEnd();
	//플러쉬 말고 버퍼 메인에서 더블을 사용하니까..
	glutSwapBuffers();
}
void myTimer(int value) {
	delta = delta + 0.001f;
	glutPostRedisplay();
	glutTimerFunc(40, myTimer, 1);
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
	glutTimerFunc(40, myTimer, 1);
	
	
	glutMainLoop();
	return 0;
}
