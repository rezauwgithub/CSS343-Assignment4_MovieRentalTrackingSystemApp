//80 Character Limit
//********//********//********//********//********//********//********//********

//----------------------------ClassicMovie.cpp-----------------------
//By: Reza Naeemi
//Created: 11/05/2016
//Last Edited: 11/26/2016
//-------------------------------------------------------------------

#ifndef CLASSIC_MOVIE_CPP
#define CLASSIC_MOVIE_CPP
#include "ClassicMovie.h"

//----------------------------ClassicMovie-----------------------
//Default constructor for ClassicMovies. Uses the Movie 
//constructor to set all values in Movie. ClassicMovie specific
//data is also set to default values.
//---------------------------------------------------------------
ClassicMovie::ClassicMovie()
	: Movie(0, "", "", MIN_YEAR, CLASSIC, DVD)
{
	releaseMonth = 1;
	actorFirstName = "";
	actorLastName = "";
}

//----------------------------ClassicMovie-----------------------
//Constructor is used to set all values of ClassicMovie.
//---------------------------------------------------------------
ClassicMovie::ClassicMovie(int s, const std::string& dir,
const std::string& title, int year, MovieMedium m, int releaseMonth,
const std::string& first, const std::string& last)
	: Movie(s, dir, title, year, CLASSIC, m)
{
	this->releaseMonth = releaseMonth;
	actorFirstName = first;
	actorLastName = last;
}

//----------------------------~ClassicMovie----------------------
//No dynamic memory is used by ClassicMovie, so nothing needs to
//be deleted.
//---------------------------------------------------------------
ClassicMovie::~ClassicMovie()
{
}

//----------------------getActorFirstName------------------------
//Returns the first name of the actor.
//---------------------------------------------------------------
std::string ClassicMovie::getActorFirstName() const
{
	return actorFirstName;
}

//----------------------setActorFirstName------------------------
//Sets the first name of the actor and returns true.
//---------------------------------------------------------------
bool ClassicMovie::setActorFirstName(const std::string& name)
{
	actorFirstName = name;
	return true;
}

//-------------------------getActorLastName-----------------------
//Default constructor for ClassicMovies. Uses the Movie 
//constructor to set all values in Movie. ClassicMovie specific
//data is also set to default values.
//---------------------------------------------------------------
std::string ClassicMovie::getActorLastName() const
{
	return actorLastName;
}

//------------------------setActorLastName-----------------------
//Sets the last name of the actor and returns true.
//---------------------------------------------------------------
bool ClassicMovie::setActorLastName(const std::string& name)
{
	actorLastName = name;
	return true;
}

//------------------------getReleaseMonth-----------------------
//Returns the release month of the movie.
//---------------------------------------------------------------
int ClassicMovie::getReleaseMonth() const
{
	return releaseMonth;
}

//---------------------------setReleaseMonth---------------------
//Default constructor for ClassicMovies. Uses the Movie 
//constructor to set all values in Movie. ClassicMovie specific
//data is also set to default values.
//---------------------------------------------------------------
bool ClassicMovie::setReleaseMonth(int m)
{
	/*
	Makes sure the month is a valid month identifier 
	(between 1 and 12). If not, it is set to 1 by 
	default and false is returned.
	*/
	bool retval = true;
	if (m < 1 || m > 12)
	{
		retval = false;
		m = 1;
	}

	releaseMonth = m;
	return retval;
}

//---------------------------print-------------------------------
//Prints the classic movies information to the outStream.
//---------------------------------------------------------------
void ClassicMovie::print(std::ostream& outStream) const
{
	outStream << getStock() << ", " << getDirector() << ", " << getTitle() <<
		", " << getActorFirstName() << " " << getActorLastName() << " " <<
				getReleaseMonth() << " " << getReleaseYear();
}

