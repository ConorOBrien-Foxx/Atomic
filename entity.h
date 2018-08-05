#pragma once
#include <string>

class Entity {
public:
	virtual std::string toString() const = 0;
};

template <class T> std::ostream& operator<<(std::ostream&, const T&);