#include <iostream>
#include "InputManager.h"

/* the program receives a file path in the first argument
   the file contains input as showed in the examples
   if the input is invalid a message will be received
   otherwise, an MST will be calculated (if exists)  */

int main(int argc, char* argv[])
{
	if (argc <= 1)
		std::cout << "no file argument received" << std::endl;
	else {
		InputManager input(argv[1]);

		input.start();
	}
}