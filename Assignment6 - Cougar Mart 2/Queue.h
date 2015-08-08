/**********************************************************************************************
Assignment: CptS 122 Assignment 6.

Description: This program simulates convenience store checkout lines.

Author: Shane Wilhelm

WSU ID: 11267127

Completion Time: 12 Hours

In completing this program, I received help from the following people: Nobody
**********************************************************************************************/

#ifndef QUEUE_H
#define QUEUE_H

#include "Vector.h"

template<typename T>
class Queue
	:public Vector<T>
{
public:
	T& getFirst()
	{
		return Vector::operator[](0);
	}

	void enqueue(const T& item)
	{
		Vector<T>::addElementAt(item, Vector::_number_of_items);
	}

	T dequeue()
	{
		T item = Vector<T>::getElementAt(0);
		Vector<T>::removeElementAt(0);
		
		return item;
	}
};
#endif // !QUEUE_H
