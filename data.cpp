#include "data.h"

Data::Data() {
	assert(false);
}

Data::Data(DataTag t) {
	tag = t;
	if(t != DT_LIST) assert(false);
}
	
Data::Data(Noun a) {
	tag = DT_ATOM;
	value.atom = a;
}

Data::Data(DataList as) {
	value.list = as;
	tag = DT_LIST;
}

template <class T>
Data::Data(T a) {
	tag = DT_ATOM;
	value.atom = Noun(a);
}

template <class T>
Data::Data(size_t count, T as[]) {
	tag = DT_LIST;
	for(size_t i = 0; i < count; i++) {
		value.list.push_back(Data(as[i]));
	}
}

Data& Data::operator[](int64_t index) {
	if(index < 0) {
		assert(false);
	}
	return value.list[index];
}


DataListConstIterator Data::begin() const {
	assert(tag == DT_LIST);
	return value.list.begin();
}
	
DataListConstIterator Data::end() const {
	assert(tag == DT_LIST);
	return value.list.end();
}
	
DataListIterator Data::begin() {
	assert(tag == DT_LIST);
	return value.list.begin();
}

DataListIterator Data::end() {
	assert(tag == DT_LIST);
	return value.list.end();
}

std::string Data::toString() const {
	switch(tag) {
		case DT_ATOM:
			return value.atom.toString();
		
		case DT_LIST:
		{
			std::string result = "{ ";
			for(auto it = begin(); it != end(); ++it) {
				Data value = *it;
				result += value.toString();
				if(std::next(it) != end())
					result += ", ";
			}
			result += " }";
			return result;
		}
		
		default:
			assert(false);
	}
}

Data Data::list(size_t count, ...) {
	va_list args;
	va_start(args, count);
	
	DataList res;
	for(size_t i = 0; i < count; i++) {
		res.push_back(va_arg(args, Data));
	}
	
	va_end(args);
	
	return Data(res);
}