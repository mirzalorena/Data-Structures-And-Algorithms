#include "Iterator.h"

#include <utility>


MultiMapIterator::MultiMapIterator(const MultiMap &map) : map(map){
	int currentPosition = 0;
	currentNode = map.head;
}

bool MultiMapIterator::valid() {
	if (currentPosition != -1 && currentNode!=NULL)
		return true;
	return false;
	//theta(1)
}

void MultiMapIterator::next() {
	//this->currentNode = this->sll.getNodeFromPosition(currentPosition)->next;
	if (this->valid())
	{
		if (currentPosition < currentNode->values.size() - 1)
		{
			//this->currentNode = this->map.head->next;
			currentPosition = currentPosition + 1;
		}
		else
		{
			currentNode = this->currentNode->next;
		}
	}
	//else
	//	throw exception();

	//theat(1)
}


TElem MultiMapIterator::getCurrent() {
	//return this->sll.getNodeFromPosition(this->currentPosition);
	//return TElem();
	//TElem pair;
	//pair(this->currentNode->key, this->currentNode->values.getNodeFromPosition(currentPosition));
	
	//return TElem(this->currentNode->key, this->currentNode->values.getNodeFromPosition(currentPosition));
	//return std::make_pair(this->currentNode->key, this->currentNode->values.getNodeFromPosition(currentPosition)->data);
	//if (currentNode != NULL)
	//{
		//return std::make_pair(this->currentNode->key, this->currentNode->values.getNodeFromPosition(currentPosition)->data);
	//}
	if (this->valid())
	{
		pair<TKey, TValue> result = TElem(this->currentNode->key, this->currentNode->values.getNodeFromPosition(currentPosition)->data);
		return result;
	}
	//else
	//	throw exception();
	//return result;

	//theta(1)
}

void MultiMapIterator::first()
{
	int currentPosition = 0;
	currentNode = map.head;

}