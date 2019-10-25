#ifndef BAYES_FIELD_HPP_
#define BAYES_FIELD_HPP_

#include <string>

class Field {
public:
	Field(const std::string& name): name{name} {};
private:
	std::string name;
};


#endif /* BAYES_FIELD_HPP_ */
