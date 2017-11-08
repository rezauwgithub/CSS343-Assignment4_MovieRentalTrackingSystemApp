//80 Character Limit
//********//********//********//********//********//********//********//********

//----------------------------DramaMovie.cpp-------------------------
//By: Reza Naeemi
//Created: 11/05/2016
//Last Edited: 12/14/2016
//-------------------------------------------------------------------

#ifndef DRAMA_MOVIE_CPP
#define DRAMA_MOVIE_CPP
#include "DramaMovie.h"
//----------------------------DramaMovie-------------------------
//Default constructor for DramaMovies. Uses the Movie 
//constructor to set all values in Movie.
//---------------------------------------------------------------
DramaMovie::DramaMovie() 
	: Movie(0, "", "", MIN_YEAR, DRAMA, DVD)
{
}

//----------------------------DramaMovie-------------------------
//Constructor sets all values specified by creator. The Movie
//constructor is used as well.
//---------------------------------------------------------------
DramaMovie::DramaMovie(int s, const std::string& dir, 
const std::string& title, int year, MovieMedium m)
	: Movie(s, dir, title, year, DRAMA, m)
{

}

//----------------------------~DramaMovie------------------------
//Destructor doesn't delete anything as now dynamic memory is 
//used.
//---------------------------------------------------------------
DramaMovie::~DramaMovie()
{
}

//----------------------------operator<<-------------------------
//Overloads the output operator to display a DramaMovie to the
//screen. Uses the private print method of the drama class. The
//Stream is then returned.
//---------------------------------------------------------------
std::ostream& operator<<(std::ostream& outStream, const DramaMovie& drama)
{
	drama.print(outStream);
	return outStream;
}

//----------------------------operator>>-------------------------
//Overloads the input operator to read into a DramaMovie. 
//Uses the private read method of the drama class. The
//Stream is then returned.
//---------------------------------------------------------------
std::istream& operator>>(std::istream& inStream, DramaMovie& drama)
{
	drama.read(inStream);
	return inStream;
}

//----------------------------print------------------------------
//Prints a DramaMovies to a stream. The Movie's stock, director,
//title, and release year are displayed.
//---------------------------------------------------------------
void DramaMovie::print(std::ostream& outStream) const
{
	outStream << getStock() << ", " << getDirector() << ", "
			  << getTitle() << ", " << getReleaseYear();
}

//----------------------------read-------------------------------
//Reads a DramaMovie from a stream. The values are read from the
//stream and used to set the DramaMovie's values.
//---------------------------------------------------------------
void DramaMovie::read(std::istream& inStream)
{
	//initialize Placeholders
	int s = 0;
	std::string dir = "";
	std::string title = "";
	int year = MIN_YEAR;

	//read the stock
	inStream >> s;
	//discard meaningless values
	inStream.get();
	inStream.get();
	
	//read the director
	getline(inStream, dir, ',');
	//discards space
	inStream.get();

	//gets the title
	getline(inStream, title, ',');
	//discards space
	inStream.get();

	//reads the year
	inStream >> year;

	//sets values
	setStock(s);
	setDirector(dir);
	setTitle(title);
	setReleaseYear(year);
} //end read

//----------------------------operator==-------------------------
//Overloads the equality operator to check if two DramaMovie
//objects are the same. DramaMovie objects are compared by
//the director and title.
//---------------------------------------------------------------
bool DramaMovie::operator==(const DramaMovie& other) const
{
	return (getDirector() == other.getDirector() &&
			getTitle()    == other.getTitle()    );
}

//----------------------------operator!=-------------------------
//Overloads the inequality operator to check if two DramaMovie
//objects are not the same. DramaMovie objects are compared by
//the director and title.
//---------------------------------------------------------------
bool DramaMovie::operator!=(const DramaMovie& other) const
{
	return !(*this == other);
}

//----------------------------operator<--------------------------
//Overloads the less than operator to check if a DramaMovie
//is less than another. DramaMovie objects are compared by
//the director and title, in that order.
//---------------------------------------------------------------
bool DramaMovie::operator<(const DramaMovie& other) const
{
	/*
	Checks to see if directors are the same, 
	if so, titles need to be compared.
	*/
	if (getDirector() == other.getDirector())
	{
		//compares titles
		return getTitle() < other.getTitle();
	}
	//compares directors
	return getDirector() < other.getDirector();
}

//----------------------------operator<=-------------------------
//Is used to see if a DramaMovie is less than or equal to 
//another DramaMovie. This uses the == and < operator.
//---------------------------------------------------------------	
bool DramaMovie::operator<=(const DramaMovie& other) const
{
	return (*this == other || *this < other);
}

//----------------------------operator<--------------------------
//Overloads the greater than operator to check if a DramaMovie
//is less than another. DramaMovie objects are compared by
//the director and title, in that order.
//---------------------------------------------------------------
bool DramaMovie::operator>(const DramaMovie& other) const
{
	/*
	Checks to see if directors are the same, 
	if so, titles need to be compared.
	*/
	if (getDirector() == other.getDirector())
	{
		//compares titles
		return getTitle() > other.getTitle();
	}
	//compares directors
	return getDirector() > other.getDirector();
}

