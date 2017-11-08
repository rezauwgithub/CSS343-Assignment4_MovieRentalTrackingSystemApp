//80 Character Limit
//********//********//********//********//********//********//********//********

//----------------------------CustomerHashTable--------------------
//Provides a hash table that stores customers for fast look up.
//Customers are hashed by id and are placed in the hash table
//that uses separate chaining to remedy collisions. The Hash table
//doesn't allow dupliactes as Customers (which are compared by id)
//are suppose to hav unique ids.
//----------------------------------------------------------------
//By: Reza Naeemi
//Created: 11/05/2016
//Last Edited: 11/26/2016
//---------------------------------------------------------------

#ifndef CUSTOMER_HASH_TABLE_H
#define CUSTOMER_HASH_TABLE_H
#include "Customer.h"
const int STARTING_SIZE = 10;
const double ACCEPTABLE_LAMBDA = 1.0;
class CustomerHashTable
{
public:
	//initializes all variables to a valid state
	CustomerHashTable();
	//copy constructor deep copies source table
	CustomerHashTable(const CustomerHashTable& source);
	//deallocates all memory
	~CustomerHashTable();

	//adds a customer to the table
	bool put(Customer* customer);
	//retrieves a customer for the table
	bool get(int id, Customer*& result);

	//gets the number of customers
	int numCustomers() const;
	//checks to see if the table is empty
	bool isEmpty() const;
	
	//gets the size of the hash table
	int getSize() const;
	
	//gets the lambda of the hashtable
	double getLambda() const;
	
	//removes the specified customer
	bool remove(int id, Customer& result);
	
	//clears the table of all data but leaves it
	//in a valid state
	void makeEmpty();
	
	//operator= deep copies one hashtable to another
	CustomerHashTable& operator=(const CustomerHashTable& source);

private:
	//Nodes are stored by the table to allow the
	//separate chaining.
	struct Node
	{
		Customer* customer;
		int key;
		Node* next;
	};

	Node** table;
	int size;
	int numElements;

	//checks to see if the id already exists in the table
	bool exists(int id, int hashCode) const;
	//adds the customer to the front of a bucket
	void push(Customer* customer, int hashCode);
	//grows the hashtable by a factor of 2
	void grow();
	//deletes the table
	void clear();
};

#endif
