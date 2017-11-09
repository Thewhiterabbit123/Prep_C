#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>

class Point {
	public:
		Point(): x(0), y(0) {};
		Point(double xx, double yy): x(xx), y(yy) {};
		Point(const Point&);

		double get_x();
		double get_y();
		double distance(const Point& rhs);

		friend bool operator == (const Point&, const Point&);
		friend bool operator != (const Point&, const Point&);
		friend std::ostream& operator << (std::ostream&, const Point&);
		friend std::istream& operator >> (std::istream&, Point&);
		
	private:
		double x;
		double y;
};

#endif