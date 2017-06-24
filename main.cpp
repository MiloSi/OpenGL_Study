#include "teapot.h"
#include <Windows.h>

/*
int main(int argc, char** argv)
{
	TEAPOT teapot(argc, argv);

	teapot.setWindowPosition(0, 0);
	teapot.setWindowSize(800, 800);
	teapot.show();

	return 0;

}*/
int APIENTRY WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR lpzCmdParam, int nCmdeShow) {
	TEAPOT *teapot = new TEAPOT();

	teapot->setWindowPosition(0, 0);
	teapot->setWindowSize(800, 800);
	teapot->show();

	return 0;

	delete teapot;
}
