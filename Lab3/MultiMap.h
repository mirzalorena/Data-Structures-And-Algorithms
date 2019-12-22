#pragma once

#include<string>
//#include "Iterator.h"
#include "SLL.h"
#include<utility>
#include <vector>

using namespace std;
typedef int TKey;
typedef int TValue;

typedef std::pair<TKey, TValue> TElem;

class MultiMapIterator;

struct MultiMapNode{
	SLL values;
	MultiMapNode* next;
	TKey key;
};

class MultiMap

{
	friend class MultiMapIterator;
private:

	/* representation of the MultiMap */
	//SLL sll;
	MultiMapNode* head;


public:

	//constructor

	MultiMap();
	void add(TKey key, TValue value);

	bool remove(TKey key, TValue value);

	int size() const;

	bool isEmpty() const;

	vector<TValue> search(TKey c) const;

	int getValueRange() const;

	MultiMapIterator iterator() const;



	//descturctor
	~MultiMap() {};





};




