#include "IntArr.h"
#include <iostream>
#include <stdexcept>

//
// Big 4
//
IntArr::IntArr()
	:size(0), 
	capacity(2),
	arr(new int[capacity])
{}

IntArr::IntArr(const IntArr& other) {
	copy(other);
}

IntArr& IntArr::operator=(const IntArr& other) {
	if (this != &other) {
		clear();
		copy(other);
	}

	return *this;
}

IntArr::~IntArr() {
	clear();
}

//
// Operators
//

//
// Other Members
//

//Принтира във вида [ 1 2 3 4 ]
void IntArr::print() const {
	std::cout << "[ ";

	for (size_t i = 0; i < size; ++i)
		std::cout << arr[i] << " ";

	std::cout << "]\n";
}

//
// Private methods:
//

//Копира стойностите от друг IntArr
void IntArr::copy(const IntArr& other) {
	size = other.size;
	capacity = other.capacity;

	arr = new int[capacity];
	for (size_t i = 0; i < size; i++)
		this->arr[i] = other.arr[i];
}

//Изчиства паметта
void IntArr::clear() {
	delete[] arr;
	arr = nullptr;
}

//Преоразмеряваме масива
void IntArr::resize() {
	int* temp = new int[2 * capacity];

	for (size_t i = 0; i < size; ++i)
		temp[i] = arr[i];

	delete[] arr;
	arr = temp;
	capacity *= 2;
}