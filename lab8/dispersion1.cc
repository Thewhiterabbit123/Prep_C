#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
#include <numeric>
#include <boost/algorithm/string.hpp>

static void check(const int n) {
    if(n != 3) {
        throw std::invalid_argument("Invalid argument");
    }
}

static double dosmth(const std::vector<int> &v) {
    int sum  = std::accumulate(v.begin(), v.end(), 0);
    double a = 0, b = sum / v.size();
    for(int elem : v) {
        a += elem - b;
    }
    return sqrt(a*a / (v.size() - 1));
}

static double dispersion(const std::string &str, const std::string &word) {
    std::vector<std::string> line_parts;
    std::vector<std::string> result;
    std::vector<int> number;

    boost::split(line_parts, str, boost::is_any_of("!?."));
    for (size_t j = 0; j < line_parts.size(); j++) {
        boost::ifind_all(result, line_parts[j], word);
        number.push_back(result.size());
    }
    return dosmth(number);
}

int main(int argc, char const *argv[]) {
    try {
        check(argc);
    } catch(std::invalid_argument& s) {
        std::cerr << s.what() << std::endl;
        return 1;
    }

    std::string str;
    std::ifstream file(argv[1]);

    if (!file.is_open()) {
        std::cerr << "File is not open\n";
        return 1;
    }

    while(!file.eof()) {
        str.push_back(file.get());
    }
    file.close();

    std::cout << "\n\nDispersion is: "<< dispersion(str, argv[2]) << "\n\n";
	return 0;
}
