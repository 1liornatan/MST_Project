#include "WeightedGraph.h"

void WeightedGraph::makeEmptyGraph(int n)
{
	removeGraph();

	adjListArr = new AdjList * [n];

	for (int i = 0; i < n; i++) {
		adjListArr[i] = new AdjList;
	}

	size = n;

	E = new std::vector<Edge*>();
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

void WeightedGraph::addEdge(int u, int v, const WeightKey& c)
{
	AdjListNode* UVNode = new AdjListNode(v, c);
	AdjListNode* VUNode = new AdjListNode(u, c);

	adjListArr[u]->insert(UVNode);
	adjListArr[v]->insert(VUNode);

	E->push_back(new Edge(u, v, WeightKey(c)));
}

void WeightedGraph::removeEdge(int u, int v)
{
	adjListArr[u]->remove(v);
	adjListArr[v]->remove(u);

	for (auto it = E->begin(); it != E->end();) {
		auto& itr = *it;
		if ((itr->getU() == u && itr->getV() == v) || (itr->getU() == v && itr->getV() == u))
			it = E->erase(it);
		else
			++it;

	}
}

int WeightedGraph::getSize() const
{
	return size;
}

void WeightedGraph::setEdgeSet(std::vector<Edge*>* edgeSet)
{
	E = edgeSet;
}

std::vector<Edge*>* WeightedGraph::getEdgeSet() const
{
	return E;
}

bool WeightedGraph::isConnected() const
{
	DFS ObjectDFS(*this);

	ObjectDFS.init();

	ObjectDFS.Visit(1);

	return (ObjectDFS.getVisited() == size);
}

void WeightedGraph::removeGraph()
{
	if (adjListArr) {
		for (int i = 0; i < size; i++) {
			if(adjListArr[i])
				delete adjListArr[i];
		}

		delete adjListArr;
	}

	if (E) {

		for (auto& itr : *E)
			if(itr)
				delete itr;

		delete E;
	}
}
