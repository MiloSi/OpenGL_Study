
/*
	Created by Milo Si.
	To studied OpenGL
*/
#include <Windows.h>
#include "solarsystem.h"


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow) {
	SolarSystem* solar =  new SolarSystem();
	solar->showWindow();


	delete solar;
	return 0;
}
