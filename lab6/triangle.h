#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "polygon.hpp"
#include "point.hpp"

class Triangle : public Polygon {
	public:
		Triangle();
		
		Triangle(const Triangle&);

		double area();
		double median(size_t number_of_side);
		double bisectrix(size_t number_of_side);
		double height(size_t number_of_side);
		bool   is_polygon();

		Point intersection_of_median();
		Point intersection_of_bisecrtix();
		char* type_of_polygon();
};

#endif