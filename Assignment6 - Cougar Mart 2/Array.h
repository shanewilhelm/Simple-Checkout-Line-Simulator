#ifndef ARRAY_H
#define ARRAY_H

#include <exception>
#include "Indexed.h"
using namespace std;

template <typename T>
class Array : public Indexed<T>
{
    //made protected in order to give access to Vector
protected:

    //_items will handle the actual storage
	//of our data items.
	T *_items;

	//used to store the maximum size of
	//our array
	int _max_size;

	//tracks the ACTUAL number of items
	//in our array
	int _number_of_items;

public:

	//Constructor: responsible for setting maximum size and
	//dynamically allocating enough space to store everything.
	Array(const int size)
		: _max_size(size)
	{
		_items = new T[size];
		_number_of_items = 0;
	}

	//We need to delcare a destructor because we're dynamically allocating memory
	//in our constructor
	~Array()
	{
		delete[] _items;
	}

	//methods that originally came from the Collection interface
#pragma region Collection overrides

	//Will return true if we have no items in our Array.  False otherwise.
	virtual bool isEmpty()
	{
		return _number_of_items == 0;
	}

	//Returns the number of items currently in the array.  Note that
	//there still might be NULL values that exist within this range.
	virtual int getSize()
	{
		return _number_of_items;
	}
#pragma endregion

	//methods that originally came from the Bag interface
#pragma region Bag overrides

	//adds an item to the "end" of our array
	virtual void addElement(const T & item)
	{
        //2013-10-11 TODO: implement functionality
        //Steps: 
        // 1. add element to the end of our array
		addElementAt(item, _number_of_items);
	}

	//checks to see if the supplied item exists within our array
	virtual bool containsElement(const T & item)
	{
        //2013-10-11 TODO: implement functionality (call getPositionOf())
		//return getPositionOf(item) != -1;
		return false;
	}

  //  int getPositionOf(const T & item)
  //  {
  //      //2013-10-11 TODO: implement functionality
  //      //Steps: iterate through array.
  //      //  1. if found, return index
  //      //  2. if not found, return -1
		//int found = -1;
		//for(int i = 0; i < _number_of_items; i++)
		//{
		//	//if the item matches the
		//	//current index...
		//	if(item == _items[i])
		//	{
		//		found = i;
		//		break;
		//	}
		//}
		//return found;
  //  }

	//removes the first matching item found from the collection
	virtual int removeElement(const T & item)
	{
        //2013-10-11 TODO: implement functionality
        //Steps: find location of item and call remove
		/*int location = getPositionOf(item);
		if(location == -1)
		{
			throw exception("Item not in collection.");
		}
		removeElementAt(location);
		return location;*/
		return -1;
	}
#pragma endregion

	//methods that originally came from the Indexed interface
#pragma region Indexed overrides

	//returns the item at the specified index
	virtual T &getElementAt(int index)
	{
        //2013-10-11 TODO: add exceptions!
		if(index < 0 || index >= _number_of_items)
		{
			throw exception("Index out of range.");
		}
		return _items[index];
	}

    virtual void setSize(int size)
    {
        //2013-10-11 TODO: implement functionality
        //check for exceptions!
		if(size < 0 || size > _max_size)
		{
			throw exception("Invalid size.");
		}
        _number_of_items = size;
    }

	//sets the item at the specified index
    virtual void setElementAt(const T &item, int index)
	{
        //2013-10-11 TODO: add exceptions!
		if(index < 0 || index >= _max_size)
		{
			throw exception("Index out of bounds.");
		}
		_items[index] = item;
		
		//if this index is larger than our currently tracked _number_of_items,
		//replace with specified index
		if(_number_of_items < index)
		{
			_number_of_items = index;
		}
	}

	//adds the item at the specified index and shifts all larger items
	//"right" by one
    virtual void addElementAt(const T &item, int index)
	{
        //make sure that we're not full and that the index is within bounds
		if(index >= _max_size)
		{
			throw exception("Array index out of bounds.");
		}
		if(_number_of_items == _max_size)
		{
			throw exception("Array is at max size.");
		}

		//shift every item to the right
		for(int i = _number_of_items - 1; i >= index; i--)
		{
			_items[i + 1] = _items[i];
		}
        
        //now that we have a spot for our item, add it to our array
		_items[index] = item;

        //increment the number of items in our array
		_number_of_items++;
	}

	//removes the item at the specified index and shifts all smaller items
	//"left" by one
    virtual void removeElementAt(int index)
	{
		if(index < 0 || index >= _max_size)
		{
			throw exception("Index out of bounds.");
		}

		//shift everything left
		for(int i = index; i < _number_of_items - 1; i++)
		{
			_items[i] = _items[i + 1];
		}

		//do the last shift if we have room
		if(_number_of_items + 1 < _max_size)
		{
			_items[_number_of_items] = _items[_number_of_items + 1];
		}

        //decrement the number of items in our array
		_number_of_items--;
	}
#pragma endregion

	//shortcut for getElementAt
	virtual T &operator[](int index)
	{
		return getElementAt(index);
	}
};

#endif