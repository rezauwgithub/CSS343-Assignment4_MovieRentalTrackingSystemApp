//80 Character Limit
//********//********//********//********//********//********//********//********

//-----------------------Return.cpp------------------------------
//By: Reza Naeemi
//Created: 11/05/2016
//Last Edited: 12/14/2016
//---------------------------------------------------------------
#ifndef RETURN_CPP
#define RETURN_CPP
#include "Return.h"
//----------------------------Return-----------------------------
//Default constructor uses the default Action constructor to set
//all pointers to NULL.
//---------------------------------------------------------------
Return::Return() : Action()
{
}

//----------------------------Return-----------------------------
//Constructor uses the Action constructor to set all pointers to 
//the specified values.
//---------------------------------------------------------------
Return::Return(Movie* movie, Customer* customer) : Action(movie, customer)
{

}

//---------------------------~Return-----------------------------
//Destructor is not repsonsible for deleting anything. The 
//movie and customer will be deleted by the data structures the
//reside in.
//---------------------------------------------------------------
Return::~Return()
{
}

//----------------------------perform----------------------------
//Performs the Return transaction. First, it is checked to make
//sure that the customer has the movie to return, if this is
//true, the movie's stock is then incremented, the movie is
//removed from the customer's list, and the transaction clones
//itself and places the clone in the history of the customer. 
//True is returned to signal that message should be displayed, 
//false otherwise.
//---------------------------------------------------------------
bool Return::perform(std::string& message)
{
	/*
	Makes sure the customer and movie pointers are pointing
	to valid data. If they are not, message is set and true
	is returned.
	*/
	if (getCustomer() == NULL || getMovie() == NULL)
	{
		message = "Return Transaction FAILED. Invalid customer or movie";
		return true;
	}

	/*
	Makes sure the return succedded. If it did not, 
	it is because the customer doens't have this movie.
	It it was successful, the clone is added to the history
	and false is returned.
	*/
	if (getCustomer()->returnMovie(getMovie()))
	{
		getCustomer()->addToHistory(this->clone());
		return false;
	}

	std::stringstream error;
	//the error message is set
	error << "Return Transaction FAILED. Customer: " << getCustomer()->getID()
	<< " has not borrowed an exact copy of movie: " << getMovie()->getTitle();
	message = error.str();
	return true;
} //end perform

//----------------------------clone------------------------------
//Returns a pointer to an exact copy of the calling Return 
//object.
//---------------------------------------------------------------
Transaction* Return::clone() const
{
	Transaction* ret = new Return(getMovie(), getCustomer());
	return ret;
}

//---------------------------print-------------------------------
//Overrides the inherited print function to work for Return 
//objects. The Return object is printed to the stream.
//---------------------------------------------------------------
void Return::print(std::ostream& outStream) const
{
	/*
	Checks to make sure customer and movie are not
	NULL before displaying them.
	*/
	if (getCustomer() == NULL || getMovie() == NULL)
	{
		outStream << "";
	}
	else
	{
		outStream << "Customer: " << getCustomer()->getID() <<
						" returned: " << getMovie()->getTitle()
					<< ", " << getMovie()->getDirector() 
					<< ", " << getMovie()->getReleaseYear();
	}
}

//---------------------------operator<<--------------------------
//Prints the Return object to the specified stream. This is done
//using the private print function. The outStream is then
//returned.
//---------------------------------------------------------------
std::ostream& operator<<(std::ostream& outStream, const Return& ret)
{
	ret.print(outStream);
	return outStream;
}

#endif
