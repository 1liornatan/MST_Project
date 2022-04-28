#pragma once

#include <iostream>

class Edge {
	int v, u, c;

public:
	
	Edge(int _v, int _u, int _c) : v(_v), u(_u), c(_c) {};

	int getV() const;
	int getU() const;
	int getC() const;
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