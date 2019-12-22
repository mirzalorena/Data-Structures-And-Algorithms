#pragma once
#include "Iterator.h"
#include "SLL.h"
//#include "SLLiterator.h"
#include "MultiMap.h"
#include<utility>

using namespace std;


MultiMap::MultiMap()
{
	this->head = NULL;
}


void MultiMap::add(TKey key, TValue value)
{
	MultiMapNode* currentNode = head;
	//int currentPosition = 1;
	while (currentNode != NULL)
	{
		if (currentNode->key != key)
		{
			currentNode = currentNode->next;
			//currentPosition = currentPosition + 1;
		}
		else if (currentNode->key == key)
		{
			//newElem->values.insertAfter(currentNode, value);
			currentNode->values.insertFirst(value);
			return;
		}
		

	}
	struct MultiMapNode* newElem = new MultiMapNode;
	newElem->key = key;
	newElem->next = head;
	newElem->values = SLL();

	newElem->values.insertFirst(value);
	this->head = newElem;

	
	//O(a)
}

vector<TValue> MultiMap::search(TKey c) const
{
	vector<TValue> values;
	MultiMapNode* currentNode = head;
	while (currentNode != NULL)
	{
		if (currentNode->key == c)
		{
			node* newNode = currentNode->values.getHead();
			while (newNode != NULL)
			{
				values.push_back(newNode->data);
				newNode=newNode->next;
			}

		}
		currentNode = currentNode->next;
	}
	return values;

	//O(n)
}

int MultiMap::size() const
{
	/*int length = 0;
	MultiMapIterator it = this->iterator();
	while (it.valid()) { length++; it=it.next(); }
	return length*/

	int lenght = 0;
	MultiMapNode* currentNode = head;
	while (currentNode != NULL)
	{
			node* newNode = currentNode->values.getHead();
			while (newNode != NULL)
			{
				lenght = lenght + 1;
				newNode = newNode->next;
			}
	
		currentNode=currentNode->next;
		
	}

	return lenght;

	//theta(n)
}

bool MultiMap::isEmpty() const
{
	MultiMapNode* currentNode = head;
	if (currentNode == NULL)
		return true;
	else return false;
	//theta(1)
}

bool MultiMap::remove(TKey key, TValue value)
{
	MultiMapNode* currentNode = head;
	while (currentNode != NULL)
	{
		if (currentNode->key != key)
		{
			currentNode = currentNode->next;
		}
		else if (currentNode->key == key)
		{	
			int initialSize = currentNode->values.size();
			currentNode->values.deleteElement(value);
			
			if (currentNode->values.size() == 0)
			{
				MultiMapNode* currentNode = head;
				MultiMapNode* prevNode = NULL;
				while (currentNode != NULL and currentNode->key != key)
				{
					prevNode = currentNode;
					currentNode = currentNode->next;
				}
				if (currentNode != NULL && prevNode == NULL)
				{
					this->head = this->head->next;
					currentNode->next = NULL;
				}
				else if (currentNode != NULL)
				{
					prevNode->next = currentNode->next;
					currentNode->next = NULL;
				}
				return true;
			}
			int finalSize = currentNode->values.size();
			if (finalSize == initialSize) return false;
			return true;
		}
	}
	return false;

	//O(n)
}

int MultiMap::getValueRange() const
{
	if (this->isEmpty())
		return -1;
	MultiMapNode* current = head;
	int minim = 10000;
	int maxim = 0;
	while (current != NULL)
	{
		if (current->values.size() != 0)
		{
			node* newNode = current->values.getHead();
			while (newNode != NULL)
			{
				if (newNode->data >= maxim)
					maxim = newNode->data;
				else if (newNode->data <= minim)
					minim = newNode->data;

				newNode = newNode->next;
			}

		}
		current = current->next;
	}
	int result = maxim - minim;
	return result;
}


MultiMapIterator MultiMap::iterator() const
{
	return MultiMapIterator(*this);
}




