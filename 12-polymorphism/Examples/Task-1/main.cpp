#include <iostream>

#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "ShapeContainer.h"

int main() {
	ShapeContainer sc;
	Triangle t(Point(0, 0), Point(0, 2), Point(3, 0));
	Circle c(Point(0, 0), 3);

	sc.add(&t);
	sc.add(&c);

	sc.printArea();
	sc.printPerimeter();

	return 0;
}