#pragma once

#include "Pair.h"

/* an implementation for a min heap using a dynamic array of pointers */

class minHeap {
	Pair** pairArr;
	int size, last;

public:

	minHeap() = delete;
	minHeap(int _size) {
		pairArr = new Pair * [_size];
		size = _size;
		last = -1;
	}

	~minHeap() {
		delete[] pairArr;
	}

	minHeap& operator=(const minHeap& p) = delete;

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
	int Parent(int child);
	int Left(int parent);
	int Right(int parent);
	void Swap(int i, int j);
};
