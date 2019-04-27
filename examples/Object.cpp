#include "Object.hpp"

Object::Object(const std::string& shape, const std::string& colour) :
		shape(shape), colour(colour) {
}

bool Object::hasShape(const std::string& shape) {
	return this->shape == shape;
}

bool Object::hasColour(const std::string& colour) {
	return this->colour == colour;
}


std::string Object::* Object::shapeField() {
	return &Object::shape;
}

std::string Object::* Object::colourField() {
	return &Object::colour;
}

