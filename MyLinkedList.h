#ifndef __MY_LINKED_LIST
#define __MY_LINKED_LIST
#include <stdlib.h>
#include "Node.h"

template <class T>
class MyLinkedList
{
	Node<T>* head;
	Node<T>* tail;

public:
	MyLinkedList() : head(NULL), tail(NULL) {}
	~MyLinkedList();

	Node<T>* addLast(const T& t);
	Node<T>* addLast(Node<T>* n);

	void deleteElement(const T& t);
	void deleteElement(Node<T>* n);

	void print(ostream& o);
};

template <class T>
MyLinkedList<T>::~MyLinkedList()
{
	while (head != NULL)
	{
		deleteElement(head);
	}
}

template <class T>
Node<T>* MyLinkedList<T>::addLast(const T& t)
{
	Node<T>* n = new Node<T>(t);
	return addLast(n);
}

template <class T>
Node<T>* MyLinkedList<T>::addLast(Node<T>* n)
{
	n->operator()(NULL, tail);
	if (head == NULL)
		head = tail = n;
	else
	{
		tail->next = n;
		tail = n;
	}
	return n;
}

template <class T>
void MyLinkedList<T>::deleteElement(const T& t)
{
	Node<T>* cur = head;

	while (cur != NULL)
	{
		if (cur->value == t)
		{
			deleteElement(cur);
			break;
		}
		cur = cur->next;
	}

}

template <class T>
void MyLinkedList<T>::deleteElement(Node<T>* n)
{
	Node<T>* nPrev = n->prev;
	Node<T>* nNext = n->next;

	if (nPrev)
		nPrev->next = nNext;
	if (nNext)
		nNext->prev = nPrev;

	if (n == head)
		head = head->next;
	if (n == tail)
		tail = tail->prev;

	delete n;
}

template <class T>
void MyLinkedList<T>::print(ostream& o)
{
	Node<T>* cur = head;
	if (cur == NULL)
		o << "The list is empty." << endl;
	else
	{
		while (cur != NULL)
		{
			o << cur->value << " -> ";
			cur = cur->next;
		}
		o << "\b\b\b  " << endl;

	}
}

#endif