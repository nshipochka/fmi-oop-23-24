#pragma once
#include "Point.h"

class Circle {
public:
	Circle();
	Circle(double x, double y, double radius);
	
	double area() const;
	void printQuadrant() const;
	void print() const;

private:
	Point center;
	double radius;
};

Circle::Circle() 
	: center(), radius(0)
{};

Circle::Circle(double x, double y, double radius)
	: center(x, y), radius(radius)
{};

double Circle::area() const {
	return 3.14 * radius * radius;
}

void Circle::printQuadrant() const {
	center.printQuadrant();
}

void Circle::print() const {
	std::cout << "-----------------" << std::endl;
	std::cout << "Circle" << std::endl;
	std::cout << "center: ";
	center.print();
	std::cout << "quadrant: ";
	printQuadrant();
	std::cout << "radius: " << radius << std::endl;
	std::cout << "area: " << area() << std::endl; // Тук area() връща лицето на текущия обект, за който ще викнем това print()
	std::cout << "-----------------" << std::endl;
}