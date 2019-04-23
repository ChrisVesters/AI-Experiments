#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <string>
#include <functional>

class Object;

using fp = std::function<bool(Object)>;

class Object {
public:
	Object(const std::string& shape, const std::string& colour);

	static fp matchesShape(const std::string& shape);
	static fp matchesColour(const std::string& colour);

private:
	std::string shape;
	std::string colour;
};



#endif /* OBJECT_HPP_ */
