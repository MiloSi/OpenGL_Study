#pragma once
#include "projection.h"


int main(int argc, char** argv) {
	glutInit(&argc, (char**)argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);


	windowID = glutCreateWindow("ROTATE CUBE");

	glutIdleFunc(reDisplay);
	glutMouseFunc(mouseHandler);
	glutMotionFunc(motionHandler);
	glutKeyboardFunc(keyboardHandler);

	
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glColorPointer(3, GL_FLOAT, 0, colors);

	glutDisplayFunc(display);

	init();
	glutMainLoop();

	return 0;
}