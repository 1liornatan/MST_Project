#include "Edge.h"

int Edge::getV() const
{
    return v;
}

int Edge::getU() const
{
    return u;
}

WeightKey Edge::getC() const
{
    return c;
}

void Edge::setC(int c) {
    this->c = c;
}

void Edge::setV(int v) {
    this->v = v;
}

void Edge::setU(int u) {
    this->u = u;
}