#include "DFS.h"


void DFS::init() {
	for (int i = 0; i < size; i++)
		Color[i] = WHITE;

	vertexVisited = 0;
}


void DFS::Visit(int u) {
	int v;

	Color[u] = GRAY;

	AdjListNode* adj = G.getAdjlist(u)->getHead();

	while (adj != nullptr) {
		v = adj->getNeighbor();
		if (Color[v] == WHITE) {
			Visit(v);
		}
		adj = adj->getNext();
	}
	Color[u] = BLACK;
	vertexVisited++;
}

int DFS::getVisited() const {
	return vertexVisited;
}

DFS::DFS(const WeightedGraph& _G) : G(_G) {
	vertexVisited = 0;
	size = G.getSize();
	Color = new Colors[size];
}