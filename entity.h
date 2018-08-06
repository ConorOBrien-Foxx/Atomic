#pragma once
#include <string>

class Entity {
public:
	virtual std::string toString() const = 0;
};

std::ostream& operator<<(std::ostream&, const Entity&);