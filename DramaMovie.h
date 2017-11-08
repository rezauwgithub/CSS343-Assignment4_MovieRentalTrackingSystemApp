//80 Character Limit
//********//********//********//********//********//********//********//********

//----------------------------DramaMovie-----------------------
//DramaMovie is a subclass of Movie. DramaMovie is not complex
//and therefore, requires no more variables than those that 
//are provided by Movie. However, DramaMovie does need to 
//implement comparison operators and override inherited 
//virtual functions to provide a proper implementation.
//
//Note: According to Assignment Specifications, DramaMovies
//are sorted by director and title, therefore, these attributes
//are used for the <, <=, >, and >= operators.
//---------------------------------------------------------------
//By: Reza Naeemi
//Created: 11/05/2016
//Last Edited: 12/14/2016
//---------------------------------------------------------------
#ifndef DRAMA_MOVIE_H
#define DRAMA_MOVIE_H
#include "Movie.h"

class DramaMovie : public Movie
{
	//overloads the output operator
	friend std::ostream& operator<<(std::ostream& outStream,
		const DramaMovie& drama);
	//overloads the input operator
	friend std::istream& operator>>(std::istream& inStream, DramaMovie& drama);

public:
	//default constructor sets all values to default values
	DramaMovie();
	//sets all values to the specified arguments
	DramaMovie(int s, const std::string& dir, const std::string& title,
		int year, MovieMedium m);
	//deletes all dynamic memory (none is used for this class)
	~DramaMovie();

	//compares two DramaMovies for equality
	bool operator==(const DramaMovie& other) const;
	//compares two DramaMovies for inequality
	bool operator!=(const DramaMovie& other) const;

	//compares two DramaMovies to see if the first one
	//is less than the second one
	bool operator<(const DramaMovie& other) const;
	//compares two DramaMovies to see if the first one
	//is less than or equal to the second one
	bool operator<=(const DramaMovie& other) const;

	//compares two DramaMovies to see if the first one
	//is greater than the second one
	bool operator>(const DramaMovie& other) const;
	//compares two DramaMovies to see if the first one
	//is greater than or equal to the second one
	bool operator>=(const DramaMovie& other) const;

	//provides a static method that checks a movie
	//to see if it is a DramaMovie
	static bool isDramaMovie(const Movie* movie);

	//overrides the operator== that accepts a Movie object
	bool operator==(const Movie& other) const;
	//overrides the operator!= that accepts a Movie object
	bool operator!=(const Movie& other) const;
	
	//overrides the operator< that accepts a Movie object
	bool operator<(const Movie& other) const;
	//overrides the operator<= that accepts a Movie object
	bool operator<=(const Movie& other) const;
	
	//overrides the operator> that accepts a Movie object
	bool operator>(const Movie& other) const;
	//overrides the operator>= that accepts a Movie object
	bool operator>=(const Movie& other) const;

private:
	//overrides the inherited print method to provide
	//a proper implementation for DramaMovie
	void print(std::ostream& outStream) const;
	//overrides the inherited read method to provide 
	//a proper implementation for DramaMovie
	void read(std::istream& inStream);
};

#endif