#ifndef __UNIVERSITY__HEADER__INCLUDED__
#define __UNIVERSITY__HEADER__INCLUDED__

#include "Student.h"

class University {
public:
	// University(); - този няма да се генерира
	// Не искаме потребителите да създават университети без имена
	University(const char* name);
	University(const University& other) = delete;
	University& operator=(const University& other) = delete;
	~University();

	void add_student(const Student& s);
	void add_student(const char* name, unsigned short age);

	void serialize() const;
	void deserialize();

	void print(std::ostream& out) const;

private:
	void resize();
	void generate_filename(char*& filename) const;

private:
	char* name;
	Student* students;
	size_t filled;
	size_t allocated;
};

#endif
