#include "triangle.hpp"
#include "point.hpp"
#include <cstring>
#include <math.h>

Triangle::Triangle() {
	this->number_of_point = 3;
	this->coordinate = new Point[number_of_point];
}

Triangle::Triangle(const Triangle& rhs) {
	this->coordinate = new Point[number_of_point];
	memcpy(this->coordinate, coordinate, sizeof(Point)*number_of_point);
}

double Triangle::area() {
	double p = this->perimeter() / 2;
	double part = 1;
	for (int i = 1; i < this->number_of_point; ++i) {
		part = part * (p - coordinate[i - 1].distance(coordinate[i]));
	}
	part = part * (p - coordinate[0].distance(coordinate[number_of_point - 1]));
	return sqrt(p*part);
}

char* Triangle::type_of_polygon() {
	char* name = (char*)"triangle\n";
	return name;
}

bool Triangle::is_polygon() {
	double a = coordinate[0].distance(coordinate[1]);
	double b = coordinate[1].distance(coordinate[2]);
	double c = coordinate[0].distance(coordinate[2]);
	return (!((a + c > b)&&(b + c > a)&&(a + b > c)));
}

double Triangle::median(size_t number_of_side) {
	double a = coordinate[0].distance(coordinate[1]);
	double b = coordinate[1].distance(coordinate[2]);
	double c = coordinate[0].distance(coordinate[2]);
	switch(number_of_side) {
		case 1: 
			return 0.5*sqrt(2*b*b + 2*c*c - a*a);
			break;
		case 2: 
			return 0.5*sqrt(2*a*a + 2*c*c - b*b);
			break;
		case 3:
			return 0.5*sqrt(2*b*b + 2*a*a - c*c);
			break;
		default:
			std::cout << "Trouble with side\n";
			return 1;
	}	
}

double Triangle::bisectrix(size_t number_of_side) {
	double a = coordinate[0].distance(coordinate[1]);
	double b = coordinate[1].distance(coordinate[2]);
	double c = coordinate[0].distance(coordinate[2]);
	double p = this->perimeter() / 2;
	switch(number_of_side) {
		case 1: 
			return ((2/(b + c))*sqrt(b*c*p*(p - a)));
			break;
		case 2: 
			return ((2/(a + c))*sqrt(a*c*p*(p - b)));
			break;
		case 3:
			return ((2/(b + a))*sqrt(b*a*p*(p - c)));
			break;
		default:
			std::cout << "Trouble with side\n";
			return 1;
	}		
}

double Triangle::height(size_t number_of_side) {
	double a = coordinate[0].distance(coordinate[1]);
	double b = coordinate[1].distance(coordinate[2]);
	double c = coordinate[0].distance(coordinate[2]);
	switch(number_of_side) {
		case 1: 
			return ((2*this->area()) / a);
			break;
		case 2: 
			return ((2*this->area()) / b);
			break;
		case 3:
			return ((2*this->area()) / c);
			break;
		default:
			std::cout << "Trouble with side\n";
			return 1;
	}		
}

Point Triangle::intersection_of_median() {
	double x = (coordinate[0].get_x() + coordinate[1].get_x() + coordinate[2].get_x())/3;
	double y = (coordinate[0].get_y() + coordinate[1].get_y() + coordinate[2].get_y())/3;
	Point barycenter(x, y);
	return barycenter;
} 

Point Triangle::intersection_of_bisecrtix() {
	double a = coordinate[1].distance(coordinate[2]);
	double b = coordinate[0].distance(coordinate[2]);
	double c = coordinate[0].distance(coordinate[1]);

	double x = (a*coordinate[0].get_x() + b*coordinate[1].get_x() + c*coordinate[2].get_x())/(a + b + c);
	double y = (a*coordinate[0].get_y() + b*coordinate[1].get_y() + c*coordinate[2].get_y())/(a + b + c);

	Point ortocenter(x, y);
	return ortocenter;
}