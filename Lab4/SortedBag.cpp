#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <exception>
#include <iostream>

using namespace std;

SortedBag::SortedBag(Relation r)
{
	this->r = r;

	this->capacity = 200;
	this->head = -1;
	this->firstEmpty = 0;

	this->next = new int[capacity];

	for (int i = 0; i < this->capacity - 1; i++)
		this->next[i] = i + 1;
	this->next[capacity - 1] = -1;

	this->elements = new TElem[capacity];
	this->frequencies = new int[capacity];

	this->sizeBag = 0;

}

void SortedBag::add(TComp e)
{
	if (this->firstEmpty == -1) 
	{
		//throw(std::exception("Capacity reached its maximum")); 
		resize();
	}
	if (this->isEmpty())
	{
		int newPos = this->firstEmpty;
		this->elements[newPos] = e;
		this->frequencies[newPos] = 1;
		this->firstEmpty = this->next[firstEmpty];
		this->next[newPos] = -1;
		this->head = newPos;
		this->sizeBag += 1;
		return;
	}
	int currentNode = this->head;
	while (currentNode != -1)
	{
		if (this->elements[currentNode] == e)
		{
			this->frequencies[currentNode] = this->frequencies[currentNode] + 1;
			return;
		}
		else
		{
			currentNode = this->next[currentNode];
		}
	}

	if (currentNode == this->head)
	{
		int newPos = this->firstEmpty;
		this->elements[newPos] = e;
		this->frequencies[newPos] = 1;
		this->next[newPos] = this->head;
		this->head = this->firstEmpty;
		this->firstEmpty = this->sizeBag + 1;
		this->sizeBag++;
		return;
	}

	if (this->r(e, this->head))
	{
		int newPos = this->firstEmpty;
		this->elements[newPos] = e;
		this->frequencies[newPos] = 1;
		this->firstEmpty = this->next[firstEmpty];
		this->next[newPos] = this->head;
		this->head = newPos;
		
		this->sizeBag++;
		return;
	}

	int current = this->head;
	while(this->next[current]!=-1 && this->r(this->elements[this->next[current]],e))
	//while (this->next[current] != -1 && this->r(e,this->elements[this->next[current]]))
	{
		current = this->next[current];
	}
	int newPos = this->firstEmpty;
	this->elements[newPos] = e;
	this->frequencies[newPos] = 1;
	this->firstEmpty = this->next[firstEmpty];
	this->next[newPos] = this->next[current];
	this->next[current] = newPos;
	this->sizeBag++;
	return;

	//O(n)
}

bool SortedBag::remove(TComp e)
{
	bool deleted = false;
	int prevNode = -1;
	int currentNode = this->head;
	while (currentNode != -1 && this->elements[currentNode] != e)
	{
		prevNode = currentNode;
		currentNode = this->next[currentNode];
	}
	if (currentNode != -1)
	{
		if (currentNode == this->head)
		{
			//this->head = this->next[head];
			//this->frequencies[currentNode]--;
			this->frequencies[currentNode] = this->frequencies[currentNode] - 1;
			if (this->frequencies[currentNode] == 0)
			{
				this->head = this->next[this->head];
				deleted = true;
				return true;
			}
			else
			{
				return true;
			}

			/*if (this->frequencies[currentNode] > 1)
			{
				this->frequencies[currentNode] -= 1;
				deleted = true;
				return true;
			}
			else
			{
				this->head = this->next[this->head];
				deleted = true;
			}
			return true;*/
		}
		//else
		//{
		//	this->next[prevNode] = this->next[currentNode];
		//}
		this->frequencies[currentNode]=this->frequencies[currentNode]-1;
		if (this->frequencies[currentNode] == 0)
		{

			this->next[prevNode] = this->next[currentNode];
			this->next[currentNode] = this->firstEmpty;
			this->firstEmpty = currentNode;
			deleted = true;
			return true;
		}
		else
		{
			deleted = true;
			return true;
		}
		/*this->next[currentNode] = firstEmpty;
		if (this->frequencies[currentNode] > 1)
		{
			this->frequencies[currentNode] -= 1;
			deleted = true;
			return true;
		}
		else
		{
			this->next[currentNode] = firstEmpty;
			this->firstEmpty = currentNode;
			deleted = true;
			return true;
		}*/
		//this->firstEmpty = currentNode;
		//return false;
		return true;
	}
	else
		return false;

	if (deleted == true)
		this->sizeBag--;

	return false;

	//O(n)
}

