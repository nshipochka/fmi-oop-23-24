#pragma once
#include "Shape.h"
#include <iostream>

class Triangle : public Shape {
public:
	Triangle() : a(), b(), c() {}
	Triangle(Point _a, Point _b, Point _c)
		: a(_a), b(_b), c(_c) {};

	virtual bool contains(const Point& p) const {
		Triangle t1(a, b, p);
		Triangle t2(b, c, p);
		Triangle t3(c, a, p);

		return area() == (t1.area() + t2.area() + t3.area());
	}

	virtual double area() const {
		//with determinant
		return abs((a.x * b.y + a.y * c.x + b.x * c.y) - (c.x * b.y + a.x * c.y + b.x * a.y)) * 0.5;
	}

	virtual double perimeter() const {
		return distance(a, b) + distance(b, c) + distance(c, a);
	}

	virtual void print() const {
		a.print();
		std::cout << " ";
		b.print();
		std::cout << " ";
		c.print();
		std::cout << std::endl;
	}

	virtual Shape* clone() const {
		return new Triangle(*this);
	}

private:
	Point a, b, c;
};