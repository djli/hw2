#include <sstream>
#include <iomanip>
#include <string>
#include "movie.h"
#include <iostream>

using namespace std;

Movie::Movie(const std::string category, const std::string name, double price, int qty, const string genre, const string rating) : Product(category, name, price, qty)
{
	genre_ = genre;
	rating_ = rating;
}

Movie::~Movie(){

}

set<string> Movie::keywords(){
	set<string> temp;

	keys = parseStringToWords(name_);
	temp = parseStringToWords(category_);
	setIntersection(keys, temp);
	temp = parseStringToWords(genre_);
	setIntersection(keys, temp);

	return keys;
}

string Movie::displayString(){
	dString = "Category: " + category_ + "\nName: " + name_ + "\nPrice: " + 
						to_string(price_) + "\nQuantity: " + to_string(qty_) + "\nGenre: " 
						+ genre_ + "\nRating: " + rating_ + '\n';
	return dString;
}

void Movie::dump(std::ostream& os) const{
	os << category_ << endl << name_ << endl << price_ << endl << qty_ << endl
	<< genre_ << endl << rating_ << endl;
}