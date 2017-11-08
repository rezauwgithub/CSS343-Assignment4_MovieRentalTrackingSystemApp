//80 Character Limit
//********//********//********//********//********//********//********//********

//----------------------------Movie------------------------------
//Movie is a base class for the entire movie hierarchy. Movie, 
//therefore, provides fields and functions that are common 
//across all Movie objects (subclasses). This includes the stock, 
//the director, the title, release year, type, and medium.
//---------------------------------------------------------------
//By: Reza Naeemi
//Created: 11/05/2016
//Last Edited: 12/14/2016
//---------------------------------------------------------------
#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include <iostream>

/*
Provided to help identify different types of movies
*/
enum MovieType
{
	COMEDY = 0,
	DRAMA = 1,
	CLASSIC = 2,
	NUMBER_OF_TYPES = 3
};

/*
Provided to identify different mediums that movies can have.
Only one is defined since there is only one medium in the
assignment specifications.
*/
enum MovieMedium
{
	DVD = 0,
	NUMBER_OF_MEDIUMS = 1
};

//assuming no movie was created before the year 1800
const int MIN_YEAR = 1800;

class Movie
{
	//overloads the output operator
	friend std::ostream& operator<<(std::ostream& outStream,
		const Movie& movie);
	//overloads the input operator
	friend std::istream& operator>>(std::istream& inStream, Movie& movie);
public:

	//default constructor sets all default values
	Movie();
	//used to set all values to corresponding argument values
	Movie(int s, const std::string& dir, const std::string& title, int year,
		MovieType t, MovieMedium m);
	//virtual destructor deletes all dynamic memory and allows polymorphism
	virtual ~Movie();

	//returns the stock of the movie
	int getStock() const;
	//set the stock of the movie (cannot be below 0)
	bool setStock(int s);
	//increases the stock by amount (amount cannot be negative)
	bool increaseStock(int amount);
	//increases the stock by 1
	bool incrementStock();
	//decreases the stock by amount (only if there is enough
	//stock to do this) (amount cannot be negative)
	bool decreaseStock(int amount);
	//decreases stock by 1 (only if there is enough in stock)
	bool decrementStock();

	//determines whether or not there is at least 1 movie in stock
	bool inStock() const;
	//determines whether or not there is at least amount in stock
	bool hasSufficientStock(int amount) const;

	//returns the title of the movie
	std::string getTitle() const;
	//sets the title of the movie
	bool setTitle(const std::string& title);

	//gets the director of the movie
	std::string getDirector() const;
	//sets the director of the movie
	bool setDirector(const std::string& dir);

	//gets the release year of the movie
	int getReleaseYear() const;
	//sets the release year of the movie
	bool setReleaseYear(int year);

	//gets the type of the movie
	MovieType getMovieType() const;
	//note: no setter is provided. This is because
	//I do not want derived classes to be able to 
	//change their type. This would cause problems.
	//Therefore, the movie is constructed with the type
	//and it can never change.

	//gets the medium of the movie
	MovieMedium getMedium() const;
	//set the medium of the movie
	bool setMedium(MovieMedium medium);

	//compares two movies for equality
	virtual bool operator==(const Movie& other) const = 0;
	//compares two movies for inequality
	virtual bool operator!=(const Movie& other) const = 0;
	
	//compares two movies to determine if the first is 
	//less than the second
	virtual bool operator<(const Movie& other) const = 0;
	//compares two movies to determine if the first is 
	//less than or equal to the second
	virtual bool operator<=(const Movie& other) const = 0;

	//compares two movies to determine if the first is 
	//greater than the second
	virtual bool operator>(const Movie& other) const = 0;
	//compares two movies to determine if the first is 
	//greater than or equal to the second
	virtual bool operator>=(const Movie& other) const = 0;

private:
	int stock;
	std::string director;
	std::string title;
	int releaseYear;
	MovieType type;
	MovieMedium medium;

	//defines a pure virtual print method that all subclasses
	//must override
	virtual void print(std::ostream& outStream) const = 0;
	//defines a pure virtual read method that all subclasses
	//must override
	virtual void read(std::istream& inStream) = 0;
};

#endif
