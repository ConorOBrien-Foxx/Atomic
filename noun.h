#pragma once
#include <string>
#include <iostream>
#include "entity.h"

enum NounTag {
	NT_NIL, NT_INTEGER, NT_FLOATING, NT_BOOLEAN, NT_CHARACTER
};
union NounValue {
	int64_t integer;
	double floating;
	bool boolean;
	char character;
};

class Noun : Entity {
private:
	NounValue value;
	NounTag tag;

public:
	Noun(int64_t i) {
		value.integer = i;
		tag = NT_INTEGER;
	}
	Noun(double d) {
		value.floating = d;
		tag = NT_FLOATING;
	}
	Noun(bool b) {
		value.boolean = b;
		tag = NT_BOOLEAN;
	}
	Noun(char c) {
		value.character = c;
		tag = NT_CHARACTER;
	}
	Noun() {
		tag = NT_NIL;
	}
	static class Noun NIL;
	
	NounTag getTag() const { return tag; }
	NounValue getValue() const { return value; }
	int64_t getIntegerValue() const {
		return value.integer;
	}
	double getFloatingValue() const {
		return value.floating;
	}
	bool getBooleanValue() const {
		return value.boolean;
	}
	char getCharacterValue() const {
		return value.character;
	}
	
	bool isInteger() const {
		return tag == NT_INTEGER;
	}
	bool isFloating() const {
		return tag == NT_FLOATING;
	}
	bool isBoolean() const {
		return tag == NT_BOOLEAN;
	}
	bool isCharacter() const {
		return tag == NT_CHARACTER;
	}
	
	bool isNumber() const {
		return isInteger() || isFloating();
	}
	
	template <class T>
	Noun castTo() const {
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
	
	Noun toFloating() const {
		return castTo<double>();
	}
	double asFloating() const {
		return toFloating().getFloatingValue();
	}
	
	Noun toInteger() const {
		return castTo<int64_t>();
	}
	int64_t asInteger() const {
		return toInteger().getIntegerValue();
	}
	
	Noun toCharacter() const {
		return castTo<char>();
	}
	char asCharacter() const {
		return toCharacter().getCharacterValue();
	}
	
	Noun toBoolean() const {
		return castTo<bool>();
	}
	bool asBoolean() const {
		return toBoolean().getBooleanValue();
	}
	
	friend Noun operator+(const Noun&, const Noun&);
	
	std::string toString() const {
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
};

