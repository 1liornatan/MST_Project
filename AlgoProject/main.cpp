#include <iostream>
#include "InputManager.h"

int main(int argc, char* argv[])
{
	InputManager input(argv[1]);

	input.start();
}