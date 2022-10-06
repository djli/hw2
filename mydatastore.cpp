#include "mydatastore.h"

using namespace std;

DatAssTore::DatAssTore(){

}

DatAssTore::~DatAssTore(){

}

void DatAssTore::addProduct(Product* p){
	products.insert(p);
}

void DatAssTore::addUser(User* u){
	users.insert(u);
}

vector<Product*> DatAssTore::search(vector<string>& terms, int type){
	vector<Product*>* searchresults = new vector<Product*>();
	set<string> tempWords;
	set<string> tempIntersect;
	for(size_t i = 0; i < terms.size(); i++){
		tempWords.insert(terms[i]);
	}
	set<Product*>::iterator it;

	for(it = products.begin(); it != products.end(); ++it){
		tempIntersect = setIntersection(tempWords, (**it).keywords());
		if(tempIntersect.size() == terms.size() && type == 0){
			searchresults->push_back(*it);
		}
		if(tempIntersect.size() != 0 && type == 1){
			searchresults->push_back(*it);
		}
	}

	return *searchresults;
}

void DatAssTore::dump(ostream& ofile){
	set<Product*>::iterator it;
	set<User*>::iterator ut;

	ofile << "<products>" << endl;

	for(it = products.begin(); it != products.end(); ++it){
		(**it).dump(ofile);
	}

	ofile << "</products>" << endl;
	ofile << "<users>" << endl;

	for(ut = users.begin(); ut != users.end(); ++ut){
		(**ut).dump(ofile);
	}

	ofile << "</users>" << endl;
}