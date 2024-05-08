#pragma once
#include "Shape.h"
#include "Triangle.h"

class Rectangle : public Shape {
public:
	Rectangle() : a(), b(), c(), d() {}
	Rectangle(Point _a, Point _b) 
		: a(_a), b(_b), c(b.x, a.y), d(a.x, b.y){}

	virtual bool contains(const Point& p) const {
		return p.x >= a.x && p.y >= a.y && p.x <= b.x && p.y <= b.y;
	}

	virtual double area() const {
		return Triangle(a, c, b).area() + Triangle(a, b, d).area();
	}

	virtual double perimeter() const {
		return 2 * (distance(a, c) + distance(a, d));
	}

	virtual void print() const {
		a.print();
		std::cout << " ";
		b.print();
		std::cout << std::endl;
	}

	virtual Shape* clone() const {
		return new Rectangle(*this);
	}

private:
	Point a, b;
	Point c, d;
};