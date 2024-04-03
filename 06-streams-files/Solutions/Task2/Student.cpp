#include "Student.h"
#include <iostream>

Student::Student() 
	:name(nullptr),
	age(0)
{}

Student::Student(const char* name, unsigned short age) 
	:Student()
{
	copy(this->name, name);
	this->age = age;
}

Student::Student(const Student& other)
	:Student()
{
	copy(this->name, other.name);
	this->age = other.age;
}

Student& Student::operator=(const Student& other)
{
	if (this != &other) {
		delete[] name;
		copy(name, other.name);
		age = other.age;
	}
	return *this;
}

Student::~Student() {
	delete[] name;
}

void Student::serialize(std::ofstream& out) const {
	size_t size = strlen(name) + 1;
	out.write(reinterpret_cast<const char*>(&size), sizeof(size_t));
	out.write(name, size * sizeof(char));
	out.write(reinterpret_cast<const char*>(&age), sizeof(unsigned short));
}

void Student::deserialize(std::ifstream& in) {
	size_t size;
	in.read(reinterpret_cast<char*>(&size), sizeof(size_t));

	delete[] name;
	name = new char[size];
	in.read(name, size * sizeof(char));

	in.read(reinterpret_cast<char*>(&age), sizeof(unsigned short));
}

void Student::print(std::ostream& out) const {
	out << name << ", " << age << std::endl;
}

void Student::copy(char*& dest, const char* src) {
	size_t size = strlen(src) + 1;

	delete[] dest;
	dest = new char[size];

	strcpy_s(dest, size, src);
}

