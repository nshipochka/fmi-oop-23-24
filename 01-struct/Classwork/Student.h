#pragma once
struct Student {
	char* name = nullptr;
	unsigned age;
	char fn[11];

	double* grades = nullptr;
	size_t gradesSize; // Пазим докъде сме запълнили масива с оценки
	size_t gradesCapacity; // Пазим какъв брой елементи сме заделили за масива с оценки

	void allocateMemory(); 
	void deallocateMemory();
	
	void resizeGrades();

	void inputName();
	void inputAge();
	void inputFn();
	void inputGrade();

	void printName() const;
	void printAge() const;
	void printFn() const;
	void printGrades() const;

	void printStudent() const;

	double getAvgGrade() const;
};

