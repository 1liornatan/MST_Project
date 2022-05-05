#pragma once
#include "WeightedGraph.h"

class WeightedGraph;

class DFS {

	enum Colors {
		WHITE,
		GRAY,
		BLACK
	};

	const WeightedGraph& G;
	Colors* Color;
	int vertexVisited;
	int size;

public:

	DFS(const WeightedGraph& _G);


	~DFS() {
		delete[] Color;
	}


	int getVisited() const;
	void Visit(int u);
	void init();

};