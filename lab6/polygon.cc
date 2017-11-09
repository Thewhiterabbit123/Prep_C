#include "polygon.hpp"
#include <cstring>
#include <math.h>

int err = 0;

Polygon::Polygon(const Polygon& rhs) {
	number_of_point =  rhs.get_number_of_point();
	this->coordinate = new Point[number_of_point];
	memcpy(this->coordinate, rhs.coordinate, sizeof(Point)*number_of_point);
}

Polygon::~Polygon() {
	delete[] coordinate;
}

void Polygon::set_point(size_t number_of_point, Point coordinate) {
	if(this->number_of_point > number_of_point) {
		this->coordinate[number_of_point] = coordinate;
	} else {
		err = 3;
		return (void)1;
	}
}

void Polygon::set_number_of_point(size_t number_of_point) {
	if (number_of_point <=2) {
		std::cout << "Its not a polygon\n";
		err = 2;
		return (void)1;
	}
	this->number_of_point = number_of_point;
	this->coordinate = new Point[number_of_point];
}

bool Polygon::is_polygon() {
	for (int i = 0; i < (this->number_of_point - 1); ++i)	{
		if (i > 1) {  //проверка на то, чтобы три точки не лежали на одной линии
			double temp1 = coordinate[i - 2].distance(coordinate[i - 1]) + coordinate[i - 1].distance(coordinate[i]);
			double temp2 = coordinate[i - 2].distance(coordinate[i]);
			if (temp2 >= temp1) {
				std::cout << "3 point on line is not cool\n";
				return 1;
			}
		}
	}
	return 0;
}

void Polygon::print_coordinate() {
	for (int i = 0; i < this->number_of_point; ++i) {
		std::cout << "Point:      "<< coordinate[i];
	}
}

const size_t Polygon::get_number_of_point() const {
	return number_of_point;
}

double Polygon::perimeter() {
	double perim = 0;
	for (int i = 0; i < (this->number_of_point - 1); ++i)	{
		perim += coordinate[i].distance(coordinate[i + 1]);
		if (this->is_polygon()) {
			return 1;
		}
	}
	perim += coordinate[number_of_point - 1].distance(coordinate[0]);
	return perim;
}

double Polygon::area() {
	double p = this->perimeter() / 2;
	double part = 1;
	for (int i = 1; i < this->number_of_point; ++i) {
		part = part * (p - coordinate[i - 1].distance(coordinate[i]));
	}
	part = part * (p - coordinate[0].distance(coordinate[number_of_point - 1]));
	return sqrt(part);
}

char* Polygon::type_of_polygon() {
	char* name = {};
	switch(number_of_point) {
		case 3: 
			name = (char*)"triangle\n";
			break;
		case 4: 
			name = (char*)"tetragon\n";
			break;
		case 5:
			name = (char*)"pentagon\n";
			break;
		default:
			name = (char*)"polygon\n";

	}
	return name;
}
