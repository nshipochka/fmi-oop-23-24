#pragma once
#include "Point.h"
class Shape {
public:
	virtual bool contains(const Point& p) const = 0;
	virtual double area() const = 0;
	virtual double perimeter() const = 0;
	virtual void print() const = 0;
	virtual Shape* clone() const = 0;

	virtual ~Shape() {}
};
