#include <sstream>
#include <iomanip>
#include <string>
#include "book.h"
#include <iostream>

using namespace std;

Book::Book(const std::string category, const std::string name, double price, int qty, const string author, const string isbn) : Product(category, name, price, qty)
{
	author_ = author;
	isbn_ = isbn;
}

Book::~Book(){

}

set<string> Book::keywords(){
	set<string> temp;

	keys = parseStringToWords(name_);
	temp = parseStringToWords(category_);
	setIntersection(keys, temp);
	temp = parseStringToWords(author_);
	setIntersection(keys, temp);
	keys.insert(isbn_);

	return keys;
}

string Book::displayString(){
	dString = "Category: " + category_ + "\nName: " + name_ + "\nPrice: " + 
						to_string(price_) + "\nQuantity: " + to_string(qty_) + "\nISBN: " + isbn_ + "\nAuthor: " 
						+ author_ + '\n';
	return dString;
}

void Book::dump(std::ostream& os) const{
	os << category_ << endl << name_ << endl << price_ << endl << qty_ << endl
	<< isbn_ << endl << author_ << endl;
}