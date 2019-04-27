#ifndef PROBABILITY_HPP_
#define PROBABILITY_HPP_

#include <algorithm>
#include <functional>
#include <vector>

template <typename T, typename V>
bool equals(T object, V T::* field, V value) {
	return object.*field == value;
}

template <typename T, typename V>
V values(T object, V T::* field) {
	return object.*field;
}

/**
 * Maximum likelihood using member pointers.
 * This allows for a bit more flexible usage.
 **/
template <typename T, typename V>
double maximumLikelihood(V T::* field, V value, std::vector<T> dataset) {
	std::function<bool(T)> match = std::bind(equals<T, V>, std::placeholders::_1, field, value);
	return maximumLikelihood(match, dataset);
}

/**
 * Maximum likelihood using functions.
 * This forces you to write a function for each probability.
 **/
template <typename T>
double maximumLikelihood(std::function<bool(T)> match, std::vector<T> dataset) {
	unsigned long count =  std::count_if(dataset.begin(), dataset.end(), match);
	unsigned long total = dataset.size();
	return (double) count / total;
}


/**
 * Laplace smoothing with a fixed pre-determined amount of options.
 **/
template <typename T>
double laplaceSmoothing(std::function<bool(T)> match, unsigned int options, unsigned int smoothing, std::vector<T> dataset) {
	unsigned long count =  std::count_if(dataset.begin(), dataset.end(), match);
	unsigned long total = dataset.size();
	return (double) (count + smoothing) / (total + smoothing * options);
}

/**
 * Laplace smoothing with member pointers.
 * This makes it possible to calculate the different options for the member ourselves!!!
 **/
template <typename T, typename V>
double laplaceSmoothing(V T::* field, V value, unsigned int smoothing, std::vector<T> dataset) {
	std::vector<V> valueset(dataset.size());
	std::function<V(T)> transform = std::bind(values<T, V>, std::placeholders::_1, field);
	std::transform(dataset.begin(), dataset.end(), valueset.begin(), transform);
	std::sort(valueset.begin(), valueset.end());
	auto end = std::unique(valueset.begin(), valueset.end());
	valueset.resize(std::distance(valueset.begin(), end));

	std::function<bool(T)> match = std::bind(equals<T, V>, std::placeholders::_1, field, value);
	return laplaceSmoothing(match, valueset.size(), smoothing, dataset);
}




#endif /* PROBABILITY_HPP_ */
