#include "AdjList.h"

bool AdjList::isEmpty() const
{
	return head == nullptr;
}

void AdjList::insert(AdjListNode* node)
{
	AdjListNode* currNode = head, * currNodeSaver = head;
	if (isEmpty())
		head = node;
	else {
		while (currNode != nullptr) {
			currNodeSaver = currNode;
			currNode = currNode->getNext();
		}
		currNodeSaver->setNext(node);
	}
}

void AdjList::remove(AdjListNode* node)
{
	AdjListNode* currNode = head;
	AdjListNode* currNodeSaver = head;

	if (node == nullptr)
		return;
	else if (node == head) {
		head = head->getNext();
		delete currNode;
	}
	else {
		while (currNode != node && currNode != nullptr) {
			currNodeSaver = currNode;
			currNode = currNode->getNext();
		}

		if (currNode != nullptr) {
			currNodeSaver->setNext(currNode->getNext());
			delete currNode;
		}
	}
}


void AdjList::remove(int v) {
	AdjListNode* currNode = head;
	
	while (currNode != nullptr) {
		if (currNode->getNeighbor() == v) {
			remove(currNode);
			break;
		}
		currNode = currNode->getNext();
	}
}

AdjListNode* AdjList::getHead() const
{
	return head;
}


