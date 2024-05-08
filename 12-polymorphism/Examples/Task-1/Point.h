#pragma once
#include <cmath>
#include <iostream>
struct Point {
	double x, y;
	Point() : x(0), y(0) {}
	Point(double x, double y) : x(x), y(y) {}
	void print() const {
		std::cout << x << " " << y;
	}
};

inline double distance(const Point& p1, const Point& p2) {
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}