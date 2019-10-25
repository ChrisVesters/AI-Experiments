#include "Examples.hpp"
#include "Object.hpp"
#include "Probability.hpp"

#include <vector>

void probabilityExample() {
	std::vector<Object> dataset2;
	for (int i = 0; i < 100; ++i) {
		Object o {"round", "red"};
		dataset2.emplace_back(o);

		Object p {"round", "orange"};
		dataset2.emplace_back(p);

		Object q {"oval", "green"};
		dataset2.emplace_back(q);

		Object r {"oval", "red"};
		dataset2.emplace_back(r);

		Object s {"square", "red"};
		dataset2.emplace_back(s);
	}

	std::function<bool(Object)> fSquare = std::bind(&Object::hasShape, std::placeholders::_1, "square");
	std::function<bool(Object)> fRound = std::bind(&Object::hasShape, std::placeholders::_1, "round");
	std::function<bool(Object)> fOval = std::bind(&Object::hasShape, std::placeholders::_1, "oval");

	std::cout << maximumLikelihood(fSquare, dataset2) << std::endl;
	std::cout << maximumLikelihood(fRound, dataset2) << std::endl;
	std::cout << maximumLikelihood(fOval, dataset2) << std::endl;
	std::cout << "-------" << std::endl;
	std::cout << maximumLikelihood<Object, std::string>(Object::shapeField(), "square", dataset2) << std::endl;
	std::cout << maximumLikelihood<Object, std::string>(Object::shapeField(), "round", dataset2) << std::endl;
	std::cout << maximumLikelihood<Object, std::string>(Object::shapeField(), "oval", dataset2) << std::endl;
	std::cout << "-------" << std::endl;

	std::cout << laplaceSmoothing(fSquare, 3, 1, dataset2) << std::endl;
	std::cout << laplaceSmoothing(fRound, 3, 1, dataset2) << std::endl;
	std::cout << laplaceSmoothing(fOval, 3, 1, dataset2) << std::endl;
	std::cout << "-------" << std::endl;
	std::cout << laplaceSmoothing<Object, std::string>(Object::shapeField(), "square", 1, dataset2) << std::endl;
	std::cout << laplaceSmoothing<Object, std::string>(Object::shapeField(), "round", 1, dataset2) << std::endl;
	std::cout << laplaceSmoothing<Object, std::string>(Object::shapeField(), "oval", 1, dataset2) << std::endl;
}
