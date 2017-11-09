#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "polygon.hpp"

class Square : public Polygon {
	public:
		Square();
		Square(const Square&);

		bool   is_polygon();
		double area();
		double diagonal();
		char*  type_of_polygon();
};

#endif