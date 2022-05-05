#include "PrimPair.h"

void PrimPair::freeMemory()
{
	int pairArrSize;

	if (min) {
		pairArrSize = sizeof(min) / sizeof(min[0]);

		for (int i = 0; i < pairArrSize; i++) {
			if (min[i])
				delete min[i];
		}
		delete min;
	}
	if (p)
		delete p;
}
