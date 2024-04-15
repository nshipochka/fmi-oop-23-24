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

bool IntArr::operator!() const {
	return size == 0;
}

IntArr& IntArr::operator+=(int n) {
	if (size == capacity)
		resize();

	arr[size] = n;
	size++;

	return *this;
}

IntArr& IntArr::operator+=(const IntArr& rhs)
{	
	/*if (size + rhs.size >= capacity) {
		resize(rhs.capacity);
	}
	for (size_t i = size; i < size + rhs.size; ++i) {
		arr[i] = rhs.arr[i - rhs.size];
	}*/
	return *this;
}

IntArr& IntArr::operator*=(int n) {
	for (size_t i = 0; i < size; ++i)
		arr[i] *= n;

	return *this;
}

IntArr& IntArr::operator++()
{
	for (size_t i = 0; i < size; ++i)
		++arr[i];

	return *this;
}

IntArr IntArr::operator++(int n)
{
	IntArr old = *this;
	this->operator++();
	return old;
}

int& IntArr::operator[](size_t index) {
	return arr[index];
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

bool operator==(const IntArr& lhs, const IntArr& rhs) {
	if (lhs.size != rhs.size)
		return false;

	for (size_t i = 0; i < lhs.size; i++)
		if (lhs.arr[i] != rhs.arr[i])
			return false;

	return true;
}

bool operator!=(const IntArr& lhs, const IntArr& rhs)
{
	return !(lhs == rhs);
}

bool operator>(const IntArr& lhs, const IntArr& rhs) {
	size_t size = std::min({ lhs.size, rhs.size });
	for (size_t i = 0; i < size; ++i) {
		if (lhs.arr[i] <= rhs.arr[i])
			return false;
	}

	return true;
}

bool operator<(const IntArr& lhs, const IntArr& rhs)
{
	size_t size = std::min({ lhs.size, rhs.size });
	for (size_t i = 0; i < size; ++i) {
		if (lhs.arr[i] >= rhs.arr[i])
			return false;
	}

	return true;
}

bool operator>=(const IntArr& lhs, const IntArr& rhs)
{
	return !(lhs < rhs);
}

bool operator<=(const IntArr& lhs, const IntArr& rhs)
{
	return !(lhs > rhs);
}

std::ostream& operator<<(std::ostream& os, const IntArr& obj)
{	
	for (size_t i = 0; i < obj.size - 1; ++i) {
		os << obj.arr[i] << " ";
	}
	os << obj.arr[obj.size - 1];
	return os;
}

std::istream& operator>>(std::istream& is, IntArr& obj)
{	
	char c = 0;
	int num = 0;
	while (is >> num) {
		obj += num;
		is.get(c);
		if (c != ' ') break;
	}
	
	return is;
}

IntArr operator+(const IntArr& lhs, int rhs) {
	IntArr result = lhs;
	result += rhs;
	return result;
}





