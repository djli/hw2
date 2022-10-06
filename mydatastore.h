#include "util.h"
#include "datastore.h"
#include <iostream>
#include <fstream>

class DatAssTore : public DataStore{
public:
	DatAssTore();
	~DatAssTore();
	void addProduct(Product* p);
	void addUser(User* u);
	std::vector<Product*> search(std::vector<std::string>& terms, int type);
	void dump(std::ostream& ofile);

protected:
	std::set<Product*> products;
	std::set<User*> users;
};