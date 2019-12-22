#pragma once
#include "DynamicArray.h"
typedef int TElem;
class DynamicArray;

class DAIterator
{
	friend class DynamicArray;

private:
	//the iterator stores a reference to the container 
	const DynamicArray& da;
	int position;
	DAIterator(const DynamicArray& c);

public:
	bool valid();
	void next();
	void first();
	TElem getCurrent();
};
