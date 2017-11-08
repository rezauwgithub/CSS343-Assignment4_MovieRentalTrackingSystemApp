//80 Character Limit
//********//********//********//********//********//********//********//********

//----------------------------driver.cpp-----------------------------
//By: Reza Naeemi
//Created: 11/05/2016
//Last Edited: 12/14/2016
//-------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include "MovieStore.h"
using namespace std;

//-----------------------------main----------------------------
//main is responsible for creating a store object and providing
//the information for the store to initialize the customers, 
//the movies, and the transactions. main will return 0 if the 
//program was successful, 1 otherwise.
//-------------------------------------------------------------
int main()
{
	//stores strings for the file names of the customers,
	//movies, and transactions.
	const char* customerFile = "data4customers.txt";
	const char* movieFile = "data4movies.txt";
	const char* transactionFile = "data4commands.txt"; 

	MovieStore myStore;
	
	/*
	Checks to make sure the inventory was initialized
	properly. If it wasn't, an error is printed and the
	program terminates with a code of 1.
	*/
	if (!myStore.initializeInventory(movieFile))
	{
		cout << "There was an error reading the movie file" << endl;
		return 1;
	}

	/*
	Checks to make sure the customers were initialized
	properly. If they weren't, an error is printed and the
	program terminates with a code of 1.
	*/
	if (!myStore.initializeCustomers(customerFile))
	{
		cout << "There was an error reading the customer file" << endl;
		return 1;
	}

	/*
	Checks to make sure the transactions were initialized
	properly. If they weren't, an error is printed and the
	program terminates with a code of 1.
	*/
	if (!myStore.processTransactions(transactionFile))
	{
		cout << "There was an error reading the transaction file" << endl;
	}

    return 0;
}