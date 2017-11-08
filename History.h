//80 Character Limit
//********//********//********//********//********//********//********//********

//----------------------------History----------------------------
//History is a concrete subclass of DisplayTransaction. In order
//to perform a History Transaction, a customer is required 
//(because it is the history of the customer that is displayed).
//Therefore, History stores a pointer to the Customer whose 
//history was requested.
//---------------------------------------------------------------
//By: Reza Naeemi
//Created: 11/05/2016
//Last Edited: 12/14/2016
//---------------------------------------------------------------
#ifndef HISTORY_H
#define HISTORY_H
#include "DisplayTransaction.h"
#include "Customer.h"
#include <sstream>

class History : public DisplayTransaction
{
	//overloads the output operator
	friend std::ostream& operator<<(std::ostream& outStream, 
											const History& history);
public:
	//default constructor sets all variables to default values
	History();
	//sets the Customer pointer when constructing the object
	History(Customer* customer);
	//Deletes all dynamically allocated memory
	~History();

	//overrides the inherited perform function to 
	//provide the proper History implementation.
	//This implementation will display the history
	//of the customer.
	bool perform(std::string& message);

	//gets a pointer to the customer
	Customer* getCustomer() const;
	//sets the pointer to the customer
	bool setCustomer(Customer* customer);

	//overrides the inherited clone method to
	//return a cloned history transaction.
	Transaction* clone() const;

private:
	Customer* customer;

	//overrides the inherited print function to 
	//provide a proper History implementation
	void print(std::ostream& outStream) const;
};

#endif
