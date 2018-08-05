#pragma once
#include <vector>
#include "noun.h"
#include "entity.h"

enum DataTag {
	DT_ATOM, DT_LIST
};
struct DataValue {
	Noun atom;
	std::vector<class Data> list;
};

class Data : Entity {
private:
	DataValue value;
	DataTag tag;

public:
	Data(Noun a) {
		tag = DT_ATOM;
		value.atom = a;
	}
	
	template <class T>
	Data(T a) {
		tag = DT_ATOM;
		value.atom = Noun(a);
	}
	
	Data(size_t count, Noun as[]) {
		tag = DT_LIST;
		for(size_t i = 0; i < count; i++) {
			value.list.push_back(Data(as[i]));
		}
	}
	
	DataValue getValue() const { return value; }
	DataTag getTag() const { return tag; }
	
	std::string toString() const {
		return "idk";
	}
};