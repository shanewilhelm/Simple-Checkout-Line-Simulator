#ifndef COLLECTION_H
#define COLLECTION_H

template<typename T>
class Collection
{
public:
	//TODO: implement iterators / enumerators for our Collection interface
	virtual bool isEmpty() = 0;
	virtual int getSize() = 0;
};

#endif