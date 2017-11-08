//80 Character Limit
//********//********//********//********//********//********//********//********

//-----------------------Transaction.cpp-------------------------
//By: Reza Naeemi
//Created: 11/05/2016
//Last Edited: 12/14/2016
//---------------------------------------------------------------

#ifndef TRANSACTION_CPP
#define TRANSACTION_CPP
#include "Transaction.h"
//----------------------------Transaction-------------------------
//Default construcor doesn't need to set any data, therefore, it 
//is blank.
//----------------------------------------------------------------
Transaction::Transaction()
{
}

//---------------------------~Transaction-------------------------
//Destructor doesn't need to delete anything, therefore, it is 
//blank.
//----------------------------------------------------------------
Transaction::~Transaction()
{
}

//----------------------------operator<<---------------------------
//Prints a Transaction to a stream using a private print function
//that all subclasses must override. The stream is then returned.
//----------------------------------------------------------------
std::ostream& operator<<(std::ostream& outStream, const Transaction& trans)
{
	trans.print(outStream);
	return outStream;
}

#endif
