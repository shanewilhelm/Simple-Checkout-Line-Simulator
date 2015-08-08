/**********************************************************************************************
Assignment: CptS 122 Assignment 6.

Description: This program simulates convenience store checkout lines.

Author: Shane Wilhelm

WSU ID: 11267127

Completion Time: 12 Hours

In completing this program, I received help from the following people: Nobody
**********************************************************************************************/

#include "Simulation.h"

void RunSimulation()
{
	string userInput = "";
	int numberCheckstands = 0;
	srand((unsigned int)time);

	ofstream outputFile;
	outputFile.open("Output.csv");

	cout << "*** Cougar Mart Checkout Simulator ***" << endl << endl;

	while (userInput == "" || numberCheckstands == 0)
	{
		cout << "How many checkout lines would you like to simulate: ";
		getline(cin, userInput);

		try
		{
			numberCheckstands = stoi(userInput);
		}
		catch (...)
		{
			userInput = "";
			numberCheckstands = 0;
		}

		if (numberCheckstands <= 0)
		{
			cout << "Invalid Input. Please Try Again..." << endl;
			numberCheckstands = 0;
		}
	}

	cout << "Preforming simulation..." << endl;

	Vector<CheckoutLine> checkstands(numberCheckstands + 1);

	for (int i = 0; i < numberCheckstands; i++)
	{
		CheckoutLine *myCheckoutLine = new CheckoutLine;
		checkstands.addElement(*myCheckoutLine);
	}

	int newCustomerProbability = 0;
	int currentMinute = 0;
	int totalCustomers = 0;
	
	
	while (currentMinute <= 12 * 60)
	{
		if (haveNewCustomer(newCustomerProbability) == true)
		{
			Customer *newCustomer = new Customer;
			totalCustomers++;

			int lineIndex =  findEmptyCheckoutLine(checkstands, numberCheckstands);
			int serviceTime = (rand() % 4) + 1;

			newCustomer->generateCustomer(currentMinute, lineIndex);

			checkstands[lineIndex].addCustomer(*newCustomer);
			
			newCustomerProbability = 0;

		}
		else
		{
			newCustomerProbability++;
		}

		for (int i = 0; i < numberCheckstands; i++)
		{
			CheckoutLine &myCheckoutLine = checkstands[i];

			myCheckoutLine.tick();
		}

		currentMinute++;
	}

	cout << "Simulation complete. Saving results to Output.csv..." << endl;

	outputFile << "\"Customers Created: \",\"" << totalCustomers << "\"\n";
	outputFile << "\"Customer ID\",\"Arrival\",\"Time to Check Out\",\"Departure\",\"Total Wait\",\"Line Number\"\n";

	for (int i = 0; i < numberCheckstands; i++)
	{
		Vector<Customer> &servicedCustomers = checkstands[i].getServicedCustomers();
		int size = checkstands[i].getServicedCustomers().getSize();

		for (int j = 0; j < size; j++)
		{
			outputFile << "\"" << servicedCustomers[j].getCustomerId() << "\",";
			outputFile << "\"" << servicedCustomers[j].getArrivalTime() << "\",";
			outputFile << "\"" << servicedCustomers[j].getServiceTime() << "\",";
			outputFile << "\"" << servicedCustomers[j].getDepartureTime() << "\",";
			outputFile << "\"" << servicedCustomers[j].getTotalWaitTime() << "\",";
			outputFile << "\"" << servicedCustomers[j].getLineName() << "\"," << endl;
		}
	}
	
	//Clean-Up
	outputFile.close();

	cout << "Save finished. Program complete." << endl;
}


bool haveNewCustomer(int customer_probability)
{
	int random = rand() % 6;
	if (random <= customer_probability)
	{
		return true;
	}
	else
		return false;
}

//Returns a random checkout lane if none are empty.
int findEmptyCheckoutLine(Array<CheckoutLine> &checkstands, int number_checkstands)
{

	for (int i = 0; i < number_checkstands; i++)
	{
		if (checkstands[i].isEmpty() == true)
		{
			return i;
		}
	}

	//None empty, randomly pick one.
	return (rand() % number_checkstands);
}