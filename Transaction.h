//80 Character Limit
//********//********//********//********//********//********//********//********

//----------------------------Transaction------------------------
//Transaction is the highest class in the Transaction hierarchy.
//Because different categories of transactions require different
//variables, Transaction does not include any variables. 
//Variables will be added in subclasses. However, every 
//Transaction will need to override a perform and print function, 
//therefore, this class provides pure virtual versions of both
//functions.
//---------------------------------------------------------------
//By: Reza Naeemi
//Created: 11/05/2016
//Last Edited: 12/14/2016
//---------------------------------------------------------------
#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include <string>
class Transaction
{
	//overloads the output operator
	friend std::ostream& operator<<(std::ostream& outStream, const Transaction& trans);
public:
	//default constructor constructs object
	Transaction();
	//virtual function to allow polymorphism appropriately
	virtual ~Transaction();

	//defines a pure virtual perform function that all
	//subclasses must override
	virtual bool perform(std::string& message) = 0;

	//provides a pure virtual function for subclasses to 
	//implement to clone themselves
	virtual Transaction* clone() const = 0;

private:
	//defines a pure virtual print functon that all
	//subclasses must override
	virtual void print(std::ostream& outStream) const = 0;
};

#endif