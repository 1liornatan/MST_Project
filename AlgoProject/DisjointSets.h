#pragma once
#include "Element.h"

const int SETS_MAX_SIZE = 100;

class DisjointSets {

	Element A[SETS_MAX_SIZE];

public:
	DisjointSets() {
		for (int i = 0; i < SETS_MAX_SIZE; i++) {
			A[i].parent = -1;
			A[i].size = 0;
		}
	}

	void MakeSet(int x);
	int Find(int x);
	void Union(int repx, int repy);
};