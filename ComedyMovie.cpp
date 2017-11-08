//80 Character Limit
//********//********//********//********//********//********//********//********

//----------------------------ClassicMovie.cpp-----------------------
//By: Reza Naeemi
//Created: 11/05/2016
//Last Edited: 11/26/2016
//-------------------------------------------------------------------

#ifndef COMEDY_MOVIE_CPP
#define COMEDY_MOVIE_CPP
#include "ComedyMovie.h"
//----------------------------ComedyMovie------------------------
//Default constructor for ComedyMovies. Uses the Movie 
//constructor to set all values in Movie.
//---------------------------------------------------------------
ComedyMovie::ComedyMovie() : Movie()
{
}

//----------------------------ComedyMovie-----------------------
//Constructor sets all values specified by creator. The Movie
//constructor is used as well.
//---------------------------------------------------------------
ComedyMovie::ComedyMovie(int s, const std::string& dir,
const std::string& title, int year, MovieMedium m)
	: Movie(s, dir, title, year, COMEDY, m)
{

}

//----------------------------~ComedyMovie----------------------
//Destructor doesn't delete anything as now dynamic memory is 
//used.
//---------------------------------------------------------------
ComedyMovie::~ComedyMovie()
{
}

//----------------------------operator<<-------------------------
//Overloads the output operator to display a ComedyMovie to the
//screen. Uses the private print method of the comedy class. The
//Stream is then returned.
//---------------------------------------------------------------
std::ostream& operator<<(std::ostream& outStream, const ComedyMovie& comedy)
{
	comedy.print(outStream);
	return outStream;
}

//----------------------------operator>>-------------------------
//Overloads the input operator to read into a ComedyMovie. 
//Uses the private read method of the comedy class. The
//Stream is then returned.
//---------------------------------------------------------------										
std::istream& operator>>(std::istream& inStream, ComedyMovie& comedy)
{
	comedy.read(inStream);
	return inStream;
}

//----------------------------operator==-------------------------
//Overloads the equality operator to check if two ComedyMovie
//objects are the same. ComedyMovie objects are compared by
//the title and release year.
//---------------------------------------------------------------
bool ComedyMovie::operator==(const ComedyMovie& other) const
{
	return (getTitle()       == other.getTitle()      && 
		    getReleaseYear() == other.getReleaseYear());
}

//----------------------------operator!=-------------------------
//Overloads the inequality operator to check if two ComedyMovie
//objects are not the same. ComedyMovie objects are compared by
//the title and release year.
//---------------------------------------------------------------
bool ComedyMovie::operator!=(const ComedyMovie& other) const
{
	return !(*this == other);
}

//----------------------------operator<--------------------------
//Overloads the less than operator to check if a ComedyMovie
//is less than another. ComedyMovies are compared by the title
//and the release year, in that order.
//---------------------------------------------------------------
bool ComedyMovie::operator<(const ComedyMovie& other) const
{
	/*
	Checks to see if the Titles are the same.
	If they are, the release years must be compared.
	*/
	if (getTitle() == other.getTitle())
	{
		//compare release years
		return getReleaseYear() < other.getReleaseYear();
	}
	
	//compare titles
	return getTitle() < other.getTitle();
}

//----------------------------operator<=-------------------------
//Is used to see if a ComedyMovie is less than or equal to 
//another ComedyMovie. This uses the == and < operator.
//---------------------------------------------------------------
bool ComedyMovie::operator<=(const ComedyMovie& other) const
{
	return (*this == other || *this < other);
}

//----------------------------operator>--------------------------
//Overloads the greater than operator to check if a ComedyMovie
//is greater than another. ComedyMovies are compared by the title
//and the release year, in that order.
//---------------------------------------------------------------
bool ComedyMovie::operator>(const ComedyMovie& other) const
{
	/*
	Checks to see if the Titles are the same.
	If they are, the release years must be compared.
	*/
	if (getTitle() == other.getTitle())
	{
		//compares release year
		return getReleaseYear() > other.getReleaseYear();
	}
	
	//compares titles
	return getTitle() > other.getTitle();
}

//----------------------------operator<=-------------------------
//Is used to see if a ComedyMovie is greater than or equal to 
//another ComedyMovie. This uses the == and > operator.
//---------------------------------------------------------------
bool ComedyMovie::operator>=(const ComedyMovie& other) const
{
	return (*this == other || *this > other);
}

//----------------------------print------------------------------
//Prints a ComedyMovies to a stream. The Movie's stock, director,
//title, and release year are displayed.
//---------------------------------------------------------------
void ComedyMovie::print(std::ostream& outStream) const
{
	outStream << getStock() << ", " << getDirector() << 
		", " << getTitle() << ", " << getReleaseYear();
}

