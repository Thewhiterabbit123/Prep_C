// ios::exceptions
#include <iostream>     // std::cerr
#include <fstream>      // std::ifstream

int main () {
  std::ifstream file;
  file.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
  try {
    std::cerr <<file.rdstate() <<std::endl;
    file.open("test.txt");
    std::cerr <<file.rdstate() <<std::endl;
    while (!file.eof()) file.get();
    std::cerr <<file.rdstate() <<std::endl;

    file.close();
    std::cerr <<file.rdstate() <<std::endl;
  }
  catch (std::ifstream::failure e) {
    std::cerr << "Exception opening/reading/closing file\n";
  }

  return 0;
}
