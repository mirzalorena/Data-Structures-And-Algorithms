#include "SecondPriorityQueue.h"
#include <iostream>
#include <stdexcept>
using namespace std;

SecondPriorityQueue::SecondPriorityQueue(Relation r) {
	this->rel = r;
	this->heap.elements = new Element[30000];
	this->heap.capacity = 30000;
	this->heap.length = 0;
}

void SecondPriorityQueue::print(){
	for (int i = 1; i <= this->heap.length; i++)
		std::cout << this->heap.elements[i].first << " " << this->heap.elements[i].second << std::endl;

	//theta(1)
}

Element SecondPriorityQueue::top() const{
	if (this->heap.length < 2) {
		throw std::invalid_argument("");
	}
	auto maxChild = -1;
	if (2 <= this->heap.length){
		maxChild = 2 ;
	}
	if (3 <= this->heap.length and this->rel(this->heap.elements[3].second, this->heap.elements[2].second))
		//it has 2 children and the second has higher priority
		maxChild = 3;
	if (4 <= this->heap.length and this->rel(this->heap.elements[4].second, this->heap.elements[maxChild].second))
		//it has 3 children and the third has higher priority
		maxChild = 4;
	return this->heap.elements[maxChild];

	//theta(1)
}

void SecondPriorityQueue::add(Element e)
{
	if (this->heap.length == this->heap.capacity)
	{
		//this->heap.capacity *= 2;
		int newCapacity = this->heap.capacity * 2;
		auto newelements = new Element[this->heap.capacity * 2];
		//memcpy(newelements, this->heap.elements, (size_t)this->heap.capacity * sizeof(Element*));
		std::copy(this->heap.elements + 0, this->heap.elements + this->heap.capacity, newelements + 0);
		//this->heap.capacity *= 2;
		delete[] this->heap.elements;
		this->heap.elements = newelements;
		this->heap.capacity = newCapacity;
	}
	this->heap.elements[this->heap.length+1] = e;
	this->heap.length += 1;
	this->bubbleup(this->heap.length);

	//O(logn)

}

void SecondPriorityQueue::bubbleup(int position)
{
	int poz = position;
	Element elem = this->heap.elements[position];
	int parent = (position + 1) / 3;
	while (poz > 1 && !this->rel(this->heap.elements[parent].second, this->heap.elements[poz].second))
	{
		auto element = this->heap.elements[poz];
		this->heap.elements[poz] = this->heap.elements[parent];
		this->heap.elements[parent] = element;
		poz = parent;
		parent = (poz + 1) / 3;
	}
	this->heap.elements[poz] = elem;

	//O(log2n)

}

void SecondPriorityQueue::push(TElem e, TPriority p)
{
	Element elem;
	elem.first = e;
	elem.second = p;
	if (this->heap.length == 0)
	{
		this->heap.elements[this->heap.length] = elem;
		this->heap.length += 1;
	}
	else
	{
		this->add(elem);
	}

	//O(logn)
}


Element SecondPriorityQueue::pop(){
	//removes and returns the element with the second highest priority
	if (this->heap.length < 2) {
		throw std::invalid_argument("");
	}
	//the representation starts from 1
	//the element with the second highest priority is on the second position
	auto maxChild = -1;
	if (2 <= this->heap.length) {
		maxChild = 2;
	}
	if (3 <= this->heap.length and this->rel(this->heap.elements[3].second, this->heap.elements[maxChild].second))
		maxChild = 3;
	if (4 <= this->heap.length and this->rel(this->heap.elements[4].second, this->heap.elements[maxChild].second))
		maxChild = 4;

	auto deletedElement = this->heap.elements[maxChild];
	this->heap.elements[maxChild] = this->heap.elements[this->heap.length];
	this->heap.length--;
	this->bubbleDown(maxChild);
	return deletedElement;

	//O(logn)
}

void SecondPriorityQueue::bubbleDown(int p){
	int position = p;
	auto element = this->heap.elements[p];
	while (position < this->heap.length) {
		auto maxChild = -1;
		if (position * 3-1 <= this->heap.length)
		{
			//it has a left child,assume it has the highest priority
			maxChild = position * 3-1;
		}
		if (position * 3   <= this->heap.length and this->rel(this->heap.elements[3 * position  ].second , this->heap.elements[maxChild].second))
			//it has 2 children and the second has higher priority
			maxChild = position * 3 ;
		if (position * 3 +1 <= this->heap.length and this->rel(this->heap.elements[3 * position+1].second, this->heap.elements[maxChild].second))
			//it has 3 children and the third has higher priority
			maxChild = position * 3+1;
		if (maxChild != -1 and this->rel(this->heap.elements[maxChild].second, element.second)) {
			auto el = heap.elements[position];
			heap.elements[position] = this->heap.elements[maxChild];
			this->heap.elements[maxChild] = el;
			position = maxChild;
		}
		else {
			position = this->heap.length + 1;
		}
	}

	//O(log2n)
}

bool SecondPriorityQueue::atMostOne() const{
	return this->heap.length <= 1;

	//theta(1)
}

SecondPriorityQueue::~SecondPriorityQueue(){
	delete[] heap.elements;
}
