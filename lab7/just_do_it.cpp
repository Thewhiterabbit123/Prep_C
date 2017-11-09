#include <iostream>
#include <cstring>
#include "vector.h"

int main(int argc, char const *argv[]) {
    Vector<int> lol;
    lol.push_back(1);
    lol.push_back(1);
    lol.push_back(1);
    lol.push_back(1);
    lol.print();

    Vector<int> cheburec;
    cheburec.push_back(1);
    cheburec.push_back(1);
    cheburec.push_back(1);
    cheburec.push_back(1);
    cheburec.print();

 
    Vector<int> lal;
    lal.push_back(2);
    lal.push_back(2);
    lal.push_back(2);
    lal.push_back(2);
    lal.push_back(2);
    lal.print();


    Vector<int> l;
    try {
        l.pop_back();
    } catch(std::length_error& s) {  
        std::cerr << s.what() << std::endl;  
        return -1;  
    }   


    return 0;
}