//80 Character Limit
//********//********//********//********//********//********//********//********

//----------------------------MovieFactory------------------------
//MovieFactory is used to create Movie objects. This is used so
//the Store object doesn't have to be concerned with reading the
//from the file or how the input is formatted. The Store will 
//be able to use a MovieFactory to worry about these details
//for it. Each method is a static function so that an object
//doesn't have to be created to use the factory. 
//---------------------------------------------------------------
//By: Reza Naeemi
//Created: 11/05/2016
//Last Edited: 12/14/2016
//---------------------------------------------------------------
#ifndef MOVIE_FACTORY_H
#define MOVIE_FACTORY_H
#include <fstream>
#include <iostream>
#include "Movie.h"
#include "DramaMovie.h"
#include "ClassicMovie.h"
#include "ComedyMovie.h"
#include <string>
class MovieFactory
{
public:
	//Uses the file stream to create a movie and return a pointer to it
	static Movie* constructMovie(std::ifstream& fromFile);
private:
	//I don't want the factory instantiated. So the constructor is private.
	MovieFactory();
	//Similarly, the destrcutor is also private.
	~MovieFactory();
	
	//Uses the file stream to create a comedy movie and return a pointer to it
	static ComedyMovie* constructComedyMovie(std::ifstream& fromFile);
	//Uses the file stream to create a drama movie and return a pointer to it
	static DramaMovie* constructDramaMovie(std::ifstream& fromFile);
	//Uses the file stream to create a classic movie and return a pointer to it
	static ClassicMovie* constructClassicMovie(std::ifstream& fromFile);
};

#endif