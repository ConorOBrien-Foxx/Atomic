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

class Noun : public Entity {
private:
	NounValue value;
	NounTag tag;

public:
	static class Noun NIL;

	Noun(int64_t i);
	Noun(double d);
	Noun(bool b);
	Noun(char c);
	Noun();
	
	NounTag getTag() const;
	NounValue getValue() const;
	int64_t getIntegerValue() const;
	double getFloatingValue() const;
	bool getBooleanValue() const;
	char getCharacterValue() const;
	
	bool isInteger() const;
	bool isFloating() const;
	bool isBoolean() const;
	bool isCharacter() const;
	
	bool isNumber() const;
	template <class T> Noun castTo() const;
	
	Noun toFloating() const;
	double asFloating() const;
	
	Noun toInteger() const;
	int64_t asInteger() const;
	
	Noun toCharacter() const;
	char asCharacter() const;
	
	Noun toBoolean() const;
	bool asBoolean() const;

	friend Noun operator+(const Noun&, const Noun&);
	std::string toString() const;
};

