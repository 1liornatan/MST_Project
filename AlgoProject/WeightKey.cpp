#include "WeightKey.h"

bool WeightKey::getIsInfinite() const
{
	return isInfinite;
}

int WeightKey::getKey() const
{
	return key;
}

void WeightKey::setKey(int _key) {
	isInfinite = false;
	key = _key;
}