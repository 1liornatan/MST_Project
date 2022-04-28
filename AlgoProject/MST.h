#pragma once

#include <iostream>
#include <vector>
#include "Edge.h"
#include "DisjointSets.h"
#include "WeightedGraph.h"

class MST {

public:
	static std::vector<Edge*>* Kruskal(WeightedGraph& G);

private:
	static void quickSortInit(WeightedGraph& G, std::vector<Edge*>& E);
	static void quickSort(std::vector<Edge*>& E, int left, int right);
	static void addAdjToList(int v, AdjList* adjList, std::vector<Edge*>& L);
	static void swap(int i, int j, std::vector<Edge*>& E);
	static int partition(std::vector<Edge*>& E, int size);
};