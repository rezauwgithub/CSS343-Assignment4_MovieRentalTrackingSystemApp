//80 Character Limit
//********//********//********//********//********//********//********//********

//-----------------------TransactionFactory.cpp------------------
//By: Reza Naeemi
//Created: 11/05/2016
//Last Edited: 12/14/2016
//---------------------------------------------------------------
#ifndef TRANSACTION_FACTORY_CPP
#define TRANSACTION_FACTORY_CPP
#include "TransactionFactory.h"
//-----------------------TransactionFactory----------------------
//This constructor is private and therefore, is blank as it does
//nothing.
//---------------------------------------------------------------
TransactionFactory::TransactionFactory()
{
}

//----------------------~TransactionFactory----------------------
//This destructor is private and therefore, is blank as it does
//nothing.
//---------------------------------------------------------------
TransactionFactory::~TransactionFactory()
{
}

//----------------------constructTransaction---------------------
//Uses the file stream to read the information in from the file 
//and convert them into Transaction objects. Pointers to the 
//objects are then returned. 
//---------------------------------------------------------------
Transaction* TransactionFactory::constructTransaction(std::ifstream& fromFile,
				BSTree<Movie>* trees, int size, CustomerHashTable& customers)
{
	/*
	Checks to make sure the file is open, if not, NULL is returned.
	If the file is open, the transaction type is read and the data
	is passed to a helper function to construct the specified 
	Transaction object.
	*/
	if (fromFile.is_open())
	{
		char transactionType;
		//reads in the Transaction identifier
		fromFile >> transactionType;
		
		/*
		Checks to see if the end of file has been reached.
		*/
		if (fromFile.eof())
		{
			return NULL;
		}

		/*
		Uses the transaction identifier to determine which 
		method to call.
		*/
		switch (transactionType)
		{
		case 'B':
			//constructs a borrow transaction
			return TransactionFactory::constructBorrow(fromFile, customers,
																trees, size);
		case 'R':
			//constructs a return transaction
			return TransactionFactory::constructReturn(fromFile, customers,
																trees, size);
		case 'I':
			//constructs an inventory transaction
			return TransactionFactory::constructInventory(fromFile, trees,
																		size);
		case 'H':
			//constructs a history transaction
			return TransactionFactory::constructHistory(fromFile, customers);
		default:
			std::cout << "Transaction type: " << transactionType 
										<< " was not recognized." << std::endl;
			std::string discard;
			//discards the line of invalid data
			getline(fromFile, discard);
			return NULL;
		}
	}
	else
	{
		return NULL;
	}
} //end constructTransaction

//----------------------constructInventory-----------------------
//Constructs a new inventory transaction (which just needs the
//movie trees and size of the tree arrary) and returns a pointer
//to it.
//---------------------------------------------------------------
Inventory* TransactionFactory::constructInventory(std::ifstream& fromFile,
												BSTree<Movie>*trees, int size)
{
	Inventory* retval = new Inventory(trees, size);
	return retval;
}

//----------------------constructHistory--------------------------
//Constructs a new history transaction (which just needs the
//customer pointer) and returns a pointer to it.
//---------------------------------------------------------------
History* TransactionFactory::constructHistory(std::ifstream& fromFile,
												CustomerHashTable& customers)
{
	int customerId = 0;
	fromFile >> customerId;
	Customer* customer = NULL;
	//gets the customer using a helper function
	customer = TransactionFactory::getCustomer(customerId, customers);
	/*
	Checks to make sure the customer pointer is not NULL. if it is
	and error is printed and NULL is returned.
	*/
	if (customer == NULL)
	{
		std::cout << "Construction of History Transaction FAILED. Customer: "
							<< customerId << " not found." << std::endl;
		return NULL;
	}
	
	History* history = new History(customer);
	return history;
}

//----------------------constructBorrow--------------------------
//Constructs a new borrow transaction (which just needs the
//movie to borrow and the customer) and returns a pointer
//to it.
//---------------------------------------------------------------
Borrow* TransactionFactory::constructBorrow(std::ifstream& fromFile,
				CustomerHashTable& customers, BSTree<Movie>* trees, int size)
{
	int customerId = 0;
	//reads in the customer id.
	fromFile >> customerId;
	
	//reads the movie from the stream using a helper function
	Movie* toFind = TransactionFactory::readMovie(fromFile);
	/*
	If the movie data was invalid, toFind will be NULL. Therefore,
	an error is printed and NULL is returned.
	*/
	if (toFind == NULL)
	{
		std::cout << "Construction of Borrow Transaction FAILED." 
						<< " Invalid type identifier" << std::endl;
		return NULL;
	}
	
	//gets the customer using a helper function
	Customer* customer = TransactionFactory::getCustomer(customerId, customers);
	/*
	Checks to make sure the customer is not NULL. If it is, an error is 
	printed and NULL is returned.
	*/
	if (customer == NULL)
	{
		std::cout << "Construction of Borrow Transaction FAILED. Customer: " 
							<< customerId << " not found." << std::endl;
		delete toFind;
		toFind = NULL;
		return NULL;
	}
	
	//gets the movie from the trees using a helper function
	Movie* result = TransactionFactory::getMovie(toFind, trees, size, true);
	/*
	Checks to make sure the movie pointer is no NULL. If it is,
	an error is printed and NULL is returned.
	*/
	if (result == NULL)
	{
		std::cout << "Construction of Borrow Transaction FAILED. Movie: " 
						<< toFind->getTitle() << " not found." << std::endl;
		delete toFind;
		toFind = NULL;
		return NULL;
	}
	
	delete toFind;
	toFind = NULL;

	Borrow* borrow = new Borrow(result, customer);
	return borrow;
} //end constructBorrow

