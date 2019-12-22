#pragma once 
#include "SortedBag.h"

typedef int TComp;
typedef TComp TElem;
typedef bool(*Relation)(TComp, TComp);


class SortedBagIterator
{
private:
	friend class SortedBag;
	TComp element;
	int index;
	SortedBagIterator(const SortedBag& c);
	const SortedBag& sb;
	int* copyFreq;
public:
	void first();
	void next();
	bool valid() const;
	TComp getCurrent() const;
};