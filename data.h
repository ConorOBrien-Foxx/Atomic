#pragma once
#include <vector>
#include <string>
#include <cassert>
#include <cstdarg>
#include <iostream>
#include "noun.h"
#include "entity.h"

enum DataTag {
	DT_ATOM, DT_LIST
};
typedef std::vector<class Data> DataList;

struct DataValue {
	Noun atom;
	DataList list;
};

typedef DataList::iterator DataListIterator;
typedef DataList::const_iterator DataListConstIterator;

class Data : public Entity {
private:
	DataValue value;
	DataTag tag;

public:
	// getters and setters //
	DataValue getValue() const { return value; }
	DataTag getTag() const { return tag; }
	
	// constructors //
	Data();
	Data(DataTag);
	Data(Noun);
	Data(DataList);
	template <class T> Data(T);
	template <class T> Data(size_t, T[]);
	static Data list(size_t, ...);	// expects all arguments to be type `Data`
	
	// iterators //
	DataListConstIterator begin() const;
	DataListConstIterator end() const;
	DataListIterator begin();
	DataListIterator end();
	
	// regular methods
	Data& operator[](int64_t);
	
	std::string toString() const;
};