#include <sstream>
#include <iomanip>
#include <string>
#include "clothing.h"
#include <iostream>

using namespace std;

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, const string size, const string brand) : Product(category, name, price, qty)
{
	size_ = size;
	brand_ = brand;
}

Clothing::~Clothing(){

}

set<string> Clothing::keywords() const{
	set<string>* words = new set<string>;
	set<string> temp;

	*words = parseStringToWords(name_);
	temp = parseStringToWords(category_);
	setIntersection(*words, temp);
	temp = parseStringToWords(brand_);
	setIntersection(*words, temp);

	return *words;
}

bool Clothing::isMatch(vector<string>& searchTerms) const{
	return false;
}

string Clothing::displayString() const{
	string* fstring = new string;
	*fstring = "Category: " + category_ + "\nName: " + name_ + "\nPrice: " + 
						to_string(price_) + "\nQuantity: " + to_string(qty_) + "\nSize: " + size_ + "\nBrand: " 
						+ brand_ + '\n';
	return *fstring;
}

void Clothing::dump(std::ostream& os) const{
	os << category_ << endl << name_ << endl << price_ << endl << qty_ << endl << size_ << endl
	<< brand_ << endl;
}