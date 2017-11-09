#include <iostream>
#include <vector>
#include <fstream>
#include <numeric>
#include <boost/algorithm/string.hpp>

static void check_values(const int n) {
    if(n != 3) {
        throw std::invalid_argument("Invalid argument");
    }
}

static double computation(const std::vector<int> &v) {
    int sum  = std::accumulate(v.begin(), v.end(), 0);
    double a = 0, b = sum / v.size();
    for(int elem : v) {
        a += elem - b;
    }
    return std::sqrt(a*a / (v.size() - 1));
}

static double dispersion(const std::string &str, const std::string &word) {
    std::vector<std::string> line_parts;
    std::vector<std::string> result;
    std::vector<int> values;

    boost::split(line_parts, str, boost::is_any_of("!?."));
    for (size_t j = 0; j < line_parts.size(); j++) {
        boost::ifind_all(result, line_parts[j], word);
        values.push_back(result.size());
    }
    return computation(values);
}

int main(int argc, char const *argv[]) {
    try {
        check_values(argc);
    } catch(std::invalid_argument& s) {
        std::cerr << s.what() << std::endl;
        return 1;
    }
    std::string str;
    std::ifstream file;
    file.exceptions(std::ifstream::failbit);
    try {
        file.open(argv[1]);
    } catch (std::ifstream::failure e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    file.exceptions(std::ifstream::badbit);
    try {
        while(!file.eof()) {
            str.push_back(file.get());
        }
        file.close();
    } catch (std::ifstream::failure e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    std::cout << "\n\nDispersion is: "<< dispersion(str, argv[2]) << "\n\n";
	return 0;
}
