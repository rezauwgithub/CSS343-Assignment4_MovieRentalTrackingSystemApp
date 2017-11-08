//80 Character Limit
//********//********//********//********//********//********//********//********

//----------------------------MovieFactory.cpp-------------------
//By: Reza Naeemi
//Created: 11/05/2016
//Last Edited: 12/14/2016
//---------------------------------------------------------------
#ifndef MOVIE_FACTORY_CPP
#define MOVIE_FACTORY_CPP
#include "MovieFactory.h"
//----------------------------MovieFactory-----------------------
//MovieFactory is used for static methods. The constructor is 
//private, therefore, it does nothing.
//---------------------------------------------------------------
MovieFactory::MovieFactory()
{
}

//---------------------------~MovieFactory-----------------------
//MovieFactory is used for static methods. The destructor is 
//private, therefore, it does nothing.
//---------------------------------------------------------------
MovieFactory::~MovieFactory()
{
}

//---------------------------constructMovie----------------------
//This static method uses a file input stream to read from the 
//file and package the data into a movie object. The pointer
//to the movie is then returned.
//---------------------------------------------------------------
Movie* MovieFactory::constructMovie(std::ifstream& fromFile)
{
	/*
	Makes sure the stream is opened. If not, NULL is returned.
	Otherwise, data is read from the stream to determine what
	kind of movie the data represents. The movie pointer is 
	then returned.
	*/
	if (fromFile.is_open())
	{
		char movieType;
		fromFile >> movieType;
		
		/*
		Checks to see if the end of file 
		has been reached.
		*/
		if (fromFile.eof())
		{
			return NULL;
		}
		
		char discardComma;
		fromFile >> discardComma;

		/*
		Uses the identifying character to determine which 
		kind of movie to make using helper functions. The
		movie is then returned. If the identifier was not 
		recognized, NULL is returned instead.
		*/
		switch (movieType)
		{
		case 'F':
			//uses a helped function to construct a ComedyMovie
			return MovieFactory::constructComedyMovie(fromFile);
		case 'D':
			//uses a helper function to construct a DramaMovie
			return MovieFactory::constructDramaMovie(fromFile);
		case 'C':
			//uses a helper function to construct a ClassicMovie
			return MovieFactory::constructClassicMovie(fromFile);
		default:
			//alerts the user of the bad information
			std::cout << "Movie identifier: " << movieType << " was not recognized" << std::endl;
			std::string discard;
			//discards the entire line of invalid information
			getline(fromFile, discard);
			return NULL;
		}
	}
	else
	{
		return NULL;
	}

} //end constructMovie

//---------------------constructComedyMovie----------------------
//Creates a ComedyMovie and uses the overloaded operator>> to 
//extract the ComedyMovie data. The pointer to the movie is then
//returned.
//---------------------------------------------------------------
ComedyMovie* MovieFactory::constructComedyMovie(std::ifstream& fromFile)
{
	ComedyMovie* retval = new ComedyMovie;
	fromFile >> *retval;
	return retval;
}

//---------------------constructDramaMovie-----------------------
//Creates a DramaMovie and uses the overloaded operator>> to 
//extract the DramaMovie data. The pointer to the movie is then
//returned.
//---------------------------------------------------------------
DramaMovie* MovieFactory::constructDramaMovie(std::ifstream& fromFile)
{
	DramaMovie* retval = new DramaMovie;
	fromFile >> *retval;
	return retval;
}

//--------------------constructClassicMovie----------------------
//Creates a ClassicMovie and uses the overloaded operator>> to 
//extract the ClassicMovie data. The pointer to the movie is then
//returned.
//---------------------------------------------------------------
ClassicMovie* MovieFactory::constructClassicMovie(std::ifstream& fromFile)
{
	ClassicMovie* retval = new ClassicMovie;
	fromFile >> *retval;
	return retval; 
}

#endif 
