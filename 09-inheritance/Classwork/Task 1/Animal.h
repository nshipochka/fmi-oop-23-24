#pragma once
#include <cstring>
#include <iostream>

class Animal {
public:
	Animal() : name(nullptr), age(0) {}

	Animal(const char* _name, unsigned _age) 
		: name(nullptr)
	{
		copy(name, _name);
		age = _age;
	}

	Animal(const Animal& other) 
		: Animal(other.name, other.age) {}

	Animal& operator=(const Animal& other) {
		if (this != &other) {
			copy(name, other.name);
			age = other.age;
		}
		return *this;
	}

	void changeName(const char* _name) {
		copy(name, _name);
	}

	void print() const {
		if (name)
			std::cout << name << ", " << age << std::endl;
	}

protected:
	void copy(char*& dest, const char* src) {
		delete[] dest;
		if (!src)
			dest = nullptr;
		else {
			size_t sz = strlen(src) + 1;
			dest = new char[sz];
			strcpy_s(dest, sz, src);
		}
	}
private:
	char* name;
	unsigned age;
};