//----------------------------operator>=-------------------------
//Is used to see if a DramaMovie is less than or equal to 
//another DramaMovie. This uses the == and < operator.
//---------------------------------------------------------------
bool DramaMovie::operator>=(const DramaMovie& other) const
{
	return (*this == other || *this > other);
}

//------------------------isDramaMovie---------------------------
//Static method is used to see if a Movie object is a DramaMovie.
//This uses a dynamic cast to see if the Movie object can be cast
//into a DramaMovie. If it can, the pointer will not be NULL, if
//it can't the pointer will be NULL.
//----------------------------------------------------------------
bool DramaMovie::isDramaMovie(const Movie* movie)
{
	//tries to cast movie to a ComedyMovie
	const DramaMovie* cast = dynamic_cast<const DramaMovie*>(movie);
	//returns true if the pointer is not NULL, false otherwise
	return (cast != NULL);
}

//----------------------------operator==-------------------------
//Provides another equality operator that takes in a Movie
//object. Therefore, the movie object needs to be cast into a 
//DramaMovie before being compared. If it cannot be, false is
//returned.
//---------------------------------------------------------------
bool DramaMovie::operator==(const Movie& other) const
{
	/*
	Checks to see if other is a DramaMovie
	*/
	if (DramaMovie::isDramaMovie(&other))
	{
		//cast other and use the opertor== for DramaMovies
		return *this == *(dynamic_cast<const DramaMovie*>(&other));
	}
	//other is not a DramaMovie, so return false
	return false;
}

//----------------------------operator!=-------------------------
//Provides another inequality operator that takes in a Movie
//object. Therefore, the movie object needs to be cast into a 
//DramaMovie before being compared. If it cannot be, false is
//returned.
//---------------------------------------------------------------
bool DramaMovie::operator!=(const Movie& other) const
{
	/*
	Checks to see if other is a DramaMovie
	*/
	if (DramaMovie::isDramaMovie(&other))
	{
		//cast other and use the opertor!= for DramaMovies
		return *this != *(dynamic_cast<const DramaMovie*>(&other));
	}
	//other is not a DramaMovie, so return false
	return false;
}

//----------------------------operator<--------------------------
//Provides another less than operator that takes in a Movie
//object. Therefore, the movie object needs to be cast into a 
//DramaMovie before being compared. If it cannot be, false is
//returned.
//---------------------------------------------------------------
bool DramaMovie::operator<(const Movie& other) const
{
	/*
	Checks to see if other is a DramaMovie
	*/
	if (DramaMovie::isDramaMovie(&other))
	{
		//cast other and use the opertor< for DramaMovies
		return *this < *(dynamic_cast<const DramaMovie*>(&other));
	}
	//other is not a DramaMovie, so return false
	return false;
}

//----------------------------operator<=-------------------------
//Provides another equal to or less than operator that takes in 
//a Movie object. Therefore, the movie object needs to be cast 
//into a DramaMovie before being compared. If it cannot be, 
//false is returned.
//---------------------------------------------------------------
bool DramaMovie::operator<=(const Movie& other) const
{
	/*
	Checks to see if other is a DramaMovie
	*/
	if (DramaMovie::isDramaMovie(&other))
	{
		//cast other and use the opertor<= for DramaMovies
		return *this <= *(dynamic_cast<const DramaMovie*>(&other));
	}
	//other is not a DramaMovie, so return false
	return false;
}

//----------------------------operator>--------------------------
//Provides another greater than operator that takes in a Movie
//object. Therefore, the movie object needs to be cast into a 
//DramaMovie before being compared. If it cannot be, false is
//returned.
//---------------------------------------------------------------
bool DramaMovie::operator>(const Movie& other) const
{
	/*
	Checks to see if other is a DramaMovie
	*/
	if (DramaMovie::isDramaMovie(&other))
	{
		//cast other and use the opertor> for DramaMovies
		return *this > *(dynamic_cast<const DramaMovie*>(&other));
	}
	//other is not a DramaMovie, so return false
	return false;
}

//----------------------------operator>=-------------------------
//Provides another equal to or greater than operator that takes  
//in a Movie object. Therefore, the movie object needs to be 
//cast into a DramaMovie before being compared. If it cannot be, 
//false is returned.
//---------------------------------------------------------------
bool DramaMovie::operator>=(const Movie& other) const
{
	/*
	Checks to see if other is a DramaMovie
	*/
	if (DramaMovie::isDramaMovie(&other))
	{
		//cast other and use the opertor>= for DramaMovies
		return *this >= *(dynamic_cast<const DramaMovie*>(&other));
	}
	//other is not a DramaMovie, so return false
	return false;
}
#endif
