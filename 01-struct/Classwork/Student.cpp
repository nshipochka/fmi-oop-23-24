#include "Student.h"
#include <iostream>

const size_t MAX_SIZE = 1024;

void Student::allocateMemory() {
	grades = new double[2];
	gradesCapacity = 2;
	gradesSize = 0;
}

void Student::deallocateMemory() {
	delete[] grades;
	delete[] name;
}

void Student::resizeGrades() {
	double* temp = grades;
	grades = new double[gradesCapacity * 2];

	for (size_t i = 0; i < gradesSize; ++i)
		grades[i] = temp[i];

	delete[] temp;
	gradesCapacity *= 2;
}

void Student::inputName() {
	std::cout << "Name: ";
	delete[] name; // Ако е имало друго име преди това, го трием

	if (std::isspace(std::cin.peek())) { // Ако нещото, което предстои в буфера на входа, е whitespace
		std::cin >> std::ws; // Изчистваме водещите whitespaces от входа
	}

	char buffer[MAX_SIZE];
	std::cin.getline(buffer, MAX_SIZE);

	name = new char[strlen(buffer) + 1];
	strcpy_s(name, strlen(buffer) + 1, buffer);
}

void Student::inputAge() {
	std::cout << "Age: ";
	std::cin >> age;
}

void Student::inputFn() {
	std::cout << "Fn: ";
	std::cin >> fn; 
	// Знаем, че е поредица от символи без whitespaces между тях
	// => Няма нужда да е с getline
}

void Student::inputGrade() {
	std::cout << "A grade: ";
	if (gradesSize == gradesCapacity) // Ако сме изчерпали празното място за оценки
		resizeGrades(); // Преоразмеряваме масива, че да имаме още място

	std::cin >> grades[gradesSize]; // Добавяме нова оценка на първото празно място
	gradesSize++;
}

void Student::printName() const {
	std::cout << "Name: " << name << std::endl;
}

void Student::printAge() const {
	std::cout << "Age: " << age << std::endl;
}

void Student::printFn() const {
	std::cout << "Fn: " << fn << std::endl;
}

void Student::printGrades() const {
	std::cout << "Grades: " << std::endl;
	for (size_t i = 0; i < gradesSize; ++i)
		std::cout << "\t" << grades[i] << std::endl;
}

void Student::printStudent() const {
	printName();
	printAge();
	printFn();
	printGrades();
}

double Student::getAvgGrade() const {
	double avg = 0;

	for (size_t i = 0; i < gradesSize; ++i)
		avg += grades[i];

	avg /= gradesSize;
	return avg;
}











