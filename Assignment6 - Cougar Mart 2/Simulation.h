/**********************************************************************************************
Assignment: CptS 122 Assignment 6.

Description: This program simulates convenience store checkout lines.

Author: Shane Wilhelm

WSU ID: 11267127

Completion Time: 12 Hours

In completing this program, I received help from the following people: Nobody
**********************************************************************************************/

#ifndef SIMULATION_H
#define SIMULATION_H

#include <random>
#include <iostream>
#include <time.h>
#include <sstream>
#include <fstream>
#include "CsvWriter.h"
#include "CheckoutLine.h"

void RunSimulation();
bool haveNewCustomer(int customer_probability);
int findEmptyCheckoutLine(Array<CheckoutLine> &checkstands, int number_checkstands);


#endif // !SIMULATION_H
