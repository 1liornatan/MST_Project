#pragma once
#include "AdjListNode.h"

class AdjList {
	AdjListNode* head;

public:

	AdjList() {
		head = nullptr;
	}

	bool isEmpty() const;
	void insert(AdjListNode* node);
	void remove(AdjListNode* node);
	void remove(int v);
	AdjListNode* getHead() const;
};