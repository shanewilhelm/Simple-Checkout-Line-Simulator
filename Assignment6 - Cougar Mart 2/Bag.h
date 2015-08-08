#ifndef BAG_H
#define BAG_H

#include "Collection.h"
template <typename T>
class Bag : public Collection<T>
{
public:
	virtual void addElement(const T & item) = 0;
	virtual bool containsElement(const T & item) = 0;
	virtual int removeElement(const T & item) = 0;
};

#endif