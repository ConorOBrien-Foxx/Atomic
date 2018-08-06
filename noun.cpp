#include "noun.h"

Noun Noun::NIL = Noun();
	
Noun::Noun(int64_t i) {
	value.integer = i;
	tag = NT_INTEGER;
}
Noun::Noun(double d) {
	value.floating = d;
	tag = NT_FLOATING;
}
Noun::Noun(bool b) {
	value.boolean = b;
	tag = NT_BOOLEAN;
}
Noun::Noun(char c) {
	value.character = c;
	tag = NT_CHARACTER;
}
Noun::Noun() {
	tag = NT_NIL;
}

NounTag Noun::getTag() const { return tag; }
NounValue Noun::getValue() const { return value; }
int64_t Noun::getIntegerValue() const {
	return value.integer;
}
double Noun::getFloatingValue() const {
	return value.floating;
}
bool Noun::getBooleanValue() const {
	return value.boolean;
}
char Noun::getCharacterValue() const {
	return value.character;
}

bool Noun::isInteger() const {
	return tag == NT_INTEGER;
}
bool Noun::isFloating() const {
	return tag == NT_FLOATING;
}
bool Noun::isBoolean() const {
	return tag == NT_BOOLEAN;
}
bool Noun::isCharacter() const {
	return tag == NT_CHARACTER;
}

bool Noun::isNumber() const {
	return isInteger() || isFloating();
}

template <class T>
Noun Noun::castTo() const {
	switch(tag) {
		case NT_INTEGER:
			return Noun((T) value.integer);
		
		case NT_FLOATING:
			return Noun((T) value.floating);
		
		case NT_BOOLEAN:
			return Noun(value.boolean ? (T)1 : (T)0);
		
		case NT_CHARACTER:
			return Noun((T) value.character);
		
		default:
			return Noun::NIL;
	}
}

Noun Noun::toFloating() const {
	return castTo<double>();
}
double Noun::asFloating() const {
	return toFloating().getFloatingValue();
}

Noun Noun::toInteger() const {
	return castTo<int64_t>();
}
int64_t Noun::asInteger() const {
	return toInteger().getIntegerValue();
}

Noun Noun::toCharacter() const {
	return castTo<char>();
}
char Noun::asCharacter() const {
	return toCharacter().getCharacterValue();
}

Noun Noun::toBoolean() const {
	return castTo<bool>();
}
bool Noun::asBoolean() const {
	return toBoolean().getBooleanValue();
}

std::string Noun::toString() const {
	switch(tag) {
		case NT_NIL:
			return "nil";
		
		case NT_INTEGER:
			return std::to_string(value.integer);
			
		case NT_FLOATING:
			return std::to_string(value.floating);
			
		case NT_BOOLEAN:
			return value.boolean ? "true" : "false";
		
		case NT_CHARACTER:
			return "'" + std::string(1, value.character);
		
		default:
			return "(no representation available)";
	}
}

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