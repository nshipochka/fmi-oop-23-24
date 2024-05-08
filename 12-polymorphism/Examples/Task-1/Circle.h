#pragma once
#include "Shape.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

class Circle : public Shape {
public:
	Circle() : center(), radius(0) {}
	Circle(Point _center, double _radius)
		: center(_center), radius(_radius) {}

	virtual bool contains(const Point& p) const {
		if (distance(p, center) <= radius)
			return true;
		return false;
	}

	virtual double area() const {
		return radius * radius * M_PI;
	}

	virtual double perimeter() const {
		return radius * 2 * M_PI;
	}

	virtual void print() const {
		center.print();
		std::cout << " " << radius;
		std::cout << std::endl;
	}

	virtual Shape* clone() const {
		return new Circle(*this);
	}

private:
	Point center;
	double radius;
};