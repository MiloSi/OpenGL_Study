

#include "image_mesh.h"



int main(int argc, char** argv) {
	glutInit(&argc, (char**)argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);


	windowID = glutCreateWindow("IMAGE MESH");

	glutIdleFunc(reDisplay);
	glutMouseFunc(mouseHandler);
	glutMotionFunc(motionHandler);
	glutKeyboardFunc(keyboardHandler);

	glutDisplayFunc(display);

	init();
	glutMainLoop();

	return 0;
}