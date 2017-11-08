//80 Character Limit
//********//********//********//********//********//********//********//********

//----------------------------Customer---------------------------
//Customer is a class that provides a way for the MovieStore to
//keep track of customer id's, first names, and last names. Each
//Customer also has history and a list of movies they have
//borrowed, making managing returns and borrows fairly simple.
//Operators are also provided to compare customers (by id as
//the ids are unique) and to print and read from stream.
//---------------------------------------------------------------
//By: Reza Naeemi
//Created: 11/05/2016
//Last Edited: 11/26/2016
//---------------------------------------------------------------

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "Transaction.h"
#include "Movie.h"
#include <algorithm>
class Customer
{
	//outputs a customer to a stream
	friend std::ostream& operator<<(std::ostream& outStream,
											const Customer& cust);
	//reads a customer's data from a stream
	friend std::istream& operator>>(std::istream& inStream,
													Customer& cust);

public:
	//default constructor sets all default values
	Customer();
	//constructor sets all specified values
	Customer(int id, const std::string& first, const std::string& last);
	//destructor deletes all dynamically allocated memory
	~Customer();

	//gets the first name of th customer
	std::string getFirstName() const;
	//sets the customer's first name
	bool setFirstName(const std::string& name);

	//gets the last name of the customer
	std::string getLastName() const;
	//sets the customer's last name
	bool setLastName(const std::string& name);

	//gets the customer's id
	int getID() const;
	//sets the customer's id
	bool setID(int id);

	//adds a Transaction to the history
	bool addToHistory(Transaction* trans);
	//displays the customer's history to a stream
	void displayHistory(std::ostream& outStream);

	//borrows a movie
	bool borrowMovie(Movie* movie);
	//returns a movie
	bool returnMovie(Movie* movie);
	//checks to see if the customer has
	//borrowed a specific movie
	bool hasBorrowed(Movie* movie) const;

	//compares two customers for equality (by id)
	bool operator==(const Customer& other) const;
	//compares two customers for inequality (by id)
	bool operator!=(const Customer& other) const;

private:
	int id;
	std::string firstName;
	std::string lastName;
	//will store copies of performed transactions
	std::vector<Transaction*> history;
	//will store pointers to the movie objects of the store
	std::list<Movie*> borrowed;
};

#endif
