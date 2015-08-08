#ifndef INDEXED_H
#define INDEXED_H

#include "Bag.h"
template <typename T>
class Indexed : public Bag<T>
{
public:
    virtual T &getElementAt(int index) = 0;
    virtual void setElementAt(const T &item, int index) = 0;
    virtual void addElementAt(const T &item, int index) = 0;
    virtual void removeElementAt(int index) = 0;
    virtual void setSize(int size) = 0;
};

#endif