#pragma once

class WeightKey {
	bool isInfinite;
	int key;

public:
	WeightKey(int _key) : key(_key), isInfinite(false) {};
	WeightKey() : key(0), isInfinite(true) {};

	bool getIsInfinite() const;
	int getKey() const;

	void setKey(int _key);


	friend bool operator<(const WeightKey& k1, const WeightKey& k2) {
		if (k1.isInfinite && !k2.isInfinite) {
			return false;
		}
		else if (!k1.isInfinite && k2.isInfinite) {
			return true;
		}
		else if (!k1.isInfinite && !k2.isInfinite) {
			return k1.key < k2.key;
		}
		else {
			return false;
		}
	}

	friend bool operator <=(const WeightKey& k1, const WeightKey& k2) {
		return (k1 < k2 || k1 == k2);
	}

	friend bool operator>(const WeightKey& k1, const WeightKey& k2) {
		return k2 < k1;
	}

	WeightKey& operator=(const int& a) {
		key = a;
		isInfinite = false;

		return *this;
	}

	friend bool operator==(const WeightKey& k1, const WeightKey& k2) {
		if (k1.isInfinite && k2.isInfinite)
			return true;
		else if (k1.isInfinite != k2.isInfinite)
			return false;
		else {
			return k1.key == k2.key;
		}
	}

	friend bool operator!=(const WeightKey& k1, const WeightKey& k2) {
		return !(k1 == k2);
	}

};