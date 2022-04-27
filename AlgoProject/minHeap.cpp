#include "minHeap.h"


void minHeap::Insert(Pair* p) {
	int i;
	last++;
	pairArr[last] = p;

	i = last;

	while (i > 0 && (pairArr[Parent(i)]->key > p->key)) { /* puts new pair as last and starts pushing it top */
		Swap(i, Parent(i));
		i = Parent(i);
	}
}

void minHeap::empty() {
	for (int i = 0; i < last; i++) {
		delete pairArr[i];
		pairArr[i] = nullptr;
	}
	last = -1;
}

void minHeap::Build(Pair** arr, int n)
{
	// clear heap
	empty();
	delete pairArr;

	// build heap
	pairArr = arr;
	
	for (int i = n / 2 - 1; i >= 0; i--)
		FixHeap(i);

}
bool minHeap::isEmpty() const
{
	return last == -1;
}
void minHeap::DecreaseKey(int place, int newKey)
{
	pairArr[place]->key = newKey;
	FixHeap(place);
}
int minHeap::Parent(int child) {
	return (child - 1) / 2;
}

int minHeap::Left(int parent) {
	return (parent * 2 + 1);
}

int minHeap::Right(int parent) {
	return (parent * 2 + 2);
}

Pair* minHeap::Min() {
	if (last < 0)
		return nullptr;

	return pairArr[0];
}

void minHeap::Swap(int i, int j) {
	Pair* temp = pairArr[i];
	pairArr[i] = pairArr[j];
	pairArr[j] = temp;

}
void minHeap::FixHeap(int node) {
	int min;
	int left = Left(node);
	int right = Right(node);

	if ((left <= last) && (pairArr[left]->key < pairArr[node]->key)) {
		min = left;
	}
	else {
		min = node;
	}

	if (right <= last && (pairArr[right]->key < pairArr[min]->key)) {
		min = right;
	}

	if (min != node) {
		Swap(node, min);
		FixHeap(min);
	}
}


Pair* minHeap::DeleteMin() {
	if (last < 0)
		return nullptr;

	Pair* min = pairArr[0];

	Swap(0, last);
	last--;

	FixHeap(0);

	return min;
}

int minHeap::numOfVals() const {
	return last + 1;
}

void minHeap::Delete(int i) {
	if (i > last)
		return;
	else if (last == i) { // last item
		pairArr[i] = nullptr;
		last--;
	}
	else {
		Swap(i, last);
		last--;
		FixHeap(i);
	}
}