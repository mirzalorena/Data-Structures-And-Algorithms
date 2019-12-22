#pragma once
#include <string>
#include <iostream>
#include <algorithm>
//#include "SLLiterator.h"

typedef int TElement;

using namespace std;

class SLLiterator;
class MultiMap;

struct node
{
	TElement data;
	node *next;
};

class SLL
{
private:
	node* head;

public:
	SLL();
	~SLL() {}
	node* getHead() const { return this->head; };
	node* search(TElement elem);
	void insertFirst(TElement data);
	void insertAfter(node* currentNode, TElement elem);
	void insertPosition(int position, TElement elem);
	node* getNodeFromPosition(int position);
	void deleteElement(TElement elem);
	int size();

	SLLiterator iterator() const;





};