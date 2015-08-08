/**********************************************************************************************
Assignment: CptS 122 Assignment 6.

Description: This program simulates convenience store checkout lines.

Author: Shane Wilhelm

WSU ID: 11267127

Completion Time: 12 Hours

In completing this program, I received help from the following people: Nobody
**********************************************************************************************/

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

using namespace std;

class Customer
{
private:
	int _customer_id;
	int _arrival_time;
	int _service_time;
	int _departure_time;
	static int _id_counter;
	int _line_name;

public:
	
	void generateCustomer(int arrival_time, int line_name)
	{
		_arrival_time = arrival_time;
		_line_name = line_name;
		_customer_id = _id_counter++;
		_departure_time = 0;
	}
	
	int getTotalWaitTime()
	{
		return (_departure_time - _arrival_time);
	}

	int getCustomerId() const
	{
		return _customer_id;
	}

	int getArrivalTime() const
	{
		return _arrival_time;
	}

	int getServiceTime() const
	{
		return _service_time;
	}

	int getDepartureTime() const
	{
		return _departure_time;
	}

	int getIdCounter() const
	{
		return _id_counter;
	}

	int getLineName() const
	{
		return _line_name;
	}

	void setCustomerId(int id)
	{
		_customer_id = id;
	}

	void setArrivalTime(int time)
	{
		_arrival_time = time;
	}

	void setServiceTime(int time)
	{
		_service_time = time;
	}

	void setDepartureTime(int time)
	{
		_departure_time = time;
	}

	void setIdCounter(int counter)
	{
		_id_counter = counter;
	}

	void setLineName(int line_name)
	{
		_line_name = line_name;
	}

};

#endif // !CUSTOMER_H


