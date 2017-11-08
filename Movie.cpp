//80 Character Limit
//********//********//********//********//********//********//********//********

//----------------------------Movie.cpp--------------------------
//By: Reza Naeemi
//Created: 11/05/2016
//Last Edited: 12/14/2016
//---------------------------------------------------------------

#ifndef MOVIE_CPP
#define MOVIE_CPP
#include "Movie.h"
//----------------------------Movie------------------------------
//Default Movie constructor sets all data to defaults.
//---------------------------------------------------------------
Movie::Movie()
{
	stock = 0;
	director = "";
	this->title = "";
	releaseYear = MIN_YEAR;
	type = COMEDY;
	medium = DVD;
}

//----------------------------Movie------------------------------
//Constructor sets all data to the specified values
//---------------------------------------------------------------
Movie::Movie(int s, const std::string& dir, const std::string& title,
									int year, MovieType t, MovieMedium m)
{
	//makes sure stock is valid data
	setStock(s);
	director = dir;
	this->title = title;
	//makes sure year is valid data
	setReleaseYear(year);
	type = t;
	medium = m;
}

//---------------------------~Movie------------------------------
//Destructor doesn't need to delete anything as no dynamic 
//memory is used.
//---------------------------------------------------------------
Movie::~Movie()
{
}

//----------------------------getStock---------------------------
//Returns the stock of the movie.
//---------------------------------------------------------------
int Movie::getStock() const
{
	return stock;
}

//----------------------------setStock---------------------------
//Sets the stock and returns true to signal a success. If s is
//less than 0, stock will be set to 0 and false will be returned
//to signal a failure.
//---------------------------------------------------------------
bool Movie::setStock(int s)
{
	bool retval = true;
	/*
	Makes sure s is 0 or greater because a 
	movie cannot have negative stock.
	*/
	if (s < 0)
	{
		retval = false;
		s = 0;
	}

	stock = s;
	return retval;
}

//-----------------------------inStock---------------------------
//Returns true if there is at least 1 movie. False if not.
//---------------------------------------------------------------
bool Movie::inStock() const
{
	return (stock >= 1);
}

//------------------------hasSufficientStock---------------------
//Returns true if the movie has at least amount in stock. 
//Otherwise, false is returned.
//---------------------------------------------------------------
bool Movie::hasSufficientStock(int amount) const
{
	return (stock - amount >= 0);
}

//------------------------increaseStock--------------------------
//Increases the stock by amount. True is returned to signal a 
//success, false signals a failure.
//---------------------------------------------------------------
bool Movie::increaseStock(int amount)
{
	bool retval = true;
	/*
	Makes sure amount is positive
	*/
	if (amount < 0)
	{
		retval = false;
		amount = 0;
	}

	stock += amount;
	return retval;
}

//------------------------incrementStock-------------------------
//Increases stock by 1 and returns true.
//---------------------------------------------------------------
bool Movie::incrementStock()
{
	stock += 1;
	return true;
}

//------------------------decreaseStock--------------------------
//Decreases stock by amount. True is returned to signal a success
//but false signals a failure.
//---------------------------------------------------------------
bool Movie::decreaseStock(int amount)
{
	bool retval = true;
	/*
	Makes sure amount is positive
	*/
	if (amount < 0)
	{
		retval = false;
		amount = 0;
	}

	/*
	Makes sure there is sufficient stock to
	remove.
	*/
	if (hasSufficientStock(amount))
	{
		stock -= amount;
		return retval;
	}

	return false;
}

//------------------------decrementStock-------------------------
//Decreases stock by 1. True is returned to signal a success and
//false signals failure.
//---------------------------------------------------------------
bool Movie::decrementStock()
{
	/*
	Makes sure the movie is in stock.
	*/
	if (inStock())
	{
		stock -= 1;
		return true;
	}

	return false;
}

//------------------------getTitle-------------------------------
//Returns the title of the movie.
//---------------------------------------------------------------
std::string Movie::getTitle() const
{
	return title;
}

//------------------------setTitle-------------------------------
//Sets the title of the movie and returns true.
//---------------------------------------------------------------
bool Movie::setTitle(const std::string& title)
{
	this->title = title;
	return true;
}

//------------------------getDirector----------------------------
//Returns the director of the movie.
//---------------------------------------------------------------
std::string Movie::getDirector() const
{
	return director;
}

//------------------------setDirector----------------------------
//Sets the director of the movie and returns true.
//---------------------------------------------------------------
bool Movie::setDirector(const std::string& dir)
{
	director = dir;
	return true;
}

//------------------------getReleaseYear-------------------------
//Returns the release year of the movie.
//---------------------------------------------------------------
int Movie::getReleaseYear() const
{
	return releaseYear;
}

//------------------------setReleaseYear-------------------------
//Sets the release year of the movie. True is returned to signal 
//a success but false is returned if the year is less than 1800.
//For this assignment, I am assuming no movie was made before
//the year 1800.
//---------------------------------------------------------------
bool Movie::setReleaseYear(int year)
{
	bool retval = true;
	/*
	Checks to make sure year is a valid year.
	*/
	if (year < MIN_YEAR)
	{
		retval = false;
		year = MIN_YEAR;
	}

	releaseYear = year;
	return retval;
}

//------------------------getMovieType---------------------------
//Returns the movie type of the calling movie.
//---------------------------------------------------------------
MovieType Movie::getMovieType() const
{
	return type;
}

//------------------------getMedium------------------------------
//Returns the medium of the calling movie.
//---------------------------------------------------------------
MovieMedium Movie::getMedium() const
{
	return medium;
}

//------------------------setMedium------------------------------
//Sets the medium of the calling movie and returns true.
//---------------------------------------------------------------
bool Movie::setMedium(MovieMedium medium)
{
	this->medium = medium;
	return true;
}

//------------------------operator<<-----------------------------
//Prints the movie object to the specified stream. This uses the
//private print function and returns the stream object.
//---------------------------------------------------------------
std::ostream& operator<<(std::ostream& outStream, const Movie& movie)
{
	movie.print(outStream);
	return outStream;
}

//------------------------operator>>-----------------------------
//Reads the movie object from the specified stream. This uses the
//private read function and returns the stream object.
//---------------------------------------------------------------
std::istream& operator>>(std::istream& inStream, Movie& movie)
{
	movie.read(inStream);
	return inStream;
}

#endif
