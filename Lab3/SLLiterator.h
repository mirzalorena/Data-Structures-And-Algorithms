#pragma once
#include "SLL.h"
#include "MultiMap.h"

//typedef int TElem;

class SLLiterator
{
private:
	SLL sll;
	node* current;

public:
	SLLiterator() {};
	void init(SLL sll);
	TElement getCurrent();
	void next();
	bool valid();

	~SLLiterator() {};

};

