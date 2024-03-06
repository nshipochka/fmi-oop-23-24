#include "Point.h"
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"

int main() {
	Point p;
	p.print();

	Point p2(2, 1);
	p2.print();

	Square sq(3, 4, 2);
	sq.print();

	Circle c(0, 0, 1);
	c.print();

	Rectangle r(2, 2, 1, 2);
	r.print();

	return 0;
}