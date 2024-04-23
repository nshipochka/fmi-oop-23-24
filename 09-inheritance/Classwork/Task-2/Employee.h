#pragma once
#include "Person.h"

class Employee : public Person {
public:
	Employee() : Person(), salary(0) {} // We write this one, because we want to use it and it won't generate automatically 
										// because we've also written a ctor w/ arguments
	Employee(const char* name, size_t age, double salary)
		: Person(name, age), salary(salary) {}

	// Otherwise, rule of 0, because we have no dynamic data in this class

	friend std::ostream& operator<<(std::ostream& out, const Employee& employee);
	// If we don't overload this operator, we can still use << for Employee, but we will << only the "Person" part of it

	// No need to overload operator==, as we only compare the names, which is a member of "Person" anyway
	// In a normal scenario, where we also compare salaries, we would have to write that too

private:
	double salary;
};

std::ostream& operator<<(std::ostream& out, const Employee& employee) {
	out << Person(employee) << ", " << employee.salary;
	return out;
}