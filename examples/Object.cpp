#include "Object.hpp"

Object::Object(const std::string& shape, const std::string& colour) :
		shape(shape), colour(colour) {
}
;

fp Object::matchesShape(const std::string& shape) {
	return [shape](const Object& obj) {
		return obj.shape == shape;
	};
}

fp Object::matchesColour(const std::string& colour) {
	return [colour](const Object& obj) {
		return obj.colour == colour;
	};
}

