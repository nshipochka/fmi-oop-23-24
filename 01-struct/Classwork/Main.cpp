#include "Student.h"
#include <iostream>

const Student* compare(const Student* s1, const Student* s2) {
	return (s1->getAvgGrade() > s2->getAvgGrade()) ? s1 : s2;
}

Student bestAvgGradeStudent(Student* students, size_t size) {
	const Student* max = students; // Сочи към първия студент

	for (size_t i = 1; i < size; ++i) {
		max = compare(max, (students + i));
	}

	return *max; // Тук какво се случва като памет?
}

int main() {
	Student students[3];

	for (size_t i = 0; i < 3; ++i) {
		students[i].allocateMemory();

		students[i].inputName();
		students[i].inputAge();
		students[i].inputFn();

		students[i].inputGrade();
		students[i].inputGrade();
		students[i].inputGrade();
	}

	for (size_t i = 0; i < 3; ++i) {
		students[i].printStudent();
	};

	bestAvgGradeStudent(students, 3).printStudent();

	for (size_t i = 0; i < 3; ++i) {
		students[i].deallocateMemory();
	};

	return 0;
}