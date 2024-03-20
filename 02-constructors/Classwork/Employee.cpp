#include "Employee.h"
#include <cstring>
#include <iostream>

Employee::Employee() : name(new char[50]), age(0), salary(0) {
	strcpy_s(name, 50, "Nobody");
}

Employee::Employee(const char* name, unsigned age, double salary) 
	: name(new char[strlen(name) + 1]), age(age), salary(salary){
	strcpy_s(this->name, strlen(name) + 1, name);
}

Employee::Employee(const Employee& other) 
	: Employee(other.name, other.age, other.salary)
{
	/*name = new char[strlen(other.name) + 1];
	strcpy_s(name, strlen(other.name) + 1, other.name);

	age = other.age;
	salary = other.salary;*/
}

Employee::~Employee() {
	delete[] name;
}

const char* Employee::getName() const {
	return name;
}

unsigned Employee::getAge() const
{
	return age;
}

double Employee::getSalary() const
{
	return salary;
}

void Employee::setName(const char* name) {
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Employee::setAge(unsigned age)
{	
	this->age = age;
}

void Employee::setSalary(double salary)
{
	this->salary = salary;
}

void Employee::print() const {

	std::cout << name << " " << age << " " << salary << std::endl;
}





