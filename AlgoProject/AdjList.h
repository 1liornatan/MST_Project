#pragma once
#include "AdjListNode.h"

class AdjList {
	AdjListNode* head;

public:

	AdjList() {
		head = nullptr;
	}

	~AdjList() {
		AdjListNode* nodeSaver;
		while (head != nullptr) {
			nodeSaver = head;
			head = head->getNext();

			delete nodeSaver;
		}
	}

	AdjList& operator=(const AdjList&) = delete;

	bool isEmpty() const;
	void insert(AdjListNode* node);
	void remove(AdjListNode* node);
	void remove(int v);
	AdjListNode* getHead() const;
};