bool SortedBag::search(TComp e) const
{
	int current = this->head;
	while (current != -1 && this->elements[current] != e)
	{
		current = this->next[current];
	}
	if (current != -1)
		return true;
	return false;

	//theta(n)
}

int SortedBag::nrOccurrences(TComp e) const
{
	//for (int i = 0; i < this->sizeBag - 1; i++)
	//	if (elements[i] == e)
	//		return this->frequencies[i];
	int currentNode = this->head;
	while (currentNode != -1)
	{
		if (elements[currentNode] == e)
			return this->frequencies[currentNode];
		else
		{
			currentNode = this->next[currentNode];
		}
	}
	return 0;

	//O(n)
}

int SortedBag::size() const
{
	if (this->isEmpty())
		return 0;
	int s = 0;
	//for (int i = 0; i < this->sizeBag - 1; i++)
	//	s = s + this->frequencies[i];
	int currentNode = this->head;
	while (currentNode != -1)
	{
		s = s + this->frequencies[currentNode];
		currentNode = this->next[currentNode];
	}
	return s;

	//theta(n)
}

void SortedBag::resize() {
	//this->capacity *= factor;
	/*TElem* elems = (TElem*)malloc(sizeof(TElem)*(this->capacity));
	TElem* Newnext = (TElem*)malloc(sizeof(TElem)*(this->capacity));
	for (int i = 0; i < this->size(); i++)
		elems[i] = this->elements[i];
	for (int i = 0; i < this->size(); i++)
		Newnext[i] = this->next[i];
	delete[] this->elements;
	this->elements = elems;
	this->next = Newnext;
	int newFirstEmpty = this->next[this->firstEmpty];
	this->firstEmpty = newFirstEmpty;*/
	int newCap = this->capacity * 2;
	TElem* auxElems = new TElem [newCap];
	TElem* auxFreq = new TElem [newCap];
	int* auxNext = new int[newCap];
	//std::copy(this->elements + 0, this->elements + this->capacity, auxElems + 0);
	for (int i = 0; i < this->capacity; i++)
	{
		auxElems[i] = this->elements[i];
	}
	//std::copy(this->frequencies + 0, this->frequencies + this->capacity, auxFreq + 0);
	for (int i = 0; i < this->capacity; i++)
	{
		auxFreq[i] = this->frequencies[i];
	}
	//std::copy(this->next + 0, this->next + this->capacity, auxNext + 0);
	for (int i = 0; i < this->capacity; i++)
	{
		auxNext[i] = this->next[i];
	}
	
	delete[] this->elements;
	this->elements = auxElems;
	delete[] this->frequencies;
	this->frequencies = auxFreq;
	delete[] this->next;
	this->next = auxNext;

	this->capacity = newCap;

	this->firstEmpty = this->capacity/2;

	for (int i = capacity/2; i < this->capacity - 1; i++)
		this->next[i] = i + 1;
	this->next[capacity - 1] = -1;

	//theta(1)
	
}

bool SortedBag::isEmpty() const
{
	return this->sizeBag == 0;

	//theta(1)
}

SortedBagIterator SortedBag::iterator() const
{
	return SortedBagIterator(*this);
}

TElem SortedBag::mostFrequent() const
{
	if (this->isEmpty())
		return NULL_TCOMP;

	int currentNode = this->head;
	TElem mostFreq = 0;
	TElem result = 0;

	while (currentNode != -1)
	{
		if (this->frequencies[currentNode] >= mostFreq)
		{
			mostFreq = this->frequencies[currentNode];
			result = this->elements[currentNode];
		}


		currentNode = this->next[currentNode];
	}
	return result;
}






