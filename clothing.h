#include "product.h"
#include <set>
#include "util.h"

class Clothing : public Product{

public:
	Clothing(const std::string category, const std::string name, double price, int qty, const std::string size, const std::string brand);
	~Clothing();
	std::set<std::string> keywords() const;
	bool isMatch(std::vector<std::string>& searchTerms) const;
	std::string displayString() const;
	void dump(std::ostream& os) const;

protected:
	std::string size_;
	std::string brand_;
	std::string dString;
	std::set<std::string> keys;
};