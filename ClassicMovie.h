//80 Character Limit
//********//********//********//********//********//********//********//********

//----------------------------ClassicMovie-----------------------
//ClassicMovie is a subclass of Movie as it is a specific type
//of movie. ClassicMovie is one of the more robust and complex
//movie types; therefore, it has some added methods and 
//variables that are not supplied by Movie. It also overrides
//virtual functions from movie to provide proper ClassicMovie
//implementation.
//
//Note: According to Assignment Specifications, ClassicMovies are
//sorted by release date, and actor name. Therefore, these
//attributes are used to determine if one is smaller, or bigger
//than another.
//---------------------------------------------------------------
//By: Reza Naeemi
//Created: 11/05/2016
//Last Edited: 11/26/2016
//---------------------------------------------------------------

#ifndef CLASSIC_MOVIE_H
#define CLASSIC_MOVIE_H
#include "Movie.h"

class ClassicMovie : public Movie
{
	//overloads the output operator
	friend std::ostream& operator<<(std::ostream& outStream,
		const ClassicMovie& classic);
	//overloads the input operator
	friend std::istream& operator>>(std::istream& inStream,
		ClassicMovie& classic);
public:
	//default constructor sets all values to default values.
	ClassicMovie();
	//sets all variables to the value that have been supplied
	ClassicMovie(int s, const std::string& dir, const std::string& title,
		int year, MovieMedium m, int releaseMonth,
		const std::string& first, const std::string& last);
	//deletes all dynamic memory (there isn't any for Movie or ClassicMovie)
	~ClassicMovie();

	//returns actorFirstName
	std::string getActorFirstName() const;
	//sets actorFirstName to name
	bool setActorFirstName(const std::string& name);

	//returns actorLastName
	std::string getActorLastName() const;
	//sets actorLastName
	bool setActorLastName(const std::string& name);

	//returns releaseMonth
	int getReleaseMonth() const;
	//sets releaseMonth
	bool setReleaseMonth(int m);

	//compares two ClassicMovies for equality
	bool operator==(const ClassicMovie& other) const;
	//compares two ClassicMovies for inequality
	bool operator!=(const ClassicMovie& other) const;

	//compares two ClassicMovies to see if the first one
	//is less than the second. Order is defined in the
	//assignment specifications. ClassicMovies are ordered
	//by release year, release month, and actor name. Therefore,
	//these attribute are used to determine if one is smaller
	//than the other.
	bool operator<(const ClassicMovie& other) const;
	//compares two ClassicMovies to see if the first one is 
	//smaller than or equal to the other.
	bool operator<=(const ClassicMovie& other) const;

	//compares two ClassicMovies together to see if the first
	//one is bigger than the second one.
	bool operator>(const ClassicMovie& other) const;
	//compares two ClassicMovies together to see if the first
	//one is bigger or equal to the second one.
	bool operator>=(const ClassicMovie& other) const;

	//checks to see if movie is a classic movie.
	//true is returned if it is, false otherwise.
	static bool isClassicMovie(const Movie* movie);

	//overrides the inherited operator== for movie
	bool operator==(const Movie& other) const;
	//overrides the inherited operator!= for movie
	bool operator!=(const Movie& other) const;
	//overrides the inherited operator< for movie
	bool operator<(const Movie& other) const;
	//overrides the inherited operator<= for movie
	bool operator<=(const Movie& other) const;
	//overrides the inherited operator> for movie
	bool operator>(const Movie& other) const;
	//overrides the inherited operator>= for movie
	bool operator>=(const Movie& other) const;

private:
	int releaseMonth;
	std::string actorFirstName;
	std::string actorLastName;

	//overrides the virtual print function to provide 
	//a print specific to ClassicMovie
	void print(std::ostream& outStream) const;
	//overrides the read method to provide an implementation
	//specific to ClassicMovie.
	void read(std::istream& inStream);
};

#endif


