#pragma once
#include "DynamicArray.h"
//#include "BagIterator.h"

typedef int TElem;

class BagIterator;

class Bag
{
	friend class BagIterator;
	friend class DynamicArray;

private:
	DynamicArray* elements;
	DynamicArray* freqencies;

public:
	//constructor
	Bag();

	void add(TElem e);

	bool remove(TElem e);

	bool search(TElem e) const;

	int nrOccurences(TElem e) const;

	int sizeArray() const;

	BagIterator iterator() const;

	bool isEmpty() const;

	int elementsWithThisFrequency(int frequency) const;

	//destructor
	~Bag();


};