//80 Character Limit
//********//********//********//********//********//********//********//********

//----------------------------CustomerHashtTable.cpp-------------
//By: Reza Naeemi
//Created: 11/05/2016
//Last Edited: 11/26/2016
//---------------------------------------------------------------

#ifndef CUSTOMER_HASH_TABLE_CPP
#define CUSTOMER_HASH_TABLE_CPP

#include "CustomerHashTable.h"
//----------------------------CustomerHashTable------------------
//Default constructor sets all variables to default values.
//---------------------------------------------------------------
CustomerHashTable::CustomerHashTable()
{
	size = STARTING_SIZE;
	numElements = 0;
	
	table = NULL;
	table = new Node*[size];
	
	/*
	Sets all pointer in the table to NULL
	*/
	for (int i = 0; i < size; i++)
	{
		table[i] = NULL;
	}
}

//----------------------------CustomerHashTable------------------
//Copy constructor deep copies source into the calling object.
//---------------------------------------------------------------
CustomerHashTable::CustomerHashTable(const CustomerHashTable& source)
{
	table = NULL;
	size = STARTING_SIZE;
	numElements = 0;
	table = new Node*[size];
	/*
	Sets all pointer in the table to NULL
	*/
	for (int i = 0; i < size; i++)
	{
		table[i] = NULL;
	}
	*this = source;
}

//----------------------------~CustomerHashTable-----------------
//Deallocates all memory used by the table using the clear 
//function.
//---------------------------------------------------------------
CustomerHashTable::~CustomerHashTable()
{
	clear();
}

//----------------------------clear------------------------------
//Deallocates all memory used by the table.
//---------------------------------------------------------------
void CustomerHashTable::clear()
{
	/*
	Loops through all buckets in the table
	deleting them
	*/
	for (int i = 0; i < size; i++)
	{
		Node* current = table[i];
		Node* toDelete = NULL;
		/*
		Loops through all elements in the
		current bucket deleting them
		*/
		while (current != NULL)
		{
			toDelete = current;
			current = current->next;
			delete toDelete->customer;
			toDelete->customer = NULL;
			delete toDelete;
			toDelete = NULL;
			toDelete = current;
		}
		table[i] = NULL;
	}

	//deletes the table
	delete[] table;
	table = NULL;
} //end clear

//----------------------------put---------------------------------
//Finds the hash code of the customer, checks to make sure the
//customer doesn't exist, and then adds the customer to the table.
//----------------------------------------------------------------
bool CustomerHashTable::put(Customer* customer)
{
	//gets the hash code
	int hashCode = customer->getID() % size;

	/*
	Makes sure the customer doesn't exist
	*/
	if (!exists(customer->getID(), hashCode))
	{
		//adds the customer
		push(customer, hashCode);
		numElements++;
		
		/*
		Checks to see if the table needs to be resized.
		This is determined by Lambda.
		*/
		if (getLambda() >= ACCEPTABLE_LAMBDA)
		{
			grow();
		}
		
		return true;
	}

	return false;
}

//----------------------------push-------------------------------
//Operates the same as push of a stack. Simply adds a new node 
//to the front of the of the bucket as determined by hashCode.
//---------------------------------------------------------------
void CustomerHashTable::push(Customer* customer, int hashCode)
{
	Node* newNode = new Node;
	newNode->key = customer->getID();
	newNode->customer = customer;
	newNode->next = table[hashCode];
	table[hashCode] = newNode;
}

//----------------------------exists-----------------------------
//Uses the hash code to search the associated bucket to make sure
//that the id doesn't exist in the table already. True is
//returned if the id already exists, false otherwise.
//---------------------------------------------------------------
bool CustomerHashTable::exists(int id, int hashCode) const
{
	Node* current = table[hashCode];
	/*
	Loops through the bucket looking for the id
	*/
	while (current != NULL)
	{
		/*
		If the id is found, true is returned
		*/
		if (id == current->key)
		{
			return true;
		}
		current = current->next;
	}

	return false;
}

//----------------------------get--------------------------------
//Searches for an id in the table. If it is found, result is 
//pointed to it and true is returned. Otherwise, false is
//returned.
//---------------------------------------------------------------
bool CustomerHashTable::get(int id, Customer*& result)
{
	int hashCode = id % size;
	Node* current = table[hashCode];
	
	/*
	Searches the bucket that is associated with 
	hashCode to see if the id exists.
	*/
	while (current != NULL)
	{
		/*
		if the id is found, result is pointed
		to the customer and true is returned.
		*/
		if (id == current->key)
		{
			result = current->customer;
			return true;
		}
		current = current->next;
	}

	//false is returned if not found
	return false;
}

//----------------------numCustomers------------------------------
//returns the number of customers in the table.
//---------------------------------------------------------------
int CustomerHashTable::numCustomers() const
{
	return numElements;
}

//----------------------------isEmpty----------------------------
//returns true is the table has 0 customers (is empty), false
//otherwise.
//---------------------------------------------------------------
bool CustomerHashTable::isEmpty() const
{
	return numElements == 0;
}

//----------------------------size-------------------------------
//Gets the size of the HashTable.
//---------------------------------------------------------------
int CustomerHashTable::getSize() const
{
	return size;
}

//----------------------------getLambda--------------------------
//Lambda in a HashTable is defined as the number of elements in
//the table divided by the size of the table. Therefore, this 
//method does that calulation and returns the resulting double.
//---------------------------------------------------------------
double CustomerHashTable::getLambda() const
{
	//need to cast the ints to doubles to avoid integer division
	return (static_cast<double>(numElements) / static_cast<double>(size));
}

