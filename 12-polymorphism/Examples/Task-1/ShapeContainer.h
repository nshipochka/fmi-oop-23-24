#pragma once
#include "Shape.h"
class ShapeContainer {
public:
	ShapeContainer() 
		: size(0), capacity(10) {
		shapes = new Shape * [capacity];
	};

	ShapeContainer(const ShapeContainer& other) = delete;
	ShapeContainer& operator=(const ShapeContainer& other) = delete;
	
	~ShapeContainer() {
		for (size_t i = 0; i < size; ++i)
			delete shapes[i];
		delete[] shapes;
	}

	void add(Shape* s) {
		if (size >= capacity)
			throw std::out_of_range("Container has no more capacity");
		
		shapes[size] = s->clone();
		size++;
	}

	void contains(Point p) const {
		bool flag = false;
		for (size_t i = 0; i < size; ++i) {
			if (shapes[i]->contains(p)) {
				shapes[i]->print();
				flag = true;
			}
		}
		if (!flag)
			std::cout << "No shapes contain this point\n";
	}

	void printArea(size_t index) const {
		if (index >= size)
			throw std::out_of_range("Index not in container");

		std::cout << shapes[index]->area();
	}

	void printArea() const {
		for (size_t i = 0; i < size; ++i) {
			printArea(i);
			std::cout << std::endl;
		}
	}

	void printPerimeter(size_t index) const {
		if (index >= size)
			throw std::out_of_range("Index out of range");

		std::cout << shapes[index]->perimeter();
	}

	void printPerimeter() const {
		for (size_t i = 0; i < size; ++i) {
			printPerimeter(i);
			std::cout << std::endl;
		}
	}

private:
	Shape** shapes;
	size_t size;
	size_t capacity;
};