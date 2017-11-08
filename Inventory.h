//80 Character Limit
//********//********//********//********//********//********//********//********

//----------------------------Inventory--------------------------
//Inventory is a concrete subclass of DisplayTransaction. 
//In order to print the Inventory of the store, the Transaction
//will require access to all of the data structures that hold
//the movie objects, therefore, Inventory has a field that 
//stores a pointer to said data structures. Inventory is required
//to overload inherited functions and provide a proper
//implementation.
//---------------------------------------------------------------
//By: Reza Naeemi
//Created: 11/05/2016
//Last Edited: 12/14/2016
//---------------------------------------------------------------
#ifndef INVENTORY_H
#define INVENTORY_H
#include "DisplayTransaction.h"
#include <sstream>
#include "BSTree.h"
#include "Movie.h"

class Inventory : public DisplayTransaction
{
	//overloads the output operator
	friend std::ostream& operator<<(std::ostream& outStream, const Inventory& inv);
public:
	//default constructor sets all fields to default values
	Inventory();
	//sets the inventory pointer
	Inventory(BSTree<Movie>* inventory, int size);
	//deletes all dynamic memory
	~Inventory();

	//overrides the inherited perform function.
	//This implementation will display the contents of
	//the BSTree's with the movies in them.
	bool perform(std::string& message);

	//overrides the inherited clone method
	//to clone the calling Inventory object
	Transaction* clone() const;

private:
	BSTree<Movie>* inventory;
	int inventorySize;

	//overrides the inherited print method to provide an
	//implementation for Inventory.
	void print(std::ostream& outStream) const;

};

#endif


