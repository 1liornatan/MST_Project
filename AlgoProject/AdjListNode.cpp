#include "AdjListNode.h"

void AdjListNode::setEdgeWeight(int edgeWeight)
{
	this->edgeWeight = edgeWeight;
}

void AdjListNode::setNeighbor(int neighbor)
{
	this->neighbor = neighbor;
}

int AdjListNode::getNeighbor() const
{
	return neighbor;
}

WeightKey& AdjListNode::getEdgeWeight()
{
	return edgeWeight;
}

AdjListNode* AdjListNode::getNext() const
{
	return next;
}

void AdjListNode::setNext(AdjListNode* node)
{
	next = node;
}
