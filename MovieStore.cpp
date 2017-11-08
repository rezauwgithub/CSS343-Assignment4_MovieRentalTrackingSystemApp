//80 Character Limit
//********//********//********//********//********//********//********//********

//-----------------------MovieStore.cpp--------------------------
//By: Reza Naeemi
//Created: 11/05/2016
//Last Edited: 12/14/2016
//---------------------------------------------------------------
#ifndef MOVIE_STORE_CPP
#define MOVIE_STORE_CPP
#include "MovieStore.h"
//----------------------------MovieStore-------------------------
//Default MovieStore constructor doesn't need to do anything as
//all data items are already initialized to valid states.
//---------------------------------------------------------------
MovieStore::MovieStore()
{
}

//---------------------------~MovieStore-------------------------
//Default MovieStore destructor has to make sure all transactions
//are deleted from the queue. The HashTable will handle the 
//customers and the trees will handle the movies, but if the 
//transactions are not processed before the store object is 
//destructed, the store will need to delete all transactions.
//---------------------------------------------------------------
MovieStore::~MovieStore()
{
}

//---------------------------initializeInventory------------------
//Uses the fileName that was passed in to open an input file 
//stream. This stream is then used to construct movie objects
//(with the help of the movie factory). Each new movie object 
//is then placed in their respective tree.
//---------------------------------------------------------------
bool MovieStore::initializeInventory(const char* fileName)
{

	//opens the file
	std::ifstream fromFile;
	fromFile.open(fileName);

	/*
	Makes sure the file is open. If not, false is returned.
	True signals a success.
	*/
	if (fromFile.is_open())
	{
		/*
		Reads data from the file until there is no more 
		data to be read.
		*/
		while (!fromFile.eof())
		{
			//uses the factory to construct movie objects
			Movie* newMovie = MovieFactory::constructMovie(fromFile);
			/*
			Makes sure the movie object is not NULL as the factory can
			return NULL for invalid data.
			*/
			if (newMovie != NULL)
			{
				//adds the movie to the appropriate BSTree
				movieTrees[newMovie->getMovieType()].insert(newMovie);
			}
		}

		//must close the file
		fromFile.close();
		return true;
	}
	else
	{
		return false;
	}
} //end initializeInventory

//---------------------------initializeCustomers-----------------
//Uses the fileName that was passed in to open an input file 
//stream. This stream is then used to construct customer objects.
//Each new customer is then placed in the HashTable.
//---------------------------------------------------------------
bool MovieStore::initializeCustomers(const char* fileName)
{
	//opens the file
	std::ifstream fromFile;
	fromFile.open(fileName);

	/*
	Makes sure the file is open. If it is not, false is
	returned. True signals success.
	*/
	if (fromFile.is_open())
	{
		/*
		Reads data from the file until there is no more 
		data to be read.
		*/
		while (!fromFile.eof())
		{
			//creates a customer and reads in customer data
			Customer* newCustomer = new Customer;
			fromFile >> *newCustomer;
			
			/*
			If insertion into the HashTable failed, the
			customer ID already exists (and they are suppose
			to be unique) so, the customer is deleted and an
			error is displayed to the screen.
			*/
			if (!customers.put(newCustomer))
			{
				std::cout << "Customer already exists" << std::endl;
				delete newCustomer;
				newCustomer = NULL;
			}

		}
		//must close to file
		fromFile.close();
		return true;
	}
	else
	{
		return false;
	}
} //end initializeCustomers

//---------------------------processTransactions-----------------
//Uses the fileName that was passed in to open an input file 
//stream. This stream is then used to construct Transaction 
//objects (with the help of the TransactionFactory). The 
//Transaction objects are then performed.
//---------------------------------------------------------------
bool MovieStore::processTransactions(const char* fileName)
{
	//opens the stream
	std::ifstream fromFile;
	fromFile.open(fileName);

	/*
	Makes sure the file is open. If it is not, false
	is returned. True signals success.
	*/
	if (fromFile.is_open())
	{
		/*
		Reads the data from the file until all 
		data has been read.
		*/
		while (!fromFile.eof())
		{
			//uses the factory to create a new Transaction
			Transaction* newTransaction = 
				TransactionFactory::constructTransaction(fromFile, movieTrees, 
													NUMBER_OF_TYPES, customers);

			/*
			Makes sure the transaction pointer is not NULL. This
			is because the factory can return NULL if invalid data
			was read. If it is not NULL, the transaction is performed.
			*/
			if (newTransaction != NULL)
			{
				performTransaction(newTransaction);
			}
		}
		
		//must close the file
		fromFile.close();
		return true;
	}
	else
	{
		return false;
	}
} //end processTransactions

//---------------------------performTransactions-----------------
//Checks to make sure the transaction to be performed is not 
//NULL. If it is not, the perform function is called on the 
//transaction and anything that needs to be printed to the 
//screen is.
//---------------------------------------------------------------
void MovieStore::performTransaction(Transaction* transaction)
{
	/*
	Checks to make sure the transaction is not NULL, if it isn't,
	it is performed.
	*/
	if (transaction != NULL)
	{
		std::string message;
		/*
		Checks to see if message needs to be displayed.
		*/
		if (transaction->perform(message))
		{
			std::cout << message << std::endl;
		}
		
		delete transaction;
		transaction = NULL;
	}
}
#endif
