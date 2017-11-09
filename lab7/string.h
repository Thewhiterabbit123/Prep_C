#ifndef STRING_H
#define STRING_H 


#include <iostream>
#include <cstring>

class String {
	public:
		String(): str(new char[1]) {*str = '\0';};//str(" ")
		String(const char* str);
		String(const String&);

		~String();

		String& operator =  (const String&);
		String& operator += (const String&);

		const char& operator[](size_t) const;
    	char& operator[](size_t);

		friend String operator + (String&, const String&);

		friend bool operator == (const String&, const String& );
		friend bool operator != (const String&, const String&);
		friend bool operator >  (const String&, const String&);
	    friend bool operator >= (const String&, const String&);
	    friend bool operator <  (const String&, const String&);
	    friend bool operator <= (const String&, const String&);

		friend std::ostream& operator << (std::ostream&, const String&);
		friend std::istream& operator >> (std::istream&, String&);

	private:
		char* str;
};


String::String(const char* str) {
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
	if(this == &rhs) {
		throw std::invalid_argument("invalid_argument");
	}
	delete[] this->str;
	size_t len = strlen(rhs.str) + 1;
	this->str = new char[len];
	memcpy(this->str, rhs.str, len);
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
	return lhs += rhs;
}

bool operator == (const String& lhs, const String& rhs) {
	return !(strcmp(lhs.str, rhs.str));
}

bool operator != (const String& lhs, const String& rhs) {
	return strcmp(lhs.str, rhs.str);
}

bool operator  > (const String& lhs, const String& rhs) {
    return (strlen(lhs.str) > strlen(rhs.str));// ? true : false;
}
 
bool operator >= (const String& lhs, const String& rhs) {
    return (strlen(lhs.str) >= strlen(rhs.str));// ? true : false;
}
 
bool operator  < (const String& lhs, const String& rhs) {
    return (strlen(lhs.str) < strlen(rhs.str));// ? true : false;
}
 
bool operator <= (const String& lhs, const String& rhs) {
    return (strlen(lhs.str) <= strlen(rhs.str));// ? true : false;
}

const char& String::operator[](size_t i) const {
    if(i < 0 || i >= strlen(this->str)) {
    	throw std::out_of_range("out of range");
    }
    return this->str[i] ;
}
 
char& String::operator[](size_t i) {
    if(i < 0 || i >= strlen(this->str)) {
    	throw std::out_of_range("out of range");
    }
    return this->str[i] ;
}

std::ostream& operator << (std::ostream& os, const String& ts){
	return os << ts.str;
}

std::istream& operator >> (std::istream& is, String& obj) {
    char* BUFF = new char[64];
 	
 	is >> BUFF;
    obj = BUFF;
    delete[] BUFF;
 //std::string
    return is;
}

#endif
