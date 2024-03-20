#pragma once
#include "Point.h"

class Rectangle {
public:
	Rectangle();
	Rectangle(double x, double y, double length, double width);

	double area() const;
	void printAllPoints() const;
	void printQuadrant() const;
	void print() const;

private:
	Point point;
	double length;
	double width;
};

Rectangle::Rectangle() 
	: point(), length(0), width(0) 
{}

Rectangle::Rectangle(double x, double y, double length, double width)
	: point(x, y), length(length), width(width)
{}

double Rectangle::area() const {
	return length * width;
}

void Rectangle::printAllPoints() const {
	std::cout << "Upper left corner: ";
	point.print();

	std::cout << "Lower left corner: ";
	Point(point.getX() - length, point.getY()).print(); // Може да създадем нова точка с нужните координати и да преизползваме print на Point

	std::cout << "Upper right corner: ";
	std::cout << point.getX() << " " << point.getY() + width << std::endl; // Може и просто да си изведем каквото сме сметнали

	std::cout << "Lower right corner: ";
	std::cout << point.getX() - length << " " << point.getY() + width << std::endl;
}

void Rectangle::printQuadrant() const {
	point.printQuadrant();
}

void Rectangle::print() const {
	std::cout << "-----------------" << std::endl;
	std::cout << "Rectangle" << std::endl;
	std::cout << "starting point: ";
	point.print();
	std::cout << "quadrant: ";
	printQuadrant();
	std::cout << "area: " << area() << std::endl;
	std::cout << "vertices: " << std::endl;
	printAllPoints();
	std::cout << "-----------------" << std::endl;
}