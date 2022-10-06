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

set<string> Book::keywords() const{
	set<string>* words = new set<string>;
	set<string> temp;

	*words = parseStringToWords(name_);
	temp = parseStringToWords(category_);
	setIntersection(*words, temp);
	temp = parseStringToWords(author_);
	setIntersection(*words, temp);
	words->insert(isbn_);

	return *words;
}

bool Book::isMatch(vector<string>& searchTerms) const{
	return false;
}

string Book::displayString() const{
	string* fstring = new string;
	*fstring = "Category: " + category_ + "\nName: " + name_ + "\nPrice: " + 
						to_string(price_) + "\nQuantity: " + to_string(qty_) + "\nISBN: " + isbn_ + "\nAuthor: " 
						+ author_ + '\n';
	return *fstring;
}

void Book::dump(std::ostream& os) const{
	os << category_ << endl << name_ << endl << price_ << endl << qty_ << endl
	<< isbn_ << endl << author_ << endl;
}