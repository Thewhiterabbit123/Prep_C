#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
#include <numeric>

static double dispersion(const std::vector<int> &v) {
    double a = 0;
    int sum  = std::accumulate(v.begin(), v.end(), 0);
    double b = sum / v.size();

    for(int elem : v) {
        a += elem - b;
    }

    return sqrt(a*a / (v.size() - 1));
}

static bool is_sentence_separator(const char c) {
	return (c == '!' || c == '?' || c == '.');
}

int main(int argc, char const *argv[]) {
    try{
        if(argc != 3) {
            std::cout << "DDDD\n";
		    throw std::invalid_argument("invalid_argument");
            std::cout << "SSSS\n";
        }
    } catch (std::invalid_argument& s) {
        std::cout << "sdfasdf\n";
        std::cerr << s.what();
        throw;
        std::cout << "DGGGG\n";
    }

    std::cout << "AAAa\n";

    std::ifstream file(argv[1]);
	if(!file.is_open()) {
        throw std::invalid_argument("invalid_argument");
    }

    int _count = 0;
	std::string str;
    const std::string word = argv[2];
    std::vector<int> number;
    char ch;

	while(file.get(ch)) {
        if(!is_sentence_separator(ch)) {
            str.push_back(ch);
        }
        if(is_sentence_separator(ch) ) {
            for (int pos = 0; pos < str.size(); pos += word.size()) {
                pos = str.find(word, pos);
                if (pos != std::string::npos) {
                    ++_count;
                } else {
                    break;
                }
            }
            std::cout << _count << std::endl;
            number.push_back(_count);
            _count = 0;
            str.clear();
        }
    }

    file.close();
    std::cout << "\nDispersion is: "<< dispersion(number) << '\n' << std::endl;
	return 0;
}
