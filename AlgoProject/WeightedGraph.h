#pragma once
#include "AdjList.h"
#include <vector>
#include "Edge.h"
#include "DFS.h"

class DFS;

class WeightedGraph {

	int size;
	AdjList** adjListArr;
	std::vector<Edge*>* E;

public:

	WeightedGraph() {
		size = 0;
		adjListArr = nullptr;
		E = nullptr;
	}

	~WeightedGraph() {
		removeGraph();
	}

	WeightedGraph& operator=(const WeightedGraph&) = delete;

	void makeEmptyGraph(int n);
	bool isAdjacent(int u, int v) const;
	AdjList* getAdjlist(int u) const;
	void addEdge(int u, int v, const WeightKey& c); // c = weight
	void removeEdge(int u, int v);
	int getSize() const;
	void setEdgeSet(std::vector<Edge*>* edgeSet);
	std::vector<Edge*>* getEdgeSet() const;
	bool isConnected() const;

private:
	void removeGraph();
};