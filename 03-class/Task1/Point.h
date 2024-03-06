#pragma once
#include<iostream>

class Point {
public:
	Point();
	Point(double x, double y);

	void printQuadrant() const;
	void print() const;

	double getX() const;
	double getY() const;

private:
	double x;
	double y;
};

Point::Point() 
	: x(0), y(0) 
{};

Point::Point(double x, double y) 
	: x(x), y(y) 
{};

void Point::print() const {
	std::cout << "x: " << x << ", y: " << y << std::endl;
}

void Point::printQuadrant() const { 
	if (x > 0 && y > 0) {
		std::cout << "First quadrant" << std::endl;
		return;
	}

	if (x < 0 && y > 0) {
		std::cout << "Second quadrant" << std::endl;
		return;
	}

	if (x < 0 && y < 0) {
		std::cout << "Third quadrant" << std::endl;
		return;
	}

	if (x > 0 && y < 0) {
		std::cout << "Fourth quadrant" << std::endl;
		return;
	}

	std::cout << "Point is (0, 0)" << std::endl;
}

double Point::getX() const {
	return x;
}

double Point::getY() const {
	return y;
}