#include "entity.h"
#include <iostream>

template <class T>
std::ostream& operator<<(std::ostream& os, const T& n) {
	return os << n.toString();
}