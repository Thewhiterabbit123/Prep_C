#ifndef ARRAY_HPP
#define ARRAY_HPP
#include "string.hpp"
#include <cstring>

class Array {
	public:
		Array(): Array_size(0), text(nullptr) { };
		Array(size_t Array_size);
		Array(const Array&);
		~Array();

		void set_string(size_t number, String str);
		void print(size_t n);
		void set_size(size_t Array_size);
		void print_string(size_t index);

		Array& operator = (const Array&);

		const size_t get_size() const;
		friend Array concat(const Array&, const Array&);
		friend Array plus  (const Array&, const Array&);
	
	private:
		String* text;
		size_t Array_size;
};

#endif
