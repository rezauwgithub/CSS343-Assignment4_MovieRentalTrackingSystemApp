//80 Character Limit
//********//********//********//********//********//********//********//********

//----------------------------TransactionFactory-----------------
//TransactionFactory is responsible for constructing
//Transaction objects and returing pointers to them. Each 
//Transaction doesn't know about the store and therefore, each 
//Transaction cannot search the store's customers or movies to 
//get the data they need. Therefore, the TransactionFactory uses
//the provided information and the store to find the objects for
//each Transaction. That way, each Transaction is constructed
//with all the data they will ever need. This also increases the
//performance when the Transactions are performed (decreasing
//performance on construction).
//---------------------------------------------------------------
//By: Reza Naeemi
//Created: 11/05/2016
//Last Edited: 12/14/2016
//---------------------------------------------------------------

#ifndef TRANSACTION_FACTORY_H
#define TRANSACTION_FACTORY_H
#include "Transaction.h"
#include "Action.h"
#include "DisplayTransaction.h"
#include "Borrow.h"
#include "Return.h"
#include "Inventory.h"
#include "History.h"
#include <fstream>
#include <string>
#include <iostream>
#include "BSTree.h"
#include "Movie.h"
#include "Customer.h"
#include "CustomerHashTable.h"
#include "DramaMovie.h"
#include "ClassicMovie.h"
#include "ComedyMovie.h"
#include <string>
#include <vector>
class TransactionFactory
{
public:
	//static method uses the stream and store's data to construct
	//a Transaction object and returns a pointer to it.
	static Transaction* constructTransaction(std::ifstream& fromFile,
				BSTree<Movie>* trees, int size, CustomerHashTable& customers);

private:
	//This class is to be used for the static methods,
	//therefore, the construct is private to prevent instantiation.
	TransactionFactory();
	//similarly, the destructor is private.
	~TransactionFactory();
	
	//helper function is used to find the customer in the
	//HashTable to construct Transactions that require a customer.
	static Customer* getCustomer(int id, CustomerHashTable& customers);
	//helper function is used to find a movie in the store's trees.
	//this is to help construct Transactions that require a movie.
	static Movie* getMovie(Movie* toFind, BSTree<Movie>* trees, int size,
												bool searchForAlternatives);
	//helper function reads in movie data from the stream 
	//this is because, depending on the movie type, 
	//the data can be different.
	static Movie* readMovie(std::ifstream& fromFile);
	
	//private helper function is used to construct an Inventory 
	//Transaction and return the pointer to it.
	static Inventory* constructInventory(std::ifstream& fromFile, 
												BSTree<Movie>*trees, int size);
	//private helper function is used to construct a History 
	//Transaction and return the pointer to it.
	static History* constructHistory(std::ifstream& fromFile, 
												CustomerHashTable& customers);
	//private helper function is used to construct a Borrow
	//Transaction and return the pointer to it.
	static Borrow* constructBorrow(std::ifstream& fromFile, 
				CustomerHashTable& customers, BSTree<Movie>* trees, int size);
	//private helper function is used to construct a Return
	//Transaction and return the pointer to it.
	static Return* constructReturn(std::ifstream& fromFile, 
				CustomerHashTable& customers, BSTree<Movie>* trees, int size);
};

#endif
