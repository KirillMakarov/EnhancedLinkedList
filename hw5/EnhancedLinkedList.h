#ifndef _ENHANCEDLINKEDLIST_H_
#define _ENHANCEDLINKEDLIST_H_
#include "LinkedList.h"

class  ListItemNotFoundException : public logic_error {

public:
	ListItemNotFoundException(const string& what_arg ) throw() :
		logic_error ("Element is not find: " + what_arg) {}
};





template <class T>
class EnhancedLinkedList:public LinkedList<T> {

public:
	T& find_first (const T& key);
	EnhancedLinkedList find_all (const T& key); 
	void remove_first (const T& key); 

};

template <class T>
EnhancedLinkedList<T> EnhancedLinkedList<T>::find_all (const T& key) {

	EnhancedLinkedList<T>* result = new EnhancedLinkedList<T>();

	Node<T>* tempNode = LinkedList<T>::head;
	if (tempNode == nullptr)
		throw EmptyListException ("head is null");
	do
	{
		if (tempNode->getData() == key)
			result -> push_back(key); //ѕочему после стрелки не отображаютс€ методы LinkedList?
		tempNode = tempNode -> getNext();
	}
	while (tempNode != nullptr);

	return *result;
}

template <class T>
T& EnhancedLinkedList<T>::find_first (const T& key)
{
	Node<T>* tempNode = LinkedList<T>::head;
	if (tempNode == nullptr)
		throw ListItemNotFoundException ("head is null");
	do
	{
		if (tempNode->getData() == key)
			return tempNode -> getData();
		tempNode = tempNode -> getNext();
	}
	while (tempNode != nullptr);

	throw ListItemNotFoundException("in find_first(T& key)");
}

template <class T>
void EnhancedLinkedList<T>::remove_first (const T& key)
{
	Node<T>* tempNode = LinkedList<T>::head;

	if (tempNode == nullptr)
		return;
	
	if (tempNode->getData() == LinkedList<T>::head->getData())
	{
		LinkedList<T>::pop_front();
		return;
	}

	do
	{
		//√олова не удалена
		//tempNext == head на 1 итерации
		if (tempNode->getNext()->getData() == key)
		{
			if (tempNode ->getNext() == LinkedList<T>::tail)
			{
				LinkedList<T>::pop_back();
				return;
			}

			//tempNode->getNext() это элемент, который надо удалить и это не хвост с головой.

			Node<T> * nodeForDelete = tempNode->getNext();
			temp->next = nodeForDelete ->getNext();

			delete nodeForDelete;

			return;
		}
		tempNode = tempNode -> getNext();
	}
	while (tempNode != nullptr);
}
#endif