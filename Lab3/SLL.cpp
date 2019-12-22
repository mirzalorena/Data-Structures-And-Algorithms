#include <string>
#include <iostream>
#include <algorithm>
#include "SLL.h"
#include "SLLiterator.h"

//typedef int TElem;

using namespace std;

SLL::SLL()
{
	this->head = NULL;
}


node* SLL::search(TElement elem)
{
	node* current = this->head;
	while (current != NULL and current->data!=elem)
	{
		current = current->next;
	}

	return current;
	
	//complexity: O(n)
}

void SLL:: insertFirst(TValue data)
{
	//struct node* newNode = (struct node*)malloc(sizeof(struct node));
	struct node* newNode = new node;
	newNode->data = data;
	newNode->next = head;
	head = newNode;

	//complexity: theta(1)
}

void SLL::insertAfter(node* currentNode, TElement elem)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = elem;
	newNode->next = currentNode->next;
	currentNode->next = newNode;

	//complexity:theta(1)
}

void SLL::insertPosition(int position, TElement elem)
{
	if (position == 1)
		insertFirst(elem);
	else
	{
		node* currentNode = head;
		int currentPosition = 1;
		while (currentPosition < position - 1 and currentNode != NULL)
		{
			currentNode = currentNode->next;
			currentPosition = currentPosition + 1;
		}
		if (currentNode != NULL)
			insertAfter(currentNode, elem);

	}
	//O(n)
}

node* SLL::getNodeFromPosition(int position)
{
	if (position == 1)
		return this->head;
	else
	{
		node* currentNode = head;
		int currentPosition = 0;
		while (currentPosition < position)
		{
			currentNode = currentNode->next;
			currentPosition = currentPosition + 1;
		}
		return currentNode;
	}
	return 0;

	//O(n)
}


void SLL::deleteElement(TElement elem)
{
	node* current = this->head;
	node* prevNode = NULL;
	while (current != NULL && current->data != elem)
	{
		prevNode = current;
		current = current->next;
	}
	if (current != NULL and prevNode == NULL)
	{
		this->head = this->head->next;
		current->next = NULL;
	}
	else if (current != NULL)
	{
		prevNode->next = current->next;
		current->next = NULL;
	}

	//O(n)
}

int SLL::size()
{
	//int length = 0;
	//SLLiterator it = this->iterator();
	//while (it.valid()) { length++; it.next(); }
	//return length;
	int lenght = 0;
	node* currentNode = head;
	while (currentNode != NULL)
	{
		lenght = lenght + 1;

		currentNode = currentNode->next;

	}

	return lenght;
	//theta(n)
}

SLLiterator SLL:: iterator() const
{
	return SLLiterator();
}
