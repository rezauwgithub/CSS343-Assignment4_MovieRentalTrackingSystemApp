//80 Character Limit
//********//********//********//********//********//********//********//********

//----------------------------Borrow.cpp-----------------------------
//By: Reza Naeemi
//Created: 11/05/2016
//Last Edited: 11/26/2016
//-------------------------------------------------------------------

#ifndef BORROW_CPP
#define BORROW_CPP
#include "Borrow.h"
//----------------------------Borrow-----------------------------
//Default constructor for Borrow objects. Sets all pointer to 
//NULL using the default Action constructor.
//---------------------------------------------------------------
Borrow::Borrow() : Action()
{
}

//----------------------------Borrow-----------------------------
//Uses the constructor of Action to set the movie and customer
//pointers.
//---------------------------------------------------------------
Borrow::Borrow(Movie* movie, Customer* customer) : Action(movie, customer)
{
}

//----------------------------~Borrow-----------------------------
//No dynamic memory needs to be deleted as each pointer used in
//this class must live on past the life of the borrow
//Transaction.
//----------------------------------------------------------------
Borrow::~Borrow()
{
}

//----------------------------perform-----------------------------
//Each Transaction object can be performed. Therefore, this
//method overrides the inherited perform method to implement the
//borrow transaction perform. It is important to note that a bool
//is returned but the bool doesn't signal success or failure.
//The assignment specs specifically state what shoudl and should
//not be printed to the screen. Therefore, the bool tells the
//MovieStore (or which ever object calls perform) whether or not
//message (which is passed in by reference) should be displayed
//to the screen.
//----------------------------------------------------------------
bool Borrow::perform(std::string& message)
{
	/*
	Checks to see if customer or movie are NULL.
	If so, message is set to reflect to information
	and true is returned.
	*/
	if (getCustomer() == NULL || getMovie() == NULL)
	{
		message = "Borrow Transaction FAILED. Invalid customer or movie";
		return true;
	}

	/*
	Calls the borrow movie function on the customer.
	This function will return true if successful, therefore, 
	if it is succesful, the transaction is added to the 
	customer's history and false is returned.
	*/
	if (getCustomer()->borrowMovie(getMovie()))
	{
		getCustomer()->addToHistory(this->clone());
		return false;
	}

	//if this line is reached, the movie is out of stock
	std::stringstream error;
	error << "Borrow Transaction FAILED. Movie: " << getMovie()->getTitle()
		<< " is out of stock.";
	message = error.str();
	return true;
} //end perform

//----------------------------clone-----------------------------
//Overrides the inherited clone method. Returns a new Borrow
//object that is a copy of the calling object.
//--------------------------------------------------------------
Transaction* Borrow::clone() const
{
	//Dynamically constructs a coy borrow object
	Transaction* borrow = new Borrow(getMovie(), getCustomer());
	return borrow;
}

//----------------------------print-----------------------------
//Overrides inherited print function to allow each borrow object
//to be able to be displayed to a stream.
//--------------------------------------------------------------
void Borrow::print(std::ostream& outStream) const
{
	/*
	Makes sure customer and movie are not NULL before 
	displaying them.
	*/
	if (getCustomer() == NULL || getMovie() == NULL)
	{
		outStream << "";
	}
	else
	{
		outStream << "Customer: " << getCustomer()->getID() <<
					" borrowed: " << getMovie()->getTitle() 
					<< ", " << getMovie()->getDirector() 
					<< ", " << getMovie()->getReleaseYear();
	}
}

//----------------------------operator<<---------------------------
//Overloads the output operator. This method simply calls the print
//function of the borrow object to be displayed. The outStream is
//then returned.
//-----------------------------------------------------------------
std::ostream& operator<<(std::ostream& outStream, const Borrow& borrow)
{
	borrow.print(outStream);
	return outStream;
}

#endif
