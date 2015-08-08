#ifndef VECTOR_H
#define VECTOR_H

#include "Array.h"
template <typename T>
class Vector : public Array<T>
{
private:

	void checkCapacity(int requested_size)
	{
		//is our array too small?
		if(requested_size >= _max_size)
		{
			//find a value of max_size that will
			//be large enough to accommodate 
			//our requested size
			int new_size = _max_size;
			while(requested_size >= new_size)
			{
				new_size *= 2 + 1;
			}
			adjustSize(new_size, _number_of_items);
		}
	}

	void adjustSize(int new_size, int num_items_to_copy)
	{
		//create new array with new size
		T *new_array = new T[new_size];

		//copy over old values from our current
		//array
		for(int i = 0; i < num_items_to_copy; i++)
		{
			new_array[i] = _items[i];
		}

		//our array size has changed, so update
		//our max size
		_max_size = new_size;

		//delete our old items
		delete[] _items;
		
		//and reassign to our new array
		_items = new_array;
	}

public:
	Vector(int initial_size = 1)
		: Array(initial_size)
	{
	}

	virtual void setSize(int size)
	{
		checkCapacity(size);
		Array::setSize(size);
	}

	virtual void setElementAt(const T &item, int index)
	{
		checkCapacity(index);
		Array::setElementAt(item, index);
	}

	virtual void addElementAt(const T &item, int index)
	{
		checkCapacity(index);
        checkCapacity(_number_of_items + 1);
		Array::addElementAt(item, index);
	}

	virtual void addElement(const T &item)
	{
		checkCapacity(_number_of_items + 1);
		Array::addElement(item);
	}

	virtual T &operator[](int index)
	{
		checkCapacity(index);
		return Array::operator[](index);
	}
};

#endif