//80 Character Limit
//********//********//********//********//********//********//********//********

//----------------------------Borrow-----------------------------
//Borrow is a concrete class of Action. This is because Borrow
//is a Transaction that performs an Action. This class requires
//nothing more than is inherited from Action. However, it must
//override all pure virtual functions to provide the proper
//Borrow implementation.
//---------------------------------------------------------------
//By: Reza Naeemi
//Created: 11/05/2016
//Last Edited: 11/26/2016
//---------------------------------------------------------------

#ifndef BORROW_H
#define BORROW_H
#include "Action.h"
#include <sstream>
class Borrow : public Action
{
	//overloads the output operator for Borrow)
	friend std::ostream& operator<<(std::ostream& outStream,
		const Borrow& borrow);
public:
	//default constructor sets all pointers to NULL
	Borrow();
	//assigns each pointer to the passed in arguments
	Borrow(Movie* movie, Customer* customer);
	//destructs the object
	~Borrow();

	//overrides the inherited perform function to implement the proper behavior
	//borrow will need to decrease the stock of the movie it points to and add
	//the borrow object to the history of the customer. Also, the movie will 
	//need to be placed into the customer's list of borrowed movies.
	bool perform(std::string& message);

	//overrides the inherited clone method in order to clone itself
	//as a borrow transaction
	Transaction* clone() const;

private:

	//overrides the print function so that borrow can display the type of
	//transaction, what movie was borrowed, and which customer borrowed it.
	void print(std::ostream& outStream) const;
};

#endif


