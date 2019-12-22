#pragma once
#include <utility>

using namespace std;

typedef int TElem;
typedef int TPriority;
typedef std::pair<TElem, TPriority> Element;
typedef bool(*Relation)(TPriority p1, TPriority p2);
typedef struct heap {
	int capacity;
	int length;
	Element* elements;
};
class SecondPriorityQueue
{
private:
	//representation of the SecondPiorityQueue
	Relation rel;
	heap heap;

public:
	//implicit constructor
	SecondPriorityQueue(Relation r);
	void print();
	//adds an element with a priority to the queue
	void push(TElem e, TPriority p);

	//returns the element with the second highest priority with respect to the relation
   //throws exception if the queue has less than 2 elements
	Element top()  const;

	void add(Element);
	void bubbleup(int);

	//removes and returns the element with the second highest priority
	//throws exception if the queue has less than 2 elements
	Element pop();

	void bubbleDown(int);

	//Element getElementToRemove();
	//checks if the queue has at most one element
	bool atMostOne() const;

	//destructor
	~SecondPriorityQueue();
};

