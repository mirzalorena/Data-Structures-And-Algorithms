#include "BagIterator.h"
#include "Bag.h"

#include <stdexcept>

BagIterator::BagIterator(const Bag& bag) : b(bag)
{
	if (b.elements->size() == 0)
		this->element = 0;
	else
	{
		this->element = this->b.elements->getElement(0);
	}


	this->copyFreq = this->b.freqencies;
	this->position = 0;
	//theta(1)
}

TElem BagIterator::getCurrent()
{

	if (this->valid())
	{
		if (this->b.nrOccurences(this->element) != 0)
			return this->element;
	}
	else
	{
		throw std::invalid_argument("");
	}
		


	//theta(1)

}

bool BagIterator::valid()
{
	if (position < this->b.sizeArray())
		return true;
	return false;
	//theta(1)
}

void BagIterator::next()
{
	if (this->valid())
	{
		if (this->b.nrOccurences(this->element) != 0)
		{
			this->copyFreq->setElement(this->position, this->copyFreq->getElement(this->position) - 1);

		}
		else
		{
			this->position += 1;
			this->element += 1;
		}
	}
	else
		throw std::invalid_argument("");
	//O(n)
}

void BagIterator::first()
{
	if (b.elements->size() == 0)
		this->element = 0;
	else
	{
		this->element = this->b.elements->getElement(0);
	}
	this->copyFreq = this->b.freqencies;
	this->position = 0;
	//theta(1)
}