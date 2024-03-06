#pragma once
#include "Point.h"

class Square {
public:
	Square();
	Square(double x, double y, double side);

	double area() const;
	void printAllPoints() const;
	void printQuadrant() const;
	void print() const;

private:
	Point point;
	double side;
};

Square::Square()
	: point(), side(0)
{}

Square::Square(double x, double y, double side)
	: point(x, y), side(side)
{}

double Square::area() const {
	return side * side;
}

void Square::printAllPoints() const {
	std::cout << "Upper left corner: ";
	point.print();

	std::cout << "Lower left corner: ";
	Point(point.getX() - side, point.getY()).print(); // Може да създадем нова точка с нужните координати и да преизползваме print на Point

	std::cout << "Upper right corner: ";
	std::cout << point.getX() << " " << point.getY() + side << std::endl; // Може и просто да си изведем каквото сме сметнали

	std::cout << "Lower right corner: ";
	std::cout << point.getX() - side << " " << point.getY() + side << std::endl;
}

void Square::printQuadrant() const {
	point.printQuadrant();
}

void Square::print() const {
	std::cout << "-----------------" << std::endl;
	std::cout << "Square" << std::endl;
	std::cout << "starting point: ";
	point.print();
	std::cout << "quadrant: ";
	printQuadrant();
	std::cout << "area: " << area() << std::endl;
	std::cout << "vertices: " << std::endl;
	printAllPoints();
	std::cout << "-----------------" << std::endl;
}