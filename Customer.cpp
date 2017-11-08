//80 Character Limit
//********//********//********//********//********//********//********//********

//----------------------------Customer.cpp-----------------------
//By: Reza Naeemi
//Created: 11/05/2016
//Last Edited: 11/26/2016
//---------------------------------------------------------------

#ifndef CUSTOMER_CPP
#define CUSTOMER_CPP
#include "Customer.h"
//----------------------------Customer---------------------------
//Default construct sets all values to defaults. The id must be
//four digits, and therefore, is set to 1000.
//---------------------------------------------------------------
Customer::Customer()
{
	id = 1000;
	firstName = "";
	lastName = "";
}

//----------------------------Customer---------------------------
//Constructor sets specified values for the stock, last name, and
//first name.
//---------------------------------------------------------------
Customer::Customer(int id, const std::string& first, const std::string& last)
{
	//uses id setter to make sure it is within the valid range
	setID(id);
	firstName = first;
	lastName = last;
}

//----------------------------~Customer--------------------------
//Deletes all Transaction pointers in the History. The Movie 
//pointers in the list are stored in the MovieStore and will
//be deleted by it, so, the customer is only responsible for 
//deleting the Transaction history.
//---------------------------------------------------------------
Customer::~Customer()
{
	/*
	Loops through the entire vector, deleting each 
	pointer.
	*/
	for (int i = 0; i < history.size(); i++)
	{
		delete history.at(i);
		history.at(i) = NULL;
	}
}

//--------------------------getFirstName-------------------------
//Returns the customer's first name.
//---------------------------------------------------------------
std::string Customer::getFirstName() const
{
	return firstName;
}

//--------------------------setFirstName-------------------------
//Sets the customer's first name.
//---------------------------------------------------------------
bool Customer::setFirstName(const std::string& name)
{
	firstName = name;
	return true;
}

//--------------------------getLastName--------------------------
//Returns the customer's last name.
//---------------------------------------------------------------
std::string Customer::getLastName() const
{
	return lastName;
}

//--------------------------setLastName--------------------------
//Sets the customer's last name.
//---------------------------------------------------------------
bool Customer::setLastName(const std::string& name)
{
	lastName = name;
	return true;
}

//--------------------------getID--------------------------------
//Returns the customer's id.
//---------------------------------------------------------------
int Customer::getID() const
{
	return id;
}

//--------------------------setID--------------------------------
//Makes sure the id is within 1000 and 9999 because the id must
//be 4 digits. If not, it is fixed within the range and false 
//is returned to signal an error. If it is, true is returned.
//---------------------------------------------------------------
bool Customer::setID(int id)
{
	bool retval = true;
	/*
	Checks to make sure id is within 
	1000 and 9999. If not, it is set
	within 1000 and 9999 and the return value
	is set to false
	*/
	if (id < 1000 || id > 9999)
	{
		retval = false;
		id = 1000;
	}

	//sets the customer's id
	this->id = id;
	return retval;
}

//--------------------------addToHistory-------------------------
//Adds a transaction pointer to the history vector.
//---------------------------------------------------------------
bool Customer::addToHistory(Transaction* trans)
{
	/*
	Checks to make sure the pointer is not NULL.
	*/
	if (trans == NULL)
	{
		return false;
	}
	//adds the pointer
	history.push_back(trans);
	return true;
}

//--------------------------displayHistory-----------------------
//Displays the transaction objects that are in the history vector
//to an out stream.
//---------------------------------------------------------------
void Customer::displayHistory(std::ostream& outStream)
{
	/*
	Loops through the vector printing each transaction
	to the stream.
	*/
	for (int i = 0; i < history.size(); i++)
	{
		outStream << *history.at(i) << std::endl;
	}
}

//--------------------------borrowMovie---------------------------
//Used to have a customer borrow a movie. This is done by adding
//the movie to the borrowed list and decreasing the movie's stock.
//----------------------------------------------------------------
bool Customer::borrowMovie(Movie* movie)
{
	/*
	Checks to see if the movie is NULL, if so, 
	false is retuned to signal a failure.
	*/
	if (movie == NULL)
	{
		return false;
	}

	/*
	Checks to make sure the movie is in stock and 
	can be borrowed.
	*/
	if (movie->inStock())
	{
		//decremenets the movie's stock
		movie->decrementStock();
		//adds the movie to borrowed
		borrowed.push_back(movie);
		//returns true to signal success
		return true;
	}

	//if movie is not in stock, false is returned
	return false;
}

//--------------------------returnMovie--------------------------
//Used to have a customer return a movie. First, the list of
//movies is checked to make sure the customer has the movie, if
//so, the movie is returned.
//---------------------------------------------------------------
bool Customer::returnMovie(Movie* movie)
{
	/*
	Checks to see if the movie is NULL. If so, 
	false is returned.
	*/
	if (movie == NULL)
	{
		return false;
	}

	/*
	Checks to see if the customer has the movie, 
	if so, the movie's stock is incremented and 
	the movie is removed from the list.
	*/
	if (hasBorrowed(movie))
	{
		movie->incrementStock();
		borrowed.remove(movie);
		return true;
	}

	//the customer doesn't have the movie, 
	//so false is returned
	return false;

}

//--------------------------hasBorrowed--------------------------
//Searched the list of borrowed movie to find the movie that 
//was passed in. If it is found, true is returned, otherwise, 
//false is returned.
//---------------------------------------------------------------
bool Customer::hasBorrowed(Movie* movie) const
{
	/*
	Checks to see if the movie is NULL, if so,
	false is returned.
	*/
	if (movie == NULL)
	{
		return false;
	}

	//searches for movie in the list
	std::list<Movie*>::const_iterator found = 
			std::find(borrowed.begin(), borrowed.end(), movie);


	//if found is the end iterator, it wasn't found, so false is
	//returned. If it is not the end, true is returned as it was
	//found
	return (found != borrowed.end());

}

//--------------------------operator<<---------------------------
//Outputs the Customer to a stream and returns the stream.
//---------------------------------------------------------------
std::ostream& operator<<(std::ostream& outStream, const Customer& cust)
{
	outStream << cust.id << " " << cust.lastName << " " << cust.firstName;
	return outStream;
}

//--------------------------operator>>---------------------------
//Reads the Customer's data from a stream and returns the stream.
//---------------------------------------------------------------
std::istream& operator>>(std::istream& inStream, Customer& cust)
{
	inStream >> cust.id >> cust.lastName >> cust.firstName;
	return inStream;
}

//--------------------------operator==---------------------------
//Compares two Customers based on id (as they are unique).
//---------------------------------------------------------------
bool Customer::operator==(const Customer& other) const
{
	return (id == other.id);
}

//--------------------------operator!=---------------------------
//Compares two Customers based on id (as they are unique).
//---------------------------------------------------------------
bool Customer::operator!=(const Customer& other) const
{
	return (id != other.id);
}

#endif
