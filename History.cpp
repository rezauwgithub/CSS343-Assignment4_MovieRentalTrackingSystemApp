//80 Character Limit
//********//********//********//********//********//********//********//********

//----------------------------History.cpp----------------------------
//By: Reza Naeemi
//Created: 11/05/2016
//Last Edited: 12/14/2016
//-------------------------------------------------------------------

#ifndef HISTORY_CPP
#define HISTORY_CPP
#include "History.h"
//----------------------------History----------------------------
//Default constructor for History. Sets the customer pointer to
//NULL.
//---------------------------------------------------------------
History::History()
{
	customer = NULL;
}

//----------------------------History----------------------------
//Constructor sets the customer pointer to the customer pointer
//that was passed in.
//---------------------------------------------------------------
History::History(Customer* customer)
{
	this->customer = customer;
}

//----------------------------~History---------------------------
//Deconstructor sets customer to NULL. The customer object will
//be destroyed by a different object. It is not History's 
//responsiblity to do so.
//---------------------------------------------------------------
History::~History()
{
	customer = NULL; 
}

//--------------------------getCustomer---------------------------
//Returns the customer pointer.
//---------------------------------------------------------------
Customer* History::getCustomer() const
{
	return customer;
}

//----------------------------setCustomer------------------------
//Sets the customer pointer and returns true to signal success.
//---------------------------------------------------------------
bool History::setCustomer(Customer* customer)
{
	this->customer = customer;
	return true;
}

//-------------------------operator<<----------------------------
//Prints the History object to the stream using the private 
//print function. The output stream is then returned.
//---------------------------------------------------------------
std::ostream& operator<<(std::ostream& outStream, const History& history)
{
	history.print(outStream);
	return outStream;
}

//----------------------------print-----------------------------
//Overrides the inherited print function to prints the History
//object to the provided stream.
//---------------------------------------------------------------
void History::print(std::ostream& outStream) const
{
	/*
	Checks to make sure customer is not NULL
	before displaying it to the screen.
	*/
	if (customer == NULL)
	{
		outStream << "";
	}
	else
	{
		//prints the customer's id
		outStream << "History for: " << customer->getID();
	}
}

//----------------------------perform----------------------------
//Overrides the inherited perfrom function to print the history
//of the requested customer. The information isn't actually
//printed. The message varaible (reference to a string) is set
//to the results. True is then returned signalling to the store
//that message should be displayed.
//---------------------------------------------------------------
bool History::perform(std::string& message)
{
	/*
	Checks to see if the customer pointer is NULL.
	If so, message is set to an error message and 
	true is returned.
	*/
	if (customer == NULL)
	{
		message = "History Transaction FAILED. No Customer was provided";
		return true;
	}

	std::stringstream historyStringStream;
	historyStringStream << "History for: " << customer->getID() << std::endl;

	//gets the Customer's history
	customer->displayHistory(historyStringStream);
	
	//sets message and returns true
	message = historyStringStream.str();
	return true;
}

//----------------------------clone------------------------------
//Overrides the inherited clone method to copy the calling 
//History object and return a Transaction pointer.
//---------------------------------------------------------------
Transaction* History::clone() const
{
	Transaction* history = new History(customer);
	return history;
}

#endif