//---------------------------read--------------------------------
//Reads data from the in stream and applies it to the classic 
//movie.
//---------------------------------------------------------------
void ClassicMovie::read(std::istream& inStream)
{
	//initializes all placeholding variables.
	int s = 0;
	std::string dir = "";
	std::string title = "";
	std::string actorFirst = "";
	std::string actorLast = "";
	int month = 1;
	int year = MIN_YEAR;

	//reads in the stock
	inStream >> s;
	//discards two pointless values
	inStream.get();
	inStream.get();

	//gets the director
	getline(inStream, dir, ',');
	//dicards the space
	inStream.get();

	//gets the title
	getline(inStream, title, ',');
	//discards the space
	inStream.get();

	//gets the actor information and the month and year
	inStream >> actorFirst >> actorLast >> month >> year;

	//sets all the values
	setStock(s);
	setDirector(dir);
	setTitle(title);
	setActorFirstName(actorFirst);
	setActorLastName(actorLast);
	setReleaseMonth(month);
	setReleaseYear(year);
} //end read

//---------------------------operator<<--------------------------
//Prints the classic movie to the stream using the print method.
//The stream is then returned.
//---------------------------------------------------------------
std::ostream& operator<<(std::ostream& outStream, const ClassicMovie& classic)
{
	classic.print(outStream);
	return outStream;
}

//---------------------------operator>>--------------------------
//Reads in data using the inStream. This calls the read method
//of the classic movie. The stream is then returned.
//---------------------------------------------------------------
std::istream& operator>>(std::istream& inStream, ClassicMovie& classic)
{
	classic.read(inStream);
	return inStream;
}

//---------------------------operator==--------------------------
//Compares two classic movies for equality. The assignment specs
//imply that classic movies can be the same if they have the same
//actor and release date, or if they have the same title and 
//director. Therefore, either of the two conditions have to be
//true for equality.
//---------------------------------------------------------------
bool ClassicMovie::operator==(const ClassicMovie& other) const
{
	return (getActorFirstName() == other.getActorFirstName() && 
			getActorLastName()  == other.getActorLastName()  && 
			getReleaseMonth()   == other.getReleaseMonth()   && 
			getReleaseYear()    == other.getReleaseYear())   || 
		   (getDirector()       == other.getDirector()       && 
		    getTitle()          == other.getTitle()          );
}

//---------------------------operator!=--------------------------
//Compares two classic movies for inequality. This negates the 
//result from the operator== method.
//---------------------------------------------------------------
bool ClassicMovie::operator!=(const ClassicMovie& other) const
{
	return !(*this == other);
}

//---------------------------operator<---------------------------
//Compares two classic movies to see if the first one is less 
//than the first. This is defined by the release year, month, 
//actor last name, and actor first name in that order.
//---------------------------------------------------------------
bool ClassicMovie::operator<(const ClassicMovie& other) const
{
	/*
	If the years are the same, the next level (month) must
	be evaluated.
	*/
	if (getReleaseYear() == other.getReleaseYear())
	{
		/*
		If months are the same, the next level (actor last name)
		must be compared.
		*/
		if (getReleaseMonth() == other.getReleaseMonth())
		{
			/*
			If actor last names are the same, the next level
			(actor first name) must be compared.
			*/
			if (getActorLastName() == other.getActorLastName())
			{
				//compares actor first name
				return getActorFirstName() < other.getActorFirstName();
			}
			//compares actor last name
			return getActorLastName() < other.getActorLastName();
		}
		//compares month
		return getReleaseMonth() < other.getReleaseMonth();
	}
	//compares year
	return  getReleaseYear() < other.getReleaseYear();
} 

//---------------------------operator<=--------------------------
//Compares two classic movies to see if the first one is less 
//or equal to the first.
//---------------------------------------------------------------
bool ClassicMovie::operator<=(const ClassicMovie& other) const
{
	return (*this == other || *this < other);
}

//---------------------------operator>---------------------------
//Compares two classic movies to see if the first one is greater
//than the first. This is defined by the release year, month, 
//actor last name, and actor first name in that order.
//---------------------------------------------------------------
bool ClassicMovie::operator>(const ClassicMovie& other) const
{
	/*
	If the years are the same, the next level (month) must
	be evaluated.
	*/
	if (getReleaseYear() == other.getReleaseYear())
	{
		/*
		If months are the same, the next level (actor last name)
		must be compared.
		*/
		if (getReleaseMonth() == other.getReleaseMonth())
		{
			/*
			If actor last names are the same, the next level
			(actor first name) must be compared.
			*/
			if (getActorLastName() == other.getActorLastName())
			{
				//compares the actor's first name
				return getActorFirstName() > other.getActorFirstName();
			}
			//compares the actor's last name
			return getActorLastName() > other.getActorLastName();
		}
		//compares the months
		return getReleaseMonth() > other.getReleaseMonth();
	}
	//compares the years
	return  getReleaseYear() > other.getReleaseYear();
}

