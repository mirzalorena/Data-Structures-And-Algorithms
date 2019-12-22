#pragma once

class Bag;

typedef int TElem;
typedef int TKey;

struct Node {
	TKey key;
	Node *next;
};

class BagIterator
{
	friend class Bag;

private:
	const Bag& bag;

	int position;
	Node* currentNode;


public:
	//BagIterator();
	void init(Bag &bag);
	TElem getCurrent();
	bool valid();
	void next();
	void first();
};

