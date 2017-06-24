#include "teapot.h"


int main(int argc, char** argv)
{
	TEAPOT teapot(argc, argv);

	teapot.setWindowPosition(0, 0);
	teapot.setWindowSize(400, 400);
	teapot.show();

	return 0;

}