//---------------------------operator<=--------------------------
//Compares two classic movies to see if the first one is less 
//or equal to the first.
//---------------------------------------------------------------
bool ClassicMovie::operator>=(const ClassicMovie& other) const
{
	return (*this == other || *this > other);
}

//---------------------------isClassicMovie----------------------
//Checks to see if a movie object is a classic movie.
//---------------------------------------------------------------
bool ClassicMovie::isClassicMovie(const Movie* movie)
{
	//attempts to dynamically cast movie into a ClassicMovie.
	const ClassicMovie* cast = dynamic_cast<const ClassicMovie*>(movie);

	//if cast is not null, the cast worked so movie is a classic
	//movie. Otherwise, it is not a classic movie.
	return (cast != NULL);
}

//---------------------------operator==--------------------------
//Allows a generl movie object to be compared with a classic
//movie. But first, the movie has to be cast into a classic movie
//in order to text for equality. If movie is not a classic movie, 
//false is returned.
//---------------------------------------------------------------
bool ClassicMovie::operator==(const Movie& other) const
{
	/*
	checks to make sure other is a classic movie 
	before they can be comared.
	*/
	if (ClassicMovie::isClassicMovie(&other))
	{
		return *this == *(dynamic_cast<const ClassicMovie*>(&other));
	}

	return false;
}

//---------------------------operator!=--------------------------
//Allows a generl movie object to be compared with a classic
//movie. But first, the movie has to be cast into a classic movie
//in order to text for inequality. If movie is not a classic 
//movie, false is returned.
//---------------------------------------------------------------
bool ClassicMovie::operator!=(const Movie& other) const
{
	/*
	checks to make sure other is a classic movie 
	before they can be comared.
	*/
	if (ClassicMovie::isClassicMovie(&other))
	{
		return *this != *(dynamic_cast<const ClassicMovie*>(&other));
	}

	return false;
}

//---------------------------operator<---------------------------
//Allows a generl movie object to be compared with a classic
//movie. But first, the movie has to be cast into a classic movie
//in order to text for inequality. If movie is not a classic 
//movie, false is returned.
//---------------------------------------------------------------
bool ClassicMovie::operator<(const Movie& other) const
{
	/*
	checks to make sure other is a classic movie 
	before they can be comared.
	*/
	if (ClassicMovie::isClassicMovie(&other))
	{
		return *this < *(dynamic_cast<const ClassicMovie*>(&other));
	}

	return false;
}

//---------------------------operator<=--------------------------
//Allows a generl movie object to be compared with a classic
//movie. But first, the movie has to be cast into a classic movie
//in order to text for inequality. If movie is not a classic 
//movie, false is returned.
//---------------------------------------------------------------
bool ClassicMovie::operator<=(const Movie& other) const
{
	/*
	checks to make sure other is a classic movie 
	before they can be comared.
	*/
	if (ClassicMovie::isClassicMovie(&other))
	{
		return *this <= *(dynamic_cast<const ClassicMovie*>(&other));
	}

	return false;
}

//---------------------------operator>---------------------------
//Allows a generl movie object to be compared with a classic
//movie. But first, the movie has to be cast into a classic movie
//in order to text for inequality. If movie is not a classic 
//movie, false is returned.
//---------------------------------------------------------------
bool ClassicMovie::operator>(const Movie& other) const
{
	/*
	checks to make sure other is a classic movie 
	before they can be comared.
	*/
	if (ClassicMovie::isClassicMovie(&other))
	{
		return *this > *(dynamic_cast<const ClassicMovie*>(&other));
	}

	return false;
}

//---------------------------operator>=--------------------------
//Allows a generl movie object to be compared with a classic
//movie. But first, the movie has to be cast into a classic movie
//in order to text for inequality. If movie is not a classic 
//movie, false is returned.
//---------------------------------------------------------------
bool ClassicMovie::operator>=(const Movie& other) const
{
	/*
	checks to make sure other is a classic movie 
	before they can be comared.
	*/
	if (ClassicMovie::isClassicMovie(&other))
	{
		return *this >= *(dynamic_cast<const ClassicMovie*>(&other));
	}

	return false;
}

#endif