//----------------------constructReturn--------------------------
//Constructs a new borrow transaction (which just needs the
//movie to borrow and the customer) and returns a pointer
//to it.
//---------------------------------------------------------------
Return* TransactionFactory::constructReturn(std::ifstream& fromFile, 
			CustomerHashTable& customers, BSTree<Movie>* trees, int size)
{
	int customerId = 0;
	//reads in the customer id
	fromFile >> customerId;
	//reads the movie from the stream using a helper function
	Movie* toFind = TransactionFactory::readMovie(fromFile);
	/*
	If the movie data was invalid, toFind will be NULL. Therefore,
	an error is printed and NULL is returned.
	*/
	if (toFind == NULL)
	{
		std::cout << "Construction of Return Transaction FAILED." 
			<< " Invalid type identifier" << std::endl;
		return NULL;
	}
	
	//gets the customer using a helper function
	Customer* customer = TransactionFactory::getCustomer(customerId, customers);
	/*
	Checks to make sure the customer is not NULL. If it is, an error is 
	printed and NULL is returned.
	*/
	if (customer == NULL)
	{
		std::cout << "Construction of Return Transaction FAILED. Customer: " 
							<< customerId << " not found." << std::endl;
		delete toFind;
		toFind = NULL;
		return NULL;
	}
	//gets the movie from the trees using a helper function
	Movie* result = TransactionFactory::getMovie(toFind, trees, size, false);
	/*
	Checks to make sure the movie pointer is no NULL. If it is,
	an error is printed and NULL is returned.
	*/
	if (result == NULL)
	{
		std::cout << "Construction of Return Transaction FAILED. Movie: " 
						<< toFind->getTitle() << " not found." << std::endl;
		delete toFind;
		toFind = NULL;
		return NULL;
	}
	
	delete toFind;
	toFind = NULL;

	Return* ret = new Return(result, customer);
	return ret;
 } //end constructReturn

//----------------------getCustomer------------------------------
//Uses the customer id and the customer hash table to search
//for a customer. NULL is returned if no customer is found, 
//otherwise a pointer to the customer is returned.
//---------------------------------------------------------------
Customer* TransactionFactory::getCustomer(int id, CustomerHashTable& customers)
{
	Customer* customer = NULL;
	/*
	Checks to make sure the customer was found. If so, the pointer
	is returned.
	*/
	if (customers.get(id, customer))
	{
		return customer;
	}
	
	return NULL;
}

//----------------------getMovie---------------------------------
//Searches for a movie in the movies trees. If the movie is
//found, a pointer to the movie is returned, otherwise, NULL
//is returned. The searchForAlternatives boolean is used to 
//search for ClassicMovie alternatives when required.
//---------------------------------------------------------------
Movie* TransactionFactory::getMovie(Movie* toFind, BSTree<Movie>* trees,
										int size, bool searchForAlternatives)
{
	Movie* returnValue = NULL;
	int index = toFind->getMovieType();
	
	trees[index].retrieve(*toFind, returnValue);
	
	/*
	Checks to see if the movie was not found. If that is
	the case, NULL is returned.
	*/
	if (returnValue == NULL)
	{
		return NULL;
	}
	
	/*
	Checks to see if the movie was not found and if the 
	movie is classical and can have another copy of the 
	same movie in the movie tree. If so, alternatives
	are searched for using a vector.
	*/
	if (!returnValue->inStock() &&
				  index == 2 && searchForAlternatives)
	{	
		toFind->setTitle(returnValue->getTitle());
		toFind->setDirector(returnValue->getDirector());
		
		std::vector<Movie*> alternatives;
		trees[index].dfs(*toFind, alternatives);

		/*
		Looks for all of the pointers in the vector to 
		try and find an in stock alternatives
		*/
		for (int i = 0; i < alternatives.size(); i++)
		{
			/*
			Checks for in stock movies to serve as the 
			alternative
			*/
			if (alternatives.at(i)->inStock())
			{
				returnValue = alternatives.at(i);
				break;
			}
		}
		
	}
	return returnValue;
} //end getMovie

//----------------------readMovie--------------------------------
//Used to read a movie from the stream. Since each movie type
//is a little different, this code has been moved to its own
//method to increase readability and maintainability. The movie
//pointer is returned (can be NULL if there is invalid data).
//---------------------------------------------------------------
Movie* TransactionFactory::readMovie(std::ifstream& fromFile)
{
	char medium = 'D';
	char type = 'T';
	
	//reads the medium
	fromFile >> medium;
	//reads the movie type
	fromFile >> type;
	fromFile.get(); //discard empty space
	Movie* toFind = NULL;

	std::string discard;
	std::string director;
	std::string title;
	int year;
	int month;
	std::string actorFirstName;
	std::string actorLastName;

	/*
	Uses the movie type to determine what information to 
	read for each movie.
	*/
	switch (type)
	{
	//reads data for Drama movies
	case 'D':
		std::getline(fromFile, director, ',');
		fromFile.get();
		std::getline(fromFile, title, ',');
		toFind = new DramaMovie();
		toFind->setTitle(title);
		toFind->setDirector(director);
		break;
	//reads data for Comedy Movies
	case 'F':
		std::getline(fromFile, title, ',');
		fromFile.get();
		fromFile >> year;
		toFind = new ComedyMovie();
		toFind->setReleaseYear(year);
		toFind->setTitle(title);
		break;
	//reads data for Classic Movies
	case 'C':
		fromFile >> month >> year >> actorFirstName >> actorLastName;
		toFind = new ClassicMovie(0, "", "", year, DVD, month, 
										actorFirstName, actorLastName);
		break;
	//discards invalid data
	default:
		std::getline(fromFile, discard);
		toFind = NULL;
	}	

	//returns the movie pointer
	return toFind;
} //end readMovie
#endif
