#pragma once

#include <iostream>
#include <fstream>
#include "InputMismatch.h"
#include "NoFileException.h"
#include "WeightedGraph.h"
#include "MST.h"



class InputManager {

	WeightedGraph G;
	std::ifstream fp;

public:

	InputManager(std::string _fileName): fp(_fileName) {

		if (!fp)
			throw NoFileException();
	}

	~InputManager() {
		if (fp)
			fp.close();
	}

	int getInt();
	void start();
	void getEdges();

	InputManager operator=(const InputManager& a) = delete;
};