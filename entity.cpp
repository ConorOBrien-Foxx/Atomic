#include "entity.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const Entity& n) {
	return os << n.toString();
}