//----------------------------grow-------------------------------
//Increases the size of the HashTable. This is done by creating a
//table twice the size of the current one and rehashing every
//element in the old one to a new location in the new table. 
//The old table is destructed as we go.
//---------------------------------------------------------------
void CustomerHashTable::grow()
{
	int newSize = size * 2;
	Node** newTable = NULL;
	newTable = new Node*[newSize];
	
	/*
	Loops through the newTable setting all pointers
	to NULL.
	*/
	for (int i = 0; i < newSize; i++)
	{
		newTable[i] = NULL;
	}
	
	/*
	Loops through all buckets of the old table
	to rehash all elements in all buckets.
	*/
	for (int i = 0; i < size; i++)
	{
		Node* current = table[i];
		/*
		Loops through all elements in the
		current bucket. All data is copied
		into a new node and the new node is
		rehashed to find its spot in the
		new table. The old nodes in the 
		old table are deleted once all
		information has been copied.
		*/
		while (current != NULL)
		{
			//copy all data
			Node* newNode = new Node;
			newNode->key = current->key;
			newNode->customer = current->customer;
			int hashCode = newNode->key % newSize;
			newNode->next = newTable[hashCode];
			newTable[hashCode] = newNode;

			//delete old node
			Node* toDelete = current;
			current = current->next;
			delete toDelete;
			toDelete = NULL;
		}
		table[i] = NULL;
	}
	
	//delete old table	
	delete[] table;
	table = NULL;
	//assign new table
	table = newTable;
	size = newSize;
} // end grow

//----------------------------makeEmpty--------------------------
//Clears the table of all data but leaves it in a valid state 
//unlike the clear funtion that destroys the table completely.
//---------------------------------------------------------------
void CustomerHashTable::makeEmpty()
{
	//deletes all data
	clear();
	size = STARTING_SIZE;
	table = new Node*[size];
	/*
	Initializes all the pointers to NULL.
	*/
	for (int i = 0; i < size; i++)
	{
		table[i] = NULL;
	}
	
	numElements = 0;
}

//----------------------------operator=--------------------------
//Used to assign a HashTable to a copy of another HashTable. This
//method creates a deep copy and makes sure that the source 
//HashTable is not the destination HashTable as well. At the end
//a reference to the calling HashTable is returned.
//---------------------------------------------------------------
CustomerHashTable& CustomerHashTable::operator=(const CustomerHashTable& source)
{
	/*
	Makes sure the source table is not the destination table
	as well.
	*/
	if (this != &source)
	{
		clear();
		size = source.size;
		numElements = source.numElements;
		table = new Node*[size];
		/*
		Sets all the pointers in table to NULL.
		*/
		for (int i = 0; i < size; i++)
		{
			table[i] = NULL;
		}
		
		/*
		Loops through the source table copying 
		all the data from its nodes to new nodes
		that are then placed in the calling 
		HashTable's table. Each node is a DEEP
		copy to prevent issues and memory leaks.
		*/
		for (int i = 0; i < size; i++)
		{
			/*
			Checks to make sure the current 
			bucket isn't NULL. If it is, there is
			no need to continue as there is nothing
			to copy.
			*/
			if (source.table[i] != NULL)
			{
				//copies the first node in the current
				//bucket and adds it as the first node
				//in the calling HashTable's bucket.
				Node* sourceNode = source.table[i];
				Node* head = new Node;
				Customer* item = new Customer;
				head->key = sourceNode->key;
				head->next = NULL;
				*item = *sourceNode->customer;
				head->customer = item;
				table[i] = head;
				sourceNode = sourceNode->next;
				
				/*
				Loops through the remaining elements in
				the source HashTable's current bucket
				copying each one and placing them in the 
				corresponding bucket in the calling
				HashTable.
				*/
				while (sourceNode != NULL)
				{
					Node* newNode = new Node;
					item = new Customer;
					newNode->next = NULL;
					*item = *sourceNode->customer;
					newNode->customer = item;
					newNode->key = sourceNode->key;
					sourceNode = sourceNode->next;
					head->next = newNode;
					head = head->next;
				}
			}
		}
	}
	return *this;
} //end operator=

//----------------------------remove-----------------------------
//Removes the customer from the HashTable with the provided id.
//If the customer is found, result is set to a copy of the
//customer object and true is returned. If no customer is found,
//result is not set and false is returned.
//---------------------------------------------------------------
bool CustomerHashTable::remove(int id, Customer& result)
{
	int hashCode = id % size;
	
	/*
	Checks to see if the bucket is empty.
	If so, false is returned.
	*/
	if (table[hashCode] == NULL)
	{
		return false;
	}
	
	Node* current = table[hashCode];
	/*
	Checks to see if the first element in the 
	bucket is the customer to delete. If so, 
	the bucket will point to the second element
	in the bucket and the first one is deleted.
	result is pointed to the removed customer, 
	and numElements is decremented. At the end,
	true is returned.
	*/
	if (id == current->key)
	{
		table[hashCode] = current->next;
		result = *current->customer;
		delete current->customer;
		current->customer = NULL;
		delete current;
		current = NULL;
		numElements--;
		return true;
	}
	
	/*
	Loops til the end of the bucket or until the 
	customer is found.
	*/
	while (current->next != NULL && id != current->next->key)
	{
		current = current->next;
	}
	
	/*
	Checks to see if the next element is NULL. If so, 
	customer was not found and false is returned.
	*/
	if (current->next == NULL)
	{
		return false;
	}
	
	//marks the node to be deleted
	Node* toDelete = current->next;
	//removes the node fromt the bucket
	current->next = current->next->next;
	//sets result
	result = *toDelete->customer;
	//deletes the node and customer
	delete toDelete->customer;
	toDelete->customer = NULL;
	delete toDelete;
	toDelete = NULL;
	numElements--;
	return true;
} //end remove
#endif