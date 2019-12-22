#include "DynamicArray.h"
#include "DA_Iterator.h"
#include <stdexcept>
#include <iostream>
#include <stdlib.h>
using namespace std;
#pragma once

DynamicArray::DynamicArray(int cap) {
	this->capacity = cap;
	this->sizeArray = 0;
	this->elements = new TElem[cap];
	//theta(1)
}

DynamicArray::DynamicArray(const DynamicArray& da) {
	this->sizeArray = da.sizeArray;
	this->capacity = da.capacity;
	this->elements = new TElem[this->capacity];
	for (int i = 0; i < this->sizeArray; i++)
		this->elements[i] = da.elements[i];
	//theta(1)
}
DynamicArray::~DynamicArray() {
	delete[] this->elements;

}
TElem DynamicArray::getElement(int pos) const {
	//if (pos >= this->sizeArray)
	//	throw std::invalid_argument("Invalid position!");
	return this->elements[pos];
	//theta(1)

}

TElem DynamicArray::setElement(int pos, TElem newElem) {
	if (pos >= this->sizeArray) {
		throw std::invalid_argument("Invalid position!");
	}
	TElem element = this->elements[pos];
	this->elements[pos] = newElem;
	return element;
	//theta(1)
}

void DynamicArray::addToEnd(TElem newElem) {
	if (this->sizeArray == this->capacity)
		this->resize(2);
	this->elements[this->sizeArray] = newElem;
	this->sizeArray++;
	//theta(1)
}

void DynamicArray::resize(int factor)
{
	this->capacity *= factor;
	TElem* elems = (TElem*)malloc(sizeof(TElem)*(this->capacity));
	for (int i = 0; i < this->sizeArray; i++)
		elems[i] = this->elements[i];
	delete[] this->elements;
	this->elements = elems;
	//theta(n)
}

void DynamicArray::addToPosition(int pos, TElem newElem) {
	if (pos > this->sizeArray) {
		throw std::invalid_argument("Invalid position!");
	}
	if (this->sizeArray == this->capacity)
		this->resize(2);
	this->sizeArray++;
	for (int i = this->sizeArray - 1; i > pos; i--) {
		this->elements[i] = this->elements[i - 1];
	}
	this->elements[pos] = newElem;
	//O(n)
}

TElem DynamicArray::remove(int pos) {
	if (pos >= this->sizeArray) {
		throw std::invalid_argument("Invalid position!");
		return -1;
	}
	TElem element = this->elements[pos];
	for (int i = pos; i < this->sizeArray - 1; i++) {
		this->elements[i] = this->elements[i + 1];
	}
	this->sizeArray--;
	return element;
	//O(n)
}
//returns an iterator for the DynamicArray
DAIterator DynamicArray::iterator() const {
	return DAIterator(*this);
	//theta(1)
}