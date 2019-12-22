
#include "SortedBagIterator.h"
#include <stdexcept>

SortedBagIterator::SortedBagIterator(const SortedBag& c) :sb(c)
{
	this->index = this->sb.head;
	//this->copyFreq = this->sb.frequencies;
	copyFreq = new int[sb.capacity];
	for (int i = 0; i < sb.capacity; i++)
	{
		this->copyFreq[i] = sb.frequencies[i];
	}

}

TComp SortedBagIterator::getCurrent() const
{
	if (this->valid())
	{
		//if (this->sb.nrOccurrences(this->element) != 0)
		//	return this->element;
		return this->sb.elements[this->index];
	}
	else
	{
		throw std::invalid_argument("");
	}
	//return -1;

	//theta(1)
}

void SortedBagIterator::next()
{
	if (this->valid())
	{
		//if (this->sb.nrOccurrences(this->element) != 0)
		//{
		//	this->copyFreq[this->index] = this->copyFreq[this->index] - 1;
		//}
		//else
		//{
			//this->index += 1;
			//this->element += 1;
			//this->index = this->sb.next[this->index];
			//this->index = this->sb.next[this->index];
			//this->element = this->sb.elements[this->next[this->element]];
		//}
		//this->index = this->sb.next[this->index];
		if (this->copyFreq[this->index] >= 1)
		{
			this->copyFreq[this->index] = this->copyFreq[this->index] - 1;
		}
		else
		{
			this->index = this->sb.next[this->index];
		}


	}
	else {
		throw std::invalid_argument("");
	}

	//theta(1)
}

void SortedBagIterator::first()
{
	this->index = this->sb.head;
	this->copyFreq = sb.frequencies;
	if (sb.size() == 0)
	{
		this->element = 0;
	}
	else
	{
		this->element = sb.elements[0];
	}

	//theta(1)
}

bool SortedBagIterator::valid() const
{
	//return index < sb.size();
	if (this->index == -1)
		return false;
	return true;

	//theta(1)
}

