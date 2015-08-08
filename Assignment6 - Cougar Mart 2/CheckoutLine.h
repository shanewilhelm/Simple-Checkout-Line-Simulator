/**********************************************************************************************
Assignment: CptS 122 Assignment 6.

Description: This program simulates convenience store checkout lines.

Author: Shane Wilhelm

WSU ID: 11267127

Completion Time: 12 Hours

In completing this program, I received help from the following people: Nobody
**********************************************************************************************/

#ifndef CHECKOUTLANE_H
#define CHECKOUTLANE_H

#include "Customer.h"
#include "Queue.h"

class CheckoutLine
{
private: 
	string _line_name;
	int _tick_count;
	Queue<Customer> _line;
	Vector<Customer> _served_customers;
	
public:
	CheckoutLine()
	{
		_tick_count = 0;
	}

	
	string getLineName()
	{
		return _line_name;
	}

	bool isEmpty()
	{
		if (_line.isEmpty() == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void addCustomer(Customer some_customer)
	{
		_line.enqueue(some_customer);
	}

	Vector<Customer> &getServicedCustomers()
	{
		return _served_customers;
	}

	void tick()
	{
		if (_line.isEmpty() == false)
		{
			Customer &firstCustomer = _line.getFirst();

			if (firstCustomer.getDepartureTime() == 0)
			{
				int serviceTime = (rand() % 4 + 1);

				firstCustomer.setServiceTime(serviceTime);
				firstCustomer.setDepartureTime((serviceTime + _tick_count));
			}

			if (firstCustomer.getDepartureTime() < _tick_count)
			{
				_served_customers.addElement(_line.dequeue());
			}
		}

		_tick_count++;
	}
};

#endif // !CHECKOUTLANE_H

