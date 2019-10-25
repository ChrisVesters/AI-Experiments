#ifndef BAYES_VALUE_HPP_
#define BAYES_VALUE_HPP_

#include <string>

class Value {

};

class DiscreteValue : public Value {
private:
	std::string value;
};

class ContinuousValue : public Value {
private:
	double value;
};



#endif /* BAYES_VALUE_HPP_ */
