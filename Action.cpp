//80 Character Limit
//********//********//********//********//********//********//********//********

//----------------------------Action.cpp-----------------------------
// By: Reza Naeemi
// Created: 11/05/2016
// Last Edited: 11/26/2016
//-------------------------------------------------------------------

#ifndef ACTION_CPP
#define ACTION_CPP
#include "Action.h"

//----------------------------Action-----------------------------
//Default constructor for Action objects. Sets all pointer to 
//NULL.
//---------------------------------------------------------------
Action::Action() : Transaction()
{
	movie = NULL;
	customer = NULL;
}

//----------------------------Action-----------------------------
//Constructor for Action that sets the pointer to the customer
//and the movie. Since the Transactions need to be operating
//on the actual objects, these pointers are not pointing to 
//copies of the data, they are pointing to the actual data.
//---------------------------------------------------------------
Action::Action(Movie* movie, Customer* customer)
{
	this->movie = movie;
	this->customer = customer;
}

//----------------------------~Action-----------------------------
//No memory for Action objects are declared dynamically. 
//Therefore, the destructor doesn't have to delete anything. Note
//that both movie and customer will be deleted by the data 
//structure they are stored in so it is not the job of the Action
//object to delete them.
//----------------------------------------------------------------
Action::~Action()
{
	//movie and customer will be 
	//destroyed by different object later. It is 
	//not Action's responsibility to do so.
	movie = NULL;
	customer = NULL;
}

//----------------------------getMovie-----------------------------
//Returns a pointer to the movie object. This is useful for 
//subclasses
//-----------------------------------------------------------------
Movie* Action::getMovie() const
{
	return movie;
}

//----------------------------setMovie-----------------------------
//Sets the movie pointer to a new movie. True is returned to signal
//a success.
//-----------------------------------------------------------------
bool Action::setMovie(Movie* movie)
{
	this->movie = movie;
	return true;
}

//----------------------------getCustomer-----------------------------
//Returns a pointer to the customer object.
//--------------------------------------------------------------------
Customer* Action::getCustomer() const
{
	return customer;
}

//----------------------------setCustomer------------------------
//Sets the customer pointer and returns true to signal a success.
//---------------------------------------------------------------
bool Action::setCustomer(Customer* customer)
{
	this->customer = customer;
	return true;
}

//----------------------------operator<<-------------------------
//Prints out the Action object to the outStream and returns the
//outStream.
//---------------------------------------------------------------
std::ostream& operator<<(std::ostream& outStream, const Action& action)
{
	action.print(outStream);
	return outStream;
}

#endif
