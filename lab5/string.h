#ifndef STRING_HPP
#define STRING_HPP

#include <iostream>
#include <cstring>

class String {
	public:
		String():str("") {};
		String(char* str);
		String(const String&);

		~String();

		String& operator =  (const String&);
		String& operator += (const String&);

		friend String operator + (const String&, const String&);

		friend bool operator ==  (const String&, const String& );
		friend bool operator !=  (const String&, const String&);
		friend std::ostream& operator << (std::ostream&, const String&);
		friend std::istream& operator >> (std::istream&, String&);

	private:
		char* str;
};
#endif
