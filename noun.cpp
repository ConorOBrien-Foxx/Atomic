#include "noun.h"

Noun Noun::NIL = Noun();

Noun operator+(const Noun& base, const Noun& other) {
	if(base.isFloating() || other.isFloating()) {
		return Noun(base.asFloating() + other.asFloating());
	}
	
	else if(base.isCharacter() || other.isCharacter()) {
		return Noun((char)(base.asInteger() + other.asInteger()));
	}
	
	else if(base.isInteger() || other.isInteger()) {
		return Noun(base.asInteger() + other.asInteger());
	}
	
	else if(base.isBoolean() || other.isBoolean()) {
		return Noun(base.asBoolean() || other.asBoolean());
	}
	
	else {
		return Noun::NIL;
	}
}