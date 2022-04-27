#pragma once
#include "AdjList.h"

class WeightedGraph {

	int size;
	AdjList** adjListArr;

public:

	WeightedGraph() {
		size = 0;
		adjListArr = nullptr;
	}

	void makeEmptyGraph(int n);
	bool isAdjacent(int u, int v) const;
	AdjList* getAdjlist(int u) const;
	void addEdge(int u, int v, int c); // c = weight
	void removeEdge(int u, int v);
};