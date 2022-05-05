#pragma once
#include "WeightKey.h"

class AdjListNode {
	AdjListNode* next;
	int neighbor;
	WeightKey edgeWeight;

public:
	AdjListNode(int neighbor, const WeightKey& edgeWeight) {
		next = nullptr;
		this->neighbor = neighbor;
		this->edgeWeight = edgeWeight;
	}

	void setEdgeWeight(int edgeWeight);
	void setNeighbor(int neighbor);
	int getNeighbor();
	WeightKey& getEdgeWeight();
	AdjListNode* getNext();
	void setNext(AdjListNode* node);
};