//80 Character Limit
//********//********//********//********//********//********//********//********

//----------------------------Inventory.cpp----------------------
//By: Reza Naeemi
//Created: 11/05/2016
//Last Edited: 12/14/2016
//---------------------------------------------------------------
#ifndef INVENTORY_CPP
#define INVENTORY_CPP
#include "Inventory.h"
//----------------------------Inventory--------------------------
//Default constructor sets the inventory to NULL and the size 
//to 0. DisplayTransaction's default constructor is used as well.
//---------------------------------------------------------------
Inventory::Inventory() : DisplayTransaction()
{
	inventorySize = 0;
	inventory = NULL;
}

//----------------------------Inventory---------------------------
//Constructor sets inventory size and inventory to the specified
//values. DisplayTransaction's default constructor is also called.
//----------------------------------------------------------------
Inventory::Inventory(BSTree<Movie>* inventory, int size) : DisplayTransaction()
{
	//makes sure inventorySize is greater than 0 
	inventorySize = (size > 0) ? size : 0;
	this->inventory = inventory;
}

//---------------------------~Inventory--------------------------
//Destructor is not responsible for deleteing any memory,
//therefore, it is blank.
//---------------------------------------------------------------
Inventory::~Inventory()
{
	//nothing needs to be deleted
}

//----------------------------clone------------------------------
//Overrides the inherited clone method to copy the calling 
//inventory object and return a Transaction pointer.
//---------------------------------------------------------------
Transaction* Inventory::clone() const
{
	Transaction* inven = new Inventory(inventory, inventorySize);
	return inven;
}

//----------------------------operator<<-------------------------
//Provides an operator<< to allow Inventory objects to be
//printed to streams. The private print method is used and the 
//outStream is returned at the end.
//---------------------------------------------------------------
std::ostream& operator<<(std::ostream& outStream, const Inventory& inv)
{
	inv.print(outStream);
	return outStream;
}

//----------------------------print------------------------------
//Overrides the inherited print method to provide a method that
//prints the calling Inventory object to the specified stream.
//---------------------------------------------------------------
void Inventory::print(std::ostream& outStream) const
{
	outStream << "Inventory size: " << inventorySize;
}

//----------------------------perform----------------------------
//Overrides the inherited perfrom function to provide an 
//implementation specific to Inventory Transactions. True is
//returned when message (a string passed in by reference) should
//be dislayed to the user (the displaying is done by the store).
//---------------------------------------------------------------
bool Inventory::perform(std::string& message)
{	
	/*
	Checks to see if invalid data has been provided. If so,
	message is set and true is returned.
	*/
	if (inventorySize <= 0 || inventory == NULL)
	{
		message = "Inventory Transaction FAILED. Invalid data.";
		return true;
	}

	std::stringstream stringStream;

	/*
	Loops through all trees printing them to the stringstream.
	*/
	for (int i = 0; i < inventorySize; i++)
	{
		inventory[i].display(stringStream);
		stringStream << std::endl;
	}

	//converts the stream to a string
	message = stringStream.str();
	return true;
}
#endif