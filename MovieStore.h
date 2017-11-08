//80 Character Limit
//********//********//********//********//********//********//********//********

//----------------------------MovieStore-------------------------
//A MovieStore holds all of the movies in the store and the 
//customers. Methods included allow the Store to initialize and
//create all movies, customers, and transactions from files as 
//well as perform the transactions.
//---------------------------------------------------------------
//By: Reza Naeemi
//Created: 11/05/2016
//Last Edited: 12/14/2016
//---------------------------------------------------------------

#ifndef MOVIE_STORE_H
#define MOVIE_STORE_H
#include "TransactionFactory.h"
#include "MovieFactory.h"
#include <queue>
class MovieStore
{
public:
	//intializes the store
	MovieStore();
	//deletes the store
	~MovieStore();

	//creates the movie trees using data from a file
	bool initializeInventory(const char* fileName);
	//creates the customer hashtable using data from a file
	bool initializeCustomers(const char* fileName);
	//creates the transactions using data from a file
	bool processTransactions(const char* fileName);

private:
	//an array of trees that hold each type of movie
	BSTree<Movie> movieTrees[NUMBER_OF_TYPES];
	//a HashTable to hold the customers
	CustomerHashTable customers;
	//performs the provided transaction
	void performTransaction(Transaction* transaction);
};

#endif 