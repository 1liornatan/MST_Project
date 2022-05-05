#include "MST.h"

std::vector<Edge*>* MST::Kruskal(WeightedGraph& G)
{
	quickSortInit(G);

	return KruskalIteration(G);
}

void MST::initPrim(bool* inT, PrimPair* primPair, int size) {
	int* p = primPair->p;
	Pair** minWeight = primPair->min;

	for (int i = 0; i < size; i++) {
		inT[i] = false;
		p[i] = -1;

		minWeight[i] = new Pair();
		minWeight[i]->data = i;

	}

	minWeight[0]->key = 0;
}
PrimPair* MST::Prim(WeightedGraph& G) {

	if (!G.isConnected())
		throw NotConnectedException();

	int n = G.getSize();
	int u, v;

	WeightKey w;
	AdjListNode* currNode;

	MinHeap priorityQueue(n);

	bool* inT = new bool[n];
	Pair** minWeight = new Pair*[n];
	int* p = new int[n];

	PrimPair* primPair = new PrimPair(minWeight, p);
	
	initPrim(inT, primPair, n);
	priorityQueue.Build(minWeight, n);


	while (!priorityQueue.isEmpty()) {
		u = priorityQueue.DeleteMin()->data;
		inT[u] = true;

		currNode = G.getAdjlist(u)->getHead();
		
		while (currNode != nullptr) {
			v = currNode->getNeighbor();
			w = currNode->getEdgeWeight();

			if (!inT[v] && w < minWeight[v]->key) {
				minWeight[v]->key = w;
				p[v] = u;
				priorityQueue.DecreaseKey(v, w.getKey());

			}
			currNode = currNode->getNext();
		}
	}

	delete[] inT;

	return primPair;
}

std::vector<Edge*>* MST::KruskalIteration(WeightedGraph& G) {

	if (!G.isConnected())
		throw NotConnectedException();

	std::vector<Edge*>* F = new std::vector<Edge*>();
	std::vector<Edge*>* L;

	DisjointSets UF(G.getSize());

	int u1, v1, u2, v2;

	L = G.getEdgeSet();

	int sizeOfV = G.getSize();

	for (int i = 0; i < sizeOfV; i++) {
		UF.MakeSet(i);
	}

	for (auto& itr : *L) {
		u1 = itr->getU();
		v1 = itr->getV();

		u2 = UF.Find(u1);
		v2 = UF.Find(v1);

		if (u2 != v2) {
			F->push_back(itr);
			UF.Union(u2, v2);
		}
	}

	return F;
}


void MST::quickSortInit(WeightedGraph& G)
{
	std::vector<Edge*>* E = G.getEdgeSet();
	quickSort(E, 0, (*E).size() - 1);
}

void MST::quickSort(std::vector<Edge*>* E, int left, int right) {
	int pivot;

	if (left < right) {
		pivot = partition(E, left, right);
		quickSort(E, left, pivot - 1);
		quickSort(E, pivot + 1, right);
	}
}

int MST::partition(std::vector<Edge*>* E, int pLeft, int pRight) {

	WeightKey pivot = (*E)[pLeft]->getC();

	int count = 0;

	for (int i = pLeft + 1; i <= pRight; i++) {
		if ((*E)[i]->getC() <= pivot)
			count++;
	}

	// Giving pivot element its correct position
	int pivotIndex = pLeft + count;
	swap(pivotIndex, pLeft, E);

	// Sorting left and right parts of the pivot element
	int i = pLeft, j = pRight;

	while (i < pivotIndex && j > pivotIndex) {

		while ((*E)[i]->getC() <= pivot) {
			i++;
		}

		while ((*E)[j]->getC() > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(i++, j--, E);
		}
	}

	return pivotIndex;
}

int MST::sumMST(std::vector<Edge*>* F)
{
	int sum = 0;

	std::vector<Edge*> E = *F;

	for (auto& itr : E) {
		sum = sum + itr->getC().getKey();
	}

	return sum;
}

int MST::sumMST(PrimPair* a, int n)
{
	int sum = 0;

	if (a->min) {
		for (int i = 0; i < n; i++) {
			sum += a->min[i]->key.getKey();
		}
	}

	return sum;
}

void MST::swap(int i, int j, std::vector<Edge*>* E) {
	Edge* temp = (*E)[i];
	(*E)[i] = (*E)[j];
	(*E)[j] = temp;
}
