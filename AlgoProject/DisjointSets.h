#pragma once
#include "Element.h"

class DisjointSets {
	Element* A;
	int size;

public:
	DisjointSets(int _size): size(_size) {
		A = new Element[size];

		for (int i = 0; i < size; i++) {
			A[i].parent = -1;
			A[i].size = 0;
		}
	}

	~DisjointSets() {
		delete A;
	}

	DisjointSets& operator=(const DisjointSets &) = delete;

	void MakeSet(int x);
	int Find(int x);
	void Union(int repx, int repy);
};