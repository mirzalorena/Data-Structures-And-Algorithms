#include "SLLArray.h"

#include <exception>

SLLArray::SLLArray() {
	int *next = new int[100];
	TElem *elems = new TElem[100];
	this->capacity = 100;
	this->head = -1;
	for (int i = 0; i < this->capacity - 1; i++)
		this->next[i] = i + 1;
	this->next[capacity]=-1;
	this->firstEmpty = 1;

	//theta(n)
}

bool SLLArray::search(TElem elem)
{
	int current = this->head;
	while (current != -1 && this->elems[current] != elem)
	{
		current = this->next[current];
	}
	if (current != -1)
		return true;
	else
		return false;
	//O(n)
}

void SLLArray::insertFirst(TElem elem)
{
	if (this->firstEmpty == -1) { throw(std::exception("Capacity reached its maximum")); }
	int newPos = this->firstEmpty;
	this->elems[newPos] = elem;
	this->firstEmpty = this->elems[firstEmpty];

	this->head = newPos;
}

void SLLArray::deleteElement(TElem elem)
{
	int prevNode = -1;
	int currentNode = this->head;
	while (currentNode != -1 && this->elems[currentNode] != elem) {
		prevNode = currentNode;
		currentNode = this->elems[currentNode];
	}
	if (currentNode != -1) {
		if (currentNode == this->head)
			this->head = this->elems[this->head];
		else
			this->elems[prevNode];
		this->elems[currentNode];
		this->firstEmpty = currentNode;
	}
	else
		throw(std::exception("Element couldn't be removed, because it does not exist"));
}