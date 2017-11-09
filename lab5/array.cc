#include "array.hpp"

Array::Array(size_t Array_size) {
	this->text = new String[Array_size];
	this->Array_size = Array_size;
}

Array::Array(const Array& rhs) {

	Array_size = rhs.get_size();
	this->text = new String[Array_size];
	memcpy(this->text, rhs.text, sizeof(String)*Array_size);
}

void Array::print(size_t n) {  //вывод массива
	for (int i = 0; i < n; ++i) {
		std::cout << text[i] << '\n' ;
	}
}

void Array::print_string(size_t index) {
	if (index < this->Array_size) {
		std::cout << text[index] << '\n';
	}
}

void Array::set_size(size_t Array_size) {
	this->text = new String[Array_size];
	this->Array_size = Array_size;
}

Array& Array::operator = (const Array& rhs) {
	if(this != &rhs) {
		delete[] this->text;
		Array_size = rhs.get_size();
		this->text = new String[Array_size];
		memcpy(this->text, rhs.text, sizeof(String)*Array_size);
	}
	return *this;
}

Array::~Array() {
	delete[] text;
}

const size_t Array::get_size() const {   //размер массива
	return Array_size;
}

void Array::set_string(size_t number, String str) {
	this->text[number] = str;
}

Array concat(const Array& lhs, const Array& rhs) { //конкатенация
	
	size_t max = 0;

	if (lhs.get_size() > rhs.get_size()) {
		max = lhs.get_size();
    } else {
    	max = lhs.get_size();
    }
	
    Array ts(max);

	for (int i = 0; i < ts.get_size(); ++i) {
		ts.text[i] = lhs.text[i] + rhs.text[i];
	}

	return ts;
}

Array plus (const Array& lhs, const Array& rhs) { //слияние 2х массивов
	size_t len = lhs.get_size() + rhs.get_size();
	Array ts(len);

	for (int i = 0; i < lhs.get_size(); ++i) {
		ts.text[i] = lhs.text[i];
	}

	for (int j = lhs.get_size(), i = 0; j < len; ++j, ++i) {
		if (rhs.text[i] != lhs.text[i]) {
			ts.text[j] = rhs.text[i];
		} else {
			ts.text[j] = (char*)"";
		}
	}
	return ts;
}
