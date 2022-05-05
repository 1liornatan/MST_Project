#pragma once
#include "Pair.h"

struct PrimPair {
	Pair** min;
	int* p;

	PrimPair(Pair** _min = nullptr, int* _p = nullptr) : min(_min), p(_p) {};

	~PrimPair() {
		freeMemory();
	}

private:
	void freeMemory();


};