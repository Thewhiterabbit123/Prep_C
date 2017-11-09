/* Разработать класс для массива строк.
 Разработать методы для поэлементной конкатенации двух массивов,
 слияния двух массивов с удалением повторяющихся строк  
 и вывода на экран всего массива и заданной строки
 создать массив объектов и передавать объекты в функцию.
 которая выполныет слияние объектов и получеет 
 объект-результат*/

#include <iostream>
#include <fstream>
#include "string.hpp"
#include "array.hpp"

Array function(const Array& lhs, const Array& rhs) {
	std::cout << "_______CONCATENACIA_______\n";
	Array res_of_conc = concat(lhs, rhs);
	size_t n = res_of_conc.get_size();
	res_of_conc.print(n);
	std::cout << "_______SLIANIE____________\n";
	Array res_of_plus = plus(res_of_conc, rhs);
	n = res_of_plus.get_size();
	res_of_plus.print(n);
	return res_of_plus;
}
//ВОПРОС ПРО КОНСТРУКТОРЫ
//ВОПРОС ПРО ДИНАМИЧЕСКУЮ ПАМЯТЬ
//ВОПРОС ПРО СТАТЬЮ
//ПОПРОС ПРО MEMCPY

int main(int argc, char const *argv[])
{
	if(argc != 2) {
		std::cerr << "trouble with arguments \n";
		return 1;
	}

	std::ifstream file(argv[1]);	//открытие файла
	if(!file.is_open()) {
		std::cerr << "file can't be open\n";
		return 1;
	}

	int n = 0;  //число строк в массиве
	file >> n;
	if(n <= 0) {
		std::cerr << "trouble with value\n";
		return 1;
	}

	Array* book = new Array[2];
	for (int i = 0; i < 2; ++i) {
		book[i].set_size(n);
	}

	for (int i = 0; i < n; ++i) {
		String str;
		file >> str;
		book[0].set_string(i, str);
		book[1].set_string(i, str);
	}

	file.close();

	Array temp = function(book[0], book[1]);

	std::cout << "_______RESALT________\n";
	size_t len = temp.get_size();
	temp.print(len);
	std::cout << "_______STRING________\n";
	temp.print_string(4);
	delete[] book;

	return 0;
}
