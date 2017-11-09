/*Реализовать базовый класс Polygon (многоугольник на  плоскости).
Класс должен содержать метод для отображения информации о 
координатах вершин многоугольника, метод вычисления периметра 
(считать что координаты вершин заданы по порядку) и виртуальные  
методы, возвращающие тип фигуры и вычисления площади. 
Построить производный класс Triangle (треугольник), содержащий 
методы для вычисления площади, нахождения точки пересечения  
медиан, длин медиан, длин биссектрис, координат точек пересечения 
биссектрис, высот треугольника.
Построить производный  класс Square(квадрат), содержащий методы
вычисления площади и нахождения длин диагоналей. 
Создать массив указателей на объекты базового класса и заполнить 
этот массив  объектами производных классов. Продемонстрировать 
работу методов базового класса для разных типов многоугольников. 
Продемонстрировать также работу собственных методов производных классов.*/

#include "point.hpp"
#include "polygon.hpp"
#include "Square.hpp"
#include "triangle.hpp"

extern int err; 

int main(int argc, char const *argv[]) {

	Point A(0, 0),
		  B(4, 0), 
		  C(4, 4), 
		  D(0, 4);

	Polygon* poly[3] = {};	 
		
	poly[0] = new Triangle();
	poly[1] = new Square();
	poly[2] = new Polygon();

	poly[0]->set_point(0, A);
	poly[0]->set_point(1, B);
	poly[0]->set_point(2, C);

	poly[1]->set_point(0, A);
	poly[1]->set_point(1, B);
	poly[1]->set_point(2, C);
	poly[1]->set_point(3, D);

	poly[2]->set_number_of_point(4);
	poly[2]->set_point(0, A);
	poly[2]->set_point(1, B);
	poly[2]->set_point(2, C);
	poly[2]->set_point(3, D);
	
	for (int i = 0; i < 3; ++i) {
		if(poly[i]->is_polygon()) {
			std::cout << "Its not a Polygon\n";
			goto FREE;
		}
		std::cout << "It's:       " << poly[i]->type_of_polygon();

		poly[i]->print_coordinate();

		std::cout << "Area:       " << poly[i]->area()      << '\n';
 		std::cout << "Perimeter:  " << poly[i]->perimeter() << '\n';
 		std::cout << '\n';
 		FREE:
 		delete poly[i];
 	}

 	Triangle L;
	L.set_point(0, A);
	L.set_point(1, B);
	L.set_point(2, C);

	Square K;
	K.set_point(0, A);
	K.set_point(1, B);
	K.set_point(2, C);
	K.set_point(3, D);
	//K.type_of_polygon()[1] = 'L';

	std::cout << "\nTRIANGLE\n";
	std::cout << "Height:     " << L.height(3)   << '\n';
	std::cout << "Bisectrix:  " << L.bisectrix(3)<< '\n';
	std::cout << "Median:     " << L.median(3)   << '\n';
	std::cout << "Barycenter: " << L.intersection_of_median();
	std::cout << "Ortocenter: " << L.intersection_of_bisecrtix();	
	std::cout << "\nSQUARE\n";
	std::cout << "Diagonal:   " << K.diagonal() << '\n';

	return 0;
}
