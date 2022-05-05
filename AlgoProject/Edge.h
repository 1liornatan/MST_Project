#pragma once

#include <iostream>
#include "WeightKey.h"

class Edge {
	int v, u;

	WeightKey c;

public:
	
	Edge(int _u, int _v, const WeightKey & _c) : v(_v), u(_u), c(_c) {};

	int getV() const;
	int getU() const;
	WeightKey getC() const;
	void setV(int v);
	void setU(int u);
	void setC(int c);

	bool operator==(const Edge& e) const {
		return (e.c != c) && (((e.v == v) && (e.u == u)) || ((e.v == u) && (e.u == v)));
	}

	bool operator!=(const Edge& e) const {
		return !(e == *this);
	}
};