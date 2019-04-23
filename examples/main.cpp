#include "Probability.hpp"
#include "Object.hpp"

#include <vector>

int main(int argc, char* argv[]) {
	std::vector<Object> dataset2;
	for (int i = 0; i < 100; ++i) {
		Object o{"round", "red"};
		dataset2.emplace_back(o);

		Object p{"round", "orange"};
		dataset2.emplace_back(p);

		Object q{"oval", "green"};
		dataset2.emplace_back(q);

		Object r{"oval", "red"};
		dataset2.emplace_back(r);
	}

	Probability<Object> pSquare(Object::matchesShape("square"));
	std::cout << pSquare(dataset2) << std::endl;

	Probability<Object> pRound(Object::matchesShape("round"));
	std::cout << pRound(dataset2) << std::endl;

	Probability<Object> pOval{Object::matchesShape("oval")};
	std::cout << pOval(dataset2) << std::endl;
}

