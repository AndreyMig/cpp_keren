#ifndef __NODE_
#define __NODE_

template <class T>
class MyLinkedList;

template <class T>
class Node
{
	T value;
	Node<T>* next;
	Node<T>* prev;

	template <class T>
	friend class MyLinkedList;

public:
	Node<T>(const T& val, Node<T>* next = NULL, Node<T>* prev = NULL) : value(val), next(next), prev(prev) {}

	T& getValue()					{ return value;} 
	Node<T>* getNext()				{ return next; }
	Node<T>* getPrev()				{ return prev; }

	const T& getValue()		 const	{ return value;} 
	const Node<T>* getNext() const	{ return next; }
	const Node<T>* getPrev() const	{ return prev; }

	void operator()(Node<T>* next, Node<T>* prev);
};

template <class T>
void Node<T>::operator()(Node<T>* next, Node<T>* prev)
{
	this->next = next;
	this->prev = prev;
}

#endif