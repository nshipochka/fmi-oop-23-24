#pragma once
#include <cstring>
#include <fstream>

class Person {
public:
	Person() : name(nullptr), age(0) {};

	Person(const char* name, size_t age)
		: name(nullptr), age(age) {
		copy(this->name, name);
	}

	Person(const Person& other)
		: Person(other.name, other.age) {}

	Person& operator=(const Person& other) {
		if (this != &other) {
			copy(name, other.name);
			age = other.age;
		}
		return *this;
	}

	Person(Person&& other) noexcept {
		name = other.name;
		age = other.age;

		other.name = nullptr;
	}

	Person& operator=(Person&& other) noexcept {
		if (this != &other) {
			delete[] name;
			
			name = other.name;
			age = other.age;

			other.name = nullptr;
		}
		return *this;
	}

	~Person() {
		delete[] name;
	}

	friend std::ostream& operator<<(std::ostream& out, const Person& person);
	friend bool operator==(const Person& lhs, const Person& rhs);

private:
	void copy(char*& dest, const char* src) {
		delete[] dest;

		if (!src) dest = nullptr;
		else {
			dest = new char[strlen(src) + 1];
			strcpy_s(dest, strlen(src) + 1, src);
		}
	}

private:
	char* name;
	size_t age;
};

std::ostream& operator<<(std::ostream& out, const Person& person) {
	out << person.name << ", " << person.age;
	return out;
}

bool operator==(const Person& lhs, const Person& rhs) { 
	return !strcmp(lhs.name, rhs.name); 
	// For simplicity of the demonstration, we will assume the only unique quality of a person or an employee is their name
}