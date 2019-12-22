#pragma once
#include "Bag.h"


//class Bag;

class BagIterator
{
	friend class Bag;

private:
	const Bag& b;
	TElem element;
	int position;
	DynamicArray* copyFreq;

	BagIterator(const Bag& b);

public:
	TElem getCurrent();
	bool valid();
	void next();
	void first();





};