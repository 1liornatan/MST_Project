#include "DisjointSets.h"

void DisjointSets::MakeSet(int x)
{
	A[x].parent = x;
	A[x].size = 1;
}

int DisjointSets::Find(int x) {  // + Path Comprassion
	if (A[x].parent == x)
		return x;

	return (A[x].parent = Find(A[x].parent));
}

void DisjointSets::Union(int repx, int repy) { // + Union By Size
	if (A[repx].size > A[repy].size) {
		A[repy].parent = repx;
		A[repx].size += A[repy].size;
	}
	else {
		A[repx].parent = repy;
		A[repy].size += A[repx].size;
	}
}

