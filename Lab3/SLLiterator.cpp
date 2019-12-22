#pragma once 
#include "SLLiterator.h"

//typedef int TElem;


void SLLiterator::init(SLL sll)
{
	this->sll = sll;
	this->current = sll.getHead();
	//theta(1)
}

TElement SLLiterator::getCurrent()
{
	//if (this->current == NULL)
	//	return 0;
	TElement e = this->current->data;
	return e;
	//theta(1)
}

void SLLiterator::next()
{
	this->current = this->current->next;
	//theta(1)
}

bool SLLiterator::valid()
{
	if (this->current != NULL)
		return true;
	return false;
	//theta(1)
}