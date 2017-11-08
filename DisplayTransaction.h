//80 Character Limit
//********//********//********//********//********//********//********//********

//----------------------------DisplayTransaction-----------------
//DisplayTransaction is an abstract subclass of Transaction. This
//is because there are several Transactions; however, they belong
//to different categories. DisplayTransaction is one of those 
//categories. DisplayTransaction does not add any variables or
//methods than what was inherited from Transaction. It overrides
//Transaction's virtual functions, but still keeps them virtual
//expecting subclasses to provide implementation.
//---------------------------------------------------------------
//By: Reza Naeemi
//Created: 11/05/2016
//Last Edited: 12/14/2016
//---------------------------------------------------------------
#ifndef DISPLAY_TRANSACTION_H
#define DISPLAY_TRANSACTION_H
#include "Transaction.h"
class DisplayTransaction : public Transaction
{
	//overloads the output operator
	friend std::ostream& operator<<(std::ostream& outStream,
		const DisplayTransaction& display);
public:
	//default constructor sets defaults
	DisplayTransaction();
	//virtual destructor deletes all dynamic memory
	virtual ~DisplayTransaction();

	//overrides the inherited perform function as a 
	//virtual function to be implemented by concrete
	//subclasses
	virtual bool perform(std::string& message) = 0;

	//overrides the inherited clone method but becuase
	//display transaction is abtract, the method remains
	//pure virtual
	virtual Transaction* clone() const = 0;

private:
	//overrides the inherited print function as a virtual 
	//function to be implemented by concrete subclasses
	virtual void print(std::ostream& outStream) const = 0;
};

#endif
