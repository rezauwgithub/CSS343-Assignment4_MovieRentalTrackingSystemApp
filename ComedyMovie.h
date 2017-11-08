//80 Character Limit
//********//********//********//********//********//********//********//********

//----------------------------ComedyMovie-----------------------
//ComedyMovie is a subclass of Movie. Comedy requires no more
//information than what is provided by Movie, therefore, no
//new variables are defined in ComedyMovie. However, 
//ComedyMovie does require overloading operators to test for
//equality and inequality. Also, ComedyMovie must override
//some inherited virtual functions in order to provide the 
//proper ComedyMovie implementation.
//
//Note: According to Assignment Specifications, ComedyMovies
//are sorted by title and year, therefore, these attributes
//are used for the <, <=, >, and >= operators.
//---------------------------------------------------------------
//By: Reza Naeemi
//Created: 11/05/2016
//Last Edited: 11/26/2016
//---------------------------------------------------------------

#ifndef COMEDY_MOVIE_H
#define COMEDY_MOVIE_H
#include "Movie.h"
class ComedyMovie : public Movie
{
	//overloads the output operator
	friend std::ostream& operator<<(std::ostream& outStream,
		const ComedyMovie& comedy);
	//overloads the input operator											
	friend std::istream& operator>>(std::istream& inStream,
		ComedyMovie& comedy);
public:
	//default constructor sets all variables to default values
	ComedyMovie();
	//sets all variables to the specific values
	ComedyMovie(int s, const std::string& dir, const std::string& title,
		int year, MovieMedium m);
	//deletes all dynamic memory (there is none for this class)
	~ComedyMovie();

	//compares two ComedyMovies for equality
	bool operator==(const ComedyMovie& other) const;
	//compares two ComedyMovies for inequality
	bool operator!=(const ComedyMovie& other) const;

	//compares two ComedyMovies to see if the first is
	//less than the second one
	bool operator<(const ComedyMovie& other) const;
	//compares two ComedtMovies to see if the first is
	//less than or equal to the second
	bool operator<=(const ComedyMovie& other) const;

	//compares two ComedyMovies to see if the first one
	//is bigger than the second one
	bool operator>(const ComedyMovie& other) const;
	//compares two ComedyMovies to see if the first one
	//is bigger than or equal to the second one
	bool operator>=(const ComedyMovie& other) const;

	//checks to see if movie is a comedy movie
	static bool isComedyMovie(const Movie* movie);

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
	//overrides the inherited print method to provide the 
	//proper ComedyMovie implementation
	void print(std::ostream& outStream) const;
	//overrides the inherited read method to provide 
	//the proper ComedyMovie implementation
	void read(std::istream& inStream);
};

#endif

