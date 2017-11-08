//80 Character Limit
//********//********//********//********//********//********//********//********

//----------------------------DisplayTransaction.cpp-----------------
//By: Reza Naeemi
//Created: 11/05/2016
//Last Edited: 11/26/2016
//-------------------------------------------------------------------

#ifndef DISPLAY_TRANSACTION_CPP
#define DISPLAY_TRANSACTION_CPP
#include "DisplayTransaction.h"
//----------------------------DisplayTransaction-----------------
//Default constructor calls Transactions default constructor. 
//No variables need to be set.
//---------------------------------------------------------------
DisplayTransaction::DisplayTransaction() : Transaction()
{
}

//---------------------------~DisplayTransaction-----------------
//No Dynamically allocated memory needs to be deleted.
//---------------------------------------------------------------
DisplayTransaction::~DisplayTransaction()
{
}

//---------------------------operator<<--------------------------
//Outputs the display transaction to the stream using the
//print function. The stream is then returned.
//---------------------------------------------------------------
std::ostream& operator<<(std::ostream& outStream, 
				const DisplayTransaction& display)
{
	display.print(outStream);
	return outStream;
}

#endif