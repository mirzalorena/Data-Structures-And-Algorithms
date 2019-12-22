#include "DA_Iterator.h"
#include <stdexcept>
#pragma once

DAIterator::DAIterator(const DynamicArray& c) : da(c) {
	this->position = 0;
	//theta(1)
}
TElem DAIterator::getCurrent() {
	if (this->valid())
		return da.getElement(this->position);
	else
		throw std::invalid_argument("Invalid iterator.");
	//theta(1)
}
bool DAIterator::valid() {
	return this->position < da.size();
	//theta(1)
}
void DAIterator::next() {
	if (this->valid())
		this->position++;
	else
		throw std::invalid_argument("Invalid iterator.");
	//theta(1)

}
void DAIterator::first() {
	this->position = 0;
	//theta(1)
}