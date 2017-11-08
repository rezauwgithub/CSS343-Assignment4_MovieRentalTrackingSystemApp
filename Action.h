//80 Character Limit
//********//********//********//********//********//********//********//********

//----------------------------Action.h-----------------------------
//Action is an abstract subclass of Transaction. A Transaction
//is operation that the Movie Store can carry out. An action,
//specifically, is a Transaction that performs something
//to other object(s). Action is abstract just like Transaction
//but is used to categorize specific Transactions. All Actions
//require a Movie and a Customer. This is why pointers to these
//objects are stored by Action.
//---------------------------------------------------------------
//By: Reza Naeemi
//Created: 11/05/2016
//Last Edited: 11/26/2016
//---------------------------------------------------------------

#ifndef ACTION_H
#define ACTION_H
#include "Movie.h"
#include "Transaction.h"
#include "Customer.h"

class Action : public Transaction
{
	//provides an output operator that calls a pure virtual print function
	friend std::ostream& operator<<(std::ostream& outStream,
		const Action& action);
public:
	//default constructor sets all pointers to NULL
	Action();
	//sets the movie and customer pointers
	Action(Movie* movie, Customer* customer);
	//virtual destructor for inheritance
	virtual ~Action();

	//returns a pointer to the movie object
	Movie* getMovie() const;
	//sets the pointer to the movie object
	bool setMovie(Movie* movie);

	//returns a pointer to the customer object
	Customer* getCustomer() const;
	//sets the pointer to the customer object.
	bool setCustomer(Customer* customer);

	//pure virtual perform function needs to be overridden by
	//subclasses so that they can implement the perform function
	//according to their behavior. 
	virtual bool perform(std::string& message) = 0;

	//pure virtual function that provides transactions
	//a method to clone themselves.
	virtual Transaction* clone() const = 0;

private:
	Movie* movie;
	Customer* customer;

	//pure virtual print function allows the output operator to 
	//call the correct print function depending on the object that
	//is being pointed to.
	virtual void print(std::ostream& outStream) const = 0;
};

#endif
