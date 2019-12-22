#include "Bag.h"
#include "BagIterator.h"
#include "DynamicArray.h"
#include <iostream>
#include <stdexcept>
#pragma once
using namespace std;

Bag::Bag()
{
	this->elements = new DynamicArray(10);
	this->freqencies = new DynamicArray(10);
	//theta(1)
}

void Bag::add(TElem e)
{
	if (this->isEmpty()) {
		this->elements->addToEnd(e);
		this->freqencies->addToEnd(1);
		return;
	}

	for (int i = 0; i < elements->sizeArray; i++)
	{
		if (elements->getElement(i) == e) {
			freqencies->setElement(i, freqencies->getElement(i) + 1);
			return;

		}
	}
	elements->addToEnd(e);
	freqencies->addToEnd(1);
	return;

	//O(n)
}

bool Bag::remove(TElem elem) {
	for (int i = 0; i < elements->sizeArray; i++) {
		if (elements->getElement(i) == elem)
		{
			if (freqencies->getElement(i) == 1)
			{
				//freqencies->~DynamicArray();
				freqencies->setElement(i, 0);
				freqencies->remove(i);
				elements->remove(i);
				return true;
			}
			else
			{
				freqencies->setElement(i, freqencies->getElement(i) - 1);;
				return true;
			}

		}
	}
	return false;
	//O(n)
}

bool Bag::search(TElem elem) const {
	try {
		for (int i = 0; i < elements->sizeArray; i++) {
			if (elements->getElement(i) == elem)
				return true;
		}
		//return false;
		//return this->elements->getElement(elem);
	}
	catch (exception) {
		return false;
	}
	return false;
	//O(n)
}

int Bag::nrOccurences(TElem elem) const {
	//if (this->isEmpty())
	//	throw std::invalid_argument("");
	for (int i = 0; i < elements->sizeArray; i++) {
		if (elements->getElement(i) == elem)
		{
			//cout << freqencies->getElement(i) << endl;
			return freqencies->getElement(i);
		}
	}
	return 0;
	//O(n)
}


int Bag::sizeArray() const {
	if (this->isEmpty())
		return 0;
	int size = 0;
	for (int i = 0; i < this->elements->size(); i++)
		size += this->freqencies->getElement(i);
	return size;
	//O(n)
}

int Bag::elementsWithThisFrequency(int frequency) const
{
	if (frequency <= 0)
		throw std::invalid_argument("");

	int contor = 0;

	for (int i = 0; i < freqencies->sizeArray; i++)
	{
		if (freqencies->getElement(i) == frequency)
			contor = contor + 1;
	}
	return contor;
}


bool Bag::isEmpty() const {
	return this->elements->sizeArray == 0;
	//theta(1)
}

Bag::~Bag() {
	delete this->elements;
	delete this->freqencies;
	//theta(1)
}

BagIterator Bag::iterator() const {
	return BagIterator(*this);
	//theta(10
}
