#ifndef PROBABILITY_HPP_
#define PROBABILITY_HPP_

#include <vector>
#include <algorithm>
#include <iostream>

#include <functional>

template <typename T> class Probability {
public:
	Probability(std::function<bool(T)> f) : match{f} {};

	double operator()(std::vector<T> dataset){
		int count = std::count_if(dataset.begin(), dataset.end(), match);
		int total = dataset.size();
		return (double) count / total;
	}

private:
	std::function<bool(T)> match;
};

#endif /* PROBABILITY_HPP_ */
