#include "MST.h"

std::vector<Edge*>* MST::Kruskal(WeightedGraph& G)
{
	std::vector<Edge*>* ptrF = new std::vector<Edge*>;
	std::vector<Edge*> F = *ptrF;
	std::vector<Edge*> L;

	DisjointSets UF;

	int u1, v1, u2, v2;


	quickSortInit(G, L);

	int sizeOfV = G.getSize();

	for (int i = 0; i < sizeOfV; i++) {
		UF.MakeSet(i);
	}

	for (auto& itr : L) {
		u1 = itr->getU();
		v1 = itr->getV();

		u2 = UF.Find(u1);
		v2 = UF.Find(v1);

		if (u2 != v2) {
			F.push_back(itr);
			UF.Union(u2, v2);
		}
	}

	return ptrF;

}

void MST::quickSortInit(WeightedGraph& G, std::vector<Edge*>& E)
{
	int n = G.getSize();

	for (int i = 0; i < n; i++) {
		addAdjToList(i, G.getAdjlist(i), E);
	}

	quickSort(E, 0, E.size() - 1);
}

void MST::quickSort(std::vector<Edge*>& E, int left, int right) {
	int pivot;

	if (left < right) {
		pivot = partition(E, E.size());
		quickSort(E, left, pivot - 1);
		quickSort(E, pivot + 1, right);
	}
}

int MST::partition(std::vector<Edge*>& E, int size) {
	int pivot = E[0]->getC();
	int left, right, cLeft, cRight;

	for (left = 1, right = size - 1; left < right; )
	{
		cLeft = E[left]->getC();
		cRight = E[right]->getC();

		if (cLeft > pivot && cRight <= pivot)
		{
			swap(left, right, E);
		}

		if (cLeft <= pivot) left++;
		if (cRight > pivot) right--;
	}

	return left;
}

void MST::swap(int i, int j, std::vector<Edge*>& E) {
	Edge* temp = E[i];
	E[i] = E[j];
	E[j] = temp;
}


void MST::addAdjToList(int v, AdjList* adjList, std::vector<Edge*>& L)
{
	AdjListNode* currNode = adjList->getHead();

	while (currNode != nullptr) {
		L.push_back(new Edge(v, currNode->getNeighbor(), currNode->getEdgeWeight()));

		currNode = currNode->getNext();
	}
}

