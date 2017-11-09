#include "Square.hpp"
#include <cstring>
#include <math.h>

Square::Square() {
	this->number_of_point = 4;
	this->coordinate = new Point[number_of_point];
}

Square::Square(const Square& rhs) {
	this->coordinate = new Point[number_of_point];
	memcpy(this->coordinate, rhs.coordinate, sizeof(Point)*number_of_point);
}

bool Square::is_polygon() {
	double side      = coordinate[0].distance(coordinate[1]) * coordinate[0].distance(coordinate[1]);
	double diagonal1 = coordinate[0].distance(coordinate[2]) * coordinate[0].distance(coordinate[2]);
	double diagonal2 = coordinate[1].distance(coordinate[3]) * coordinate[1].distance(coordinate[3]);
	
	return (((abs(side*2 - diagonal1) > 0.0001) && (abs(diagonal2 - diagonal1) > 0.0001))); 
}

double Square::area() {
	return coordinate[1].distance(coordinate[2])*coordinate[1].distance(coordinate[2]);
}

const char* Square::type_of_polygon() {
	char* name = "Square\n";
	return name;
}

double Square::diagonal() {
	return (coordinate[0].distance(coordinate[2]));
}


