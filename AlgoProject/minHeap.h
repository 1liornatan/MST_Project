#pragma once

#include "Pair.h"

/* an implementation for a min heap using a dynamic array of pointers */

class MinHeap {
	Pair** pairArr;
	int* posArr;
	int size, last;

public:

	MinHeap() = delete;
	MinHeap(int _size) {
		pairArr = new Pair * [_size];
		size = _size;
		last = -1;
		posArr = new int[_size];
	}

	~MinHeap() {
		if(posArr)
			delete posArr;

		if(pairArr)
			delete pairArr;
	}

	MinHeap& operator=(const MinHeap& p) = delete;

	void Insert(Pair* p);
	Pair* DeleteMin();
	Pair* Min();
	void Delete(int i);
	void Build(Pair** arr, int n);
	bool isEmpty() const;
	void DecreaseKey(int place, int newKey);

private:
	void empty();
	void FixHeap(int node);
	void FixHeapUp(int node);
	int Parent(int child) const;
	int Left(int parent) const;
	int Right(int parent) const;
	void Swap(int i, int j);
};
