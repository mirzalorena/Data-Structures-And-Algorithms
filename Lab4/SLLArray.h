#pragma once

#include "DynamicVector.h"

typedef int TElem;

class SLLArray
{
private:
	int firstEmpty;
	int capacity;
	int head;
	int next[100];
	//DynamicVector<int> next;
	TElem elems[100];
	//DynamicVector<TElem> elems;



public:
	SLLArray();
	~SLLArray() {}
	int getHead() const { return this->head; }
	int getFirstEmpty() { return this->firstEmpty; }
	int size() const;
	bool search(TElem elem);
	void insertFirst(TElem elem);
	void insertEnd(TElem elem);
	void insertAtPosition(int pos, TElem elem);
	void deleteElement(TElem elem);
	void deleteElementEnd(TElem elem);
	TElem getFromPosition(int pos) const { return this->elems[pos]; }



};