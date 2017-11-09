#include <iostream>
#include <cstring>
#include "string.h"

int main(int argc, char const *argv[]) {

	String lol = "sdjhfws";
	std::cout << lol << std::endl;

	try {
		lol = lol;
	} catch(std::invalid_argument& e) {  
    	std::cerr << e.what() << std::endl;  
    	return -1;  
   	} 

   	try {
		std:: cout << lol[100];
	} catch(std::out_of_range& s) {  
    	std::cerr << s.what() << std::endl;  
    	return -1;  
   	}   

	return 0;
}
