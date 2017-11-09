#include "string.hpp"


String::String(char* str): str(nullptr) {
	if (str!=nullptr)
	{
		/* code */
	}
	size_t len = strlen(str) + 1;
	this->str = new char[len];
	memcpy(this->str, str, len);
}

String::String(const String& rhs) {
	size_t len = strlen(rhs.str) + 1;
	this->str = new char[len];
	memcpy(this->str, rhs.str, len);
}

String::~String() {
	delete[] str;
}

String& String::operator = (const String& rhs) {
	if(this != &rhs) {
		delete[] this->str;
		size_t len = strlen(rhs.str) + 1;
		this->str = new char[len];
		memcpy(this->str, rhs.str, len);
	}
	return *this;
}

String& String::operator += (const String& rhs) {
	int len = strlen(this->str) + strlen(rhs.str) + 1;
	char* ts = new char[len];
	for (int i = 0; i < strlen(this->str); ++i) {
		ts[i] = this->str[i];
	}
	for (int k = strlen(this->str), j = 0; k < len; ++k, ++j) {
		ts[k] = rhs.str[j];
	}
	delete[] this->str;
	this->str = ts;
	return *this;
}

String operator + (String lhs, const String& rhs) {
//	String ts = lhs;
	return lhs += rhs;
}

bool operator == (const String& lhs, const String& rhs) {
	return !(strcmp(lhs.str, rhs.str));
}

bool operator != (const String& lhs, const String& rhs) {
	return strcmp(lhs.str, rhs.str);
}

std::ostream& operator << (std::ostream& os, const String& ts){
	return os << ts.str;
}

std::istream& operator >> (std::istream& is, String& obj) {
    char* BUFF = new char[64];
 	
 	is >> BUFF;
    obj = BUFF;
    delete[] BUFF;
 
    return is;
}
