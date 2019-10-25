#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <string>
#include <functional>

class Object;

using fp = std::function<bool(Object)>;

class Object {
public:
	Object(const std::string& shape, const std::string& colour);

	bool hasShape(const std::string& shape);
	bool hasColour(const std::string& colour);

	static std::string Object::* shapeField();
	static std::string Object::* colourField();

private:
	std::string shape;
	std::string colour;
};



#endif /* OBJECT_HPP_ */
