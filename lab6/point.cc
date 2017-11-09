#include "point.hpp"
#include "math.h"

Point::Point(const Point& rhs) {
	this->x = rhs.x;
	this->y = rhs.y;
}

double Point::get_x() {
	return x;
}

double Point::get_y() {
	return y;
}

double Point::distance(const Point& rhs) {
	if (this != &rhs) {
		return sqrt((rhs.x-this->x)*(rhs.x-this->x) + 
			        (rhs.y-this->y)*(rhs.y-this->y));
	}
}

//PVS

bool operator==(const Point& lhs, const Point& rhs) {
	return ((lhs.x == rhs.x) && (lhs.y == rhs.y));
}

bool operator!=(const Point& lhs, const Point& rhs) {
	return !((lhs.x == rhs.x) && (lhs.y == rhs.y));
}

std::ostream& operator << (std::ostream& os, const Point& ts){
	return os << "(" << ts.x << ";" << ts.y << ")\n";
}

std::istream& operator >> (std::istream& is, Point& ts) {
 	
 	char braket_left = ' ', braket_right = ' ', colon = ' ';

 	is >> braket_left >> ts.x >> colon >> ts.y >> braket_right;
 	if( (braket_left  != '(') && 
 	    (braket_right != ')') && 
 	    (   colon     != ':')) {
 		is.setstate(std::ios::failbit);
 		std::cout << "Failbit\n";
 	}

    return is;
}
