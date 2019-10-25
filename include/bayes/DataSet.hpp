#ifndef BAYES_DATASET_HPP_
#define BAYES_DATASET_HPP_

#include "Field.hpp"
#include "Value.hpp"

#include <vector>

using Header = const std::vector<const Field>;
using Row = const std::vector<const Value*>;

class DataSet {
public:
//	DataSet(Header header) : header{header} {};
//
//	void addRow(Row row) {
//		elements.emplace_back(row);
//	};

private:
	// The dataset should contain a header list.
	// Once created this should never change!!!
//	Header header;
//
//	// Should the list of Values be moved up into this class?
//	std::vector<Row> elements;
};



#endif /* BAYES_DATASET_HPP_ */
