#pragma once

#include <iostream>
#include <vector>
#include "Edge.h"
#include "DisjointSets.h"
#include "WeightedGraph.h"
#include "NotConnectedException.h"
#include "MinHeap.h"
#include "PrimPair.h"

class MST {

public:
	static std::vector<Edge*>* Kruskal(WeightedGraph& G);
	static PrimPair* Prim(WeightedGraph& G);
	static std::vector<Edge*>* KruskalIteration(WeightedGraph& G);
	static int sumMST(std::vector<Edge*>* E);
	static int sumMST(PrimPair* a, int n);

private:
	static void quickSortInit(WeightedGraph& G);
	static void quickSort(std::vector<Edge*>* E, int left, int right);
	static void swap(int i, int j, std::vector<Edge*>* E);
	static int partition(std::vector<Edge*>* E, int pLeft, int pRight);
	static void initPrim(bool* inT, PrimPair* primPair, int size);
};