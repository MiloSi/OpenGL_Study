#pragma once
#include <stdlib.h>
#include <gl/glut.h>
#include <gl/glu.h>
#include <gl/gl.h>

class TEAPOT {

public :
	TEAPOT();
	TEAPOT(int argc, char** argv);
	GLboolean setWindowSize(const GLint& , const GLint& );
	GLboolean setWindowPosition(const GLint& , const GLint& );
	GLboolean setTimer(const GLint );
	GLboolean show();


	static GLint width;
	static GLint height;


private:
	//void display();
	//void timer(const GLint);
	void init();
	GLint position_x;
	GLint position_y;
	GLint time;

	GLboolean isSetSize = false;
	GLboolean isSetPosition = false;
	GLboolean isSetTimer = false;

};
enum {WHITE, BLACK, EXIT};

void menu(const GLint);
void display();
void timer(const GLint);