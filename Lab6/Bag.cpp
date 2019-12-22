#include "Bag.h"
#include "BagIterator.h"

Bag::~Bag()
{

}

Bag::Bag()
{
	this->sizeBag = 0;
	this->arr = new Node*[m];
	for (int i = 0; i < m; i++) {
		this->arr[i] = nullptr;
	}

}

int Bag::hash(TElem e) const
{
	return e % this->m;
}

void Bag::rehash()
{
	if (this->sizeBag / float(this->m) > 0.7)
	{
		this->m *= 2;
		for (int i = 0; i < m / 2; i++)
		{
			Node* head = this->arr[i];
			while (head != nullptr)
			{
				addToPosition(this->hash(head->info), head->info);
				head = head->next;
			}
		}
	}
}

void Bag::addToPosition(int pos, TElem e)
{
	Node* next = this->arr[pos];
	Node* prev = nullptr;
	while (next != nullptr)
	{
		prev = next;
		next = next->next;
	}
	Node* toAdd = new Node;
	toAdd->info = e;
	prev->next = toAdd;
	toAdd->next = next;
}

bool Bag::removeFromPosition(int pos, TElem e)
{
	Node* current = this->arr[pos];
	Node* prev = nullptr;
	while (current != nullptr && current->info != e)
	{
		prev = current;
		current = current->next;
	}
	if (current == nullptr)
	{
		this->arr[pos] = current->next;
	}
	else
	{
		prev->next = current->next;
	}
	delete current;
	return true;
}

void Bag::add(TElem e)
{
	this->addToPosition(this->hash(e), e);
	this->sizeBag++;

}

bool Bag::remove(TElem e)
{
	return removeFromPosition(this->hash(e), e);
}

int Bag::nrOccurrences(TElem e) const
{
	int cont = 0;
	return cont;

}

int Bag::size() const
{
	return this->sizeBag;
}

BagIterator Bag::iterator() const
{
	//BagIterator newIterator(*this);
	//return newIterator;
}

bool Bag::isEmpty() const
{
	return this->sizeBag == 0;
}
