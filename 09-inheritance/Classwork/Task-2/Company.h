#pragma once
#include "Employee.h"
#include <iostream>

class Company {
public:
	Company()
		: employees(nullptr), size(0), capacity(2) {
		employees = new Employee[capacity];
	}

	Company(const Company& other) = delete;
	Company& operator=(const Company& other) = delete;

	~Company() {
		delete[] employees;
	}

	void add_employee(const Employee& employee) {
		if (size >= capacity)
			resize();

		employees[size++] = employee;
	};

	void add_employee(const char* name, size_t age, double salary) {
		add_employee(Employee(name, age, salary));
	};

	void print_all() const {
		for (size_t i = 0; i < size; ++i) {
			std::cout << employees[i] << std::endl; 
		}
	}

	bool has_employee(const char* name) const {
		return find(name) != -1;
	}

	void print_employee(const char* name) const {
		int index = find(name);
		if (index == -1) return;
		std::cout << employees[index];
	}

private:
	int find(const char* name) const {
		Employee temp(name, 0, 0);
		for (size_t i = 0; i < size; ++i) {
			if (temp == employees[i])
				return i;
		}
		return -1;
	}

	void resize() {
		Employee* new_employees = new Employee[capacity *= 2];
		for (size_t i = 0; i < size; ++i)
			new_employees[i] = employees[i];
		
		delete[] employees;
		employees = new_employees;
	}

private:
	Employee* employees;
	size_t size;
	size_t capacity;
};