//----------------------------read-------------------------------
//Reads a ComedyMovie from a stream. The values are read from the
//stream and used to set the ComedyMovie's values.
//---------------------------------------------------------------
void ComedyMovie::read(std::istream& inStream)
{
	//declares the placeholders
	int s = 0;
	std::string dir = "";
	std::string title = "";
	int year = MIN_YEAR;

	//reads in the stock
	inStream >> s;
	//discard meaningless characters
	inStream.get();
	inStream.get();
	
	//get the director
	getline(inStream, dir, ',');
	//discard blank space
	inStream.get();

	//read in the title
	getline(inStream, title, ',');
	//discard blank space
	inStream.get();

	//read in year
	inStream >> year;

	//set all values
	setStock(s);
	setDirector(dir);
	setTitle(title);
	setReleaseYear(year);
} //end read

//------------------------isComedyMovie---------------------------
//Static method is used to see if a Movie object is a ComedyMovie.
//This uses a dynamic cast to see if the Movie object can be cast
//into a ComedyMovie. If it can, the pointer will not be NULL, if
//it can't the pointer will be NULL.
//----------------------------------------------------------------
bool ComedyMovie::isComedyMovie(const Movie* movie)
{
	//tries to cast movie to a ComedyMovie
	const ComedyMovie* cast = dynamic_cast<const ComedyMovie*>(movie);

	//returns true if the pointer is not NULL, false otherwise
	return (cast != NULL);
}

//----------------------------operator==-------------------------
//Provides another equality operator that takes in a Movie
//object. Therefore, the movie object needs to be cast into a 
//ComedyMovie before being compared. If it cannot be, false is
//returned.
//---------------------------------------------------------------
bool ComedyMovie::operator==(const Movie& other) const
{
	/*
	Checks to see if other is a ComedyMovie
	*/
	if (ComedyMovie::isComedyMovie(&other))
	{
		//cast other and use the opertor== for ComedyMovies
		return *this == *(dynamic_cast<const ComedyMovie*>(&other));
	}

	//other is not a ComedyMovie, so return false
	return false;
}

//----------------------------operator!=-------------------------
//Provides another inequality operator that takes in a Movie
//object. Therefore, the movie object needs to be cast into a 
//ComedyMovie before being compared. If it cannot be, false is
//returned.
//---------------------------------------------------------------
bool ComedyMovie::operator!=(const Movie& other) const
{
	/*
	Checks to see if other is a ComedyMovie
	*/
	if (ComedyMovie::isComedyMovie(&other))
	{
		//cast other and use the opertor!= for ComedyMovies
		return *this != *(dynamic_cast<const ComedyMovie*>(&other));
	}
	//other is not a ComedyMovie, so return false
	return false;
}

//----------------------------operator<--------------------------
//Provides another less than operator that takes in a Movie
//object. Therefore, the movie object needs to be cast into a 
//ComedyMovie before being compared. If it cannot be, false is
//returned.
//---------------------------------------------------------------
bool ComedyMovie::operator<(const Movie& other) const
{
	/*
	Checks to see if other is a ComedyMovie
	*/
	if (ComedyMovie::isComedyMovie(&other))
	{
		//cast other and use the opertor< for ComedyMovies
		return *this < *(dynamic_cast<const ComedyMovie*>(&other));
	}
	//other is not a ComedyMovie, so return false
	return false;
}

//----------------------------operator<=-------------------------
//Provides another equal to or less than operator that takes in 
//a Movie object. Therefore, the movie object needs to be cast 
//into a ComedyMovie before being compared. If it cannot be, 
//false is returned.
//---------------------------------------------------------------
bool ComedyMovie::operator<=(const Movie& other) const
{
	/*
	Checks to see if other is a ComedyMovie
	*/
	if (ComedyMovie::isComedyMovie(&other))
	{
		//cast other and use the opertor<= for ComedyMovies
		return *this <= *(dynamic_cast<const ComedyMovie*>(&other));
	}
	//other is not a ComedyMovie, so return false
	return false;
}

//----------------------------operator>--------------------------
//Provides another greater than operator that takes in a Movie
//object. Therefore, the movie object needs to be cast into a 
//ComedyMovie before being compared. If it cannot be, false is
//returned.
//---------------------------------------------------------------
bool ComedyMovie::operator>(const Movie& other) const
{
	/*
	Checks to see if other is a ComedyMovie
	*/
	if (ComedyMovie::isComedyMovie(&other))
	{
		//cast other and use the opertor> for ComedyMovies
		return *this > *(dynamic_cast<const ComedyMovie*>(&other));
	}
	//other is not a ComedyMovie, so return false
	return false;
}

//----------------------------operator>=-------------------------
//Provides another equal to or greater than operator that takes  
//in a Movie object. Therefore, the movie object needs to be 
//cast into a ComedyMovie before being compared. If it cannot be, 
//false is returned.
//---------------------------------------------------------------
bool ComedyMovie::operator>=(const Movie& other) const
{
	/*
	Checks to see if other is a ComedyMovie
	*/
	if (ComedyMovie::isComedyMovie(&other))
	{
		//cast other and use the opertor>= for ComedyMovies
		return *this >= *(dynamic_cast<const ComedyMovie*>(&other));
	}
	//other is not a ComedyMovie, so return false
	return false;
}
#endif
