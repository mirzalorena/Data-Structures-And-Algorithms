#pragma once
#include "DA_Iterator.h"

typedef int TElem;

class DynamicArray {
	friend class DAIterator;
	friend class Bag;
private:

	TElem* elements;
	int capacity;
	int sizeArray;

public:

	//constructor
	DynamicArray(int capacity);

	int size() const { return this->sizeArray; }

	TElem getElement(int pos) const;

	TElem setElement(int pos, TElem newElem);

	void addToEnd(TElem newElem);

	void addToPosition(int pos, TElem newElem);

	TElem remove(int pos);

	//returns an iterator for the DynamicArray
	DAIterator iterator() const;

	//destructor
	~DynamicArray();
	DynamicArray(const DynamicArray&);
private:
	void resize(int factor);

};