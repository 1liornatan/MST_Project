#pragma once

class AdjListNode {
	AdjListNode* next;
	int neighbor;
	int edgeWeight;

public:
	AdjListNode(int neighbor, int edgeWeight) {
		next = nullptr;
		this->neighbor = neighbor;
		this->edgeWeight = edgeWeight;
	}

	void setEdgeWeight(int edgeWeight);
	void setNeighbor(int neighbor);
	int getNeighbor();
	int getEdgeWeight();
	AdjListNode* getNext();
	void setNext(AdjListNode* node);
};