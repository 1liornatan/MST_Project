#include "WeightedGraph.h"

void WeightedGraph::makeEmptyGraph(int n)
{
	adjListArr = new AdjList * [n];

	for (int i = 0; i < n; i++) {
		adjListArr[i] = new AdjList;
	}

	size = n;
}

bool WeightedGraph::isAdjacent(int u, int v) const
{
	bool areAdjacent = false;
	
	AdjListNode* currEdge = adjListArr[u]->getHead();

	do {
		if (currEdge->getNeighbor() == v) {
			areAdjacent = true;
			break;
		}
		currEdge = currEdge->getNext();
	} while (currEdge != nullptr);

	return areAdjacent;
}

AdjList* WeightedGraph::getAdjlist(int u) const
{
	return adjListArr[u];
}

void WeightedGraph::addEdge(int u, int v, int c)
{
	AdjListNode* UVNode = new AdjListNode(v, c);
	AdjListNode* VUNode = new AdjListNode(u, c);

	adjListArr[u]->insert(UVNode);
	adjListArr[v]->insert(VUNode);
}

void WeightedGraph::removeEdge(int u, int v)
{
	adjListArr[u]->remove(v);
	adjListArr[v]->remove(u);
}
