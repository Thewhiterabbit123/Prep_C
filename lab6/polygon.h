#ifndef POLYGON_HPP
#define POLYGON_HPP
#include "point.hpp"

class Polygon {

	public:
		Polygon(): number_of_point(0), coordinate(nullptr) {};
		Polygon(const Polygon&);
		virtual ~Polygon();

		void   set_point(size_t number_of_point, Point coordinate);
		void   set_number_of_point(size_t number_of_point);
		void   print_coordinate();
		double perimeter();

		const   size_t get_number_of_point() const;

		virtual char*  type_of_polygon();
		virtual double area();
		virtual bool   is_polygon();

	protected:
		size_t number_of_point;
		Point* coordinate;
};

#endif
