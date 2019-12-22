#pragma once
#include "SLL.h"
#include "MultiMap.h"

//typedef TElem;

class MultiMapIterator {
	const MultiMap &map;
	int currentPosition;
	MultiMapNode* currentNode;


public:
	MultiMapIterator(const MultiMap &map);
	~MultiMapIterator() {}
	//MultiMapIterator(SLL list);
	bool valid();
	void next();
	void first();
	TElem getCurrent();
};
