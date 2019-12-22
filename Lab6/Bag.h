#pragma once

#include "BagIterator.h"
#include <utility>
#include <vector>

typedef int TElem;

using namespace std;


typedef struct Node {
	TElem info;
	Node* next;
};


class Bag {

private:

	int m=8;
	Node** arr; //an array of pointers to nodes
	int hash(TElem e) const;
	void rehash();

	int sizeBag;

	void addToPosition(int pos, TElem e);
	bool removeFromPosition(int pos, TElem e);

public:

	//constructor

	Bag();

	

	//void resize();

	//adds an element to the bag

	void add(TElem e);



	//removes one occurrence of an element from a bag

	//returns true if an element was removed, false otherwise (if e was not part of the bag)

	bool remove(TElem e);



	//checks if an element appearch is the bag

	bool search(TElem e) const;



	//returns the number of occurrences for an element in the bag

	int nrOccurrences(TElem e) const;



	//returns the number of elements from the bag

	int size() const;



	//returns an iterator for this bag

	BagIterator iterator() const;



	//checks if the bag is empty

	bool isEmpty() const;



	//destructor

	~Bag();

};