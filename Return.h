//80 Character Limit
//********//********//********//********//********//********//********//********

//----------------------------Return----------------------------
//Return is a concrete subclass of Action. Return is a
//Transaction used when a customer wants to return a movie
//that they have already borrowed. No new variables are required
//for Return so the class defines no new fields. However, Return
//must override inherited functions to provide a concrete 
//implementation.
//---------------------------------------------------------------
//By: Reza Naeemi
//Created: 11/05/2016
//Last Edited: 12/14/2016
//---------------------------------------------------------------
#ifndef RETURN_H
#define RETURN_H
#include "Action.h"
#include <sstream>
class Return : public Action
{
	//overloads the output operator
	friend std::ostream& operator<<(std::ostream& outStream,
												const Return& ret);
public:
	//sets all fields to default values
	Return();
	//used to set movie and customer during creation of object
	Return(Movie* movie, Customer* customer);
	//deletes all dynamic memory
	~Return();

	//overrides the inherited perform function to proide an
	//implementation that increases the stock of the movie that
	//is stores at movie and removes the movie from the customer's
	//list of borrowed movies. The transaction is then placed
	//in the customer's history.
	bool perform(std::string& message);

	//overrides the inherited one method to clone
	//the calling Return object
	Transaction* clone() const;

private:
	//overrides the inherited print method to provide an
	//implementation that can print a Return Transaction.
	void print(std::ostream& outStream) const;
};

#endif


