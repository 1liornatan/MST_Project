#include "MinHeap.h"


void MinHeap::Insert(Pair* p) {
	int i;
	last++;
	pairArr[last] = p;
	posArr[p->data] = last;

	i = last; 

	while (i > 0 && (p->key < pairArr[Parent(i)]->key)) { /* puts new pair as last and starts pushing it top */
		Swap(i, Parent(i));
		i = Parent(i);
	}
}

void MinHeap::empty() {
	for (int i = 0; i < last; i++) {
		delete pairArr[i];
		pairArr[i] = nullptr;
		posArr[i] = -1;
	}
	last = -1;
}

void MinHeap::Build(Pair** arr, int n)
{
	// clear heap
	empty();
	delete pairArr;
	delete posArr;

	// build heap
	pairArr = new Pair * [n];
	last = n-1;
	size = n;
	posArr = new int[n];

	for (int i = 0; i < n; i++) {
		pairArr[i] = arr[i];
		posArr[i] = i;
	}

	for (int i = (n / 2) - 1; i >= 0; i--)
		FixHeap(i);

}
bool MinHeap::isEmpty() const
{
	return last == -1;
}
void MinHeap::DecreaseKey(int place, int newKey)
{
	int pos = posArr[place];
	pairArr[pos]->key = newKey;
	FixHeapUp(pos);
}
int MinHeap::Parent(int child) {
	return (child - 1) / 2;
}

int MinHeap::Left(int parent) {
	return (parent * 2 + 1);
}

int MinHeap::Right(int parent) {
	return (parent * 2 + 2);
}

Pair* MinHeap::Min() {
	if (last < 0)
		return nullptr;

	return pairArr[0];
}

void MinHeap::Swap(int i, int j) {
	Pair* temp = pairArr[i];
	pairArr[i] = pairArr[j];
	pairArr[j] = temp;

	posArr[pairArr[i]->data] = i;
	posArr[pairArr[j]->data] = j;
}

void MinHeap::FixHeap(int node) {
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

void MinHeap::FixHeapUp(int node) {
	int parent = Parent(node);

	if (parent >= 0 && pairArr[node]->key < pairArr[parent]->key) {
		Swap(node, parent);
		FixHeapUp(parent);
	}
}



Pair* MinHeap::DeleteMin() {
	if (last < 0)
		return nullptr;

	Pair* min = pairArr[0];

	Swap(0, last);
	last--;

	FixHeap(0);

	return min;
}

void MinHeap::Delete(int i) {
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