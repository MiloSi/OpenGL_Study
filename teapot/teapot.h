#pragma once
#include <gl/glut.h>
#include <gl/glu.h>
#include <gl/gl.h>

class TEAPOT {

public :
	TEAPOT(int argc, char** argv);
	GLboolean setWindowSize(const GLint& , const GLint& );
	GLboolean setWindowPosition(const GLint& , const GLint& );
	GLboolean setTimer(const GLint );
	GLboolean show();



private:
	//void display();
	//void timer(const GLint);
	void init();



	GLint width;
	GLint height;

	GLint position_x;
	GLint position_y;
	GLint time;

	GLboolean isSetSize = false;
	GLboolean isSetPosition = false;
	GLboolean isSetTimer = false;

};

void display();
void timer(const GLint);