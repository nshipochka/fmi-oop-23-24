#include "University.h"

University::University(const char* name) {
	size_t size = strlen(name) + 1;
	this->name = new char[size];
	strcpy_s(this->name, size, name);

	filled = 0;
	allocated = 5;
	students = new Student[allocated];
}

University::~University() {
	delete[] name;
	delete[] students;
}

void University::add_student(const Student& s) {
	if (filled >= allocated)
		resize();

	students[filled++] = s;
}

void University::add_student(const char* name, unsigned short age) {
	if (filled >= allocated)
		resize();

	students[filled++] = Student(name, age);
}

void University::serialize() const {
	char* filename;
	generate_filename(filename);

	std::ofstream out;
	out.open(filename, std::ios::binary);
	if (!out)
		throw std::exception("Can't open file\n");

	size_t size = strlen(name) + 1;
	out.write(reinterpret_cast<const char*>(&size), sizeof(size_t));
	out.write(name, size * sizeof(char));

	out.write(reinterpret_cast<const char*>(&filled), sizeof(size_t));

	for (size_t i = 0; i < filled; ++i)
		students[i].serialize(out);

	delete[] filename;
	out.close();
}

void University::deserialize() {
	char* filename;
	generate_filename(filename);

	std::ifstream in;
	in.open(filename, std::ios::binary);
	if (!in)
		throw std::exception("Can't open file\n");

	// Тук четем размера на името на университета и самото име
	size_t size;
	in.read(reinterpret_cast<char*>(&size), sizeof(size_t));
	in.read(name, size * sizeof(char));

	// Тук четем броя на записаните студенти
	in.read(reinterpret_cast<char*>(&size), sizeof(size_t));

	// Ако не искаме да пазим дотук съществуващите студенти:
	/*delete[] students;
	students = new Student[size];
	allocated = size;
	filled = 0;*/

	// Тук четем всеки студент използвайки функцията за четене на Student 
	// и после този, който сме прочели го добавяме към университета
	Student temp;
	for (size_t i = 0; i < size; ++i) {
		temp.deserialize(in);
		add_student(temp); 
	}

	delete[] filename;
	in.close();
}

void University::print(std::ostream& out) const {
	out << name << std::endl;
	for (size_t i = 0; i < filled; ++i)
		students[i].print(out);
}

void University::resize() {
	Student* temp = new Student[allocated * 2];

	for (size_t i = 0; i < filled; ++i)
		temp[i] = students[i];

	delete[] students;
	students = temp;
	allocated *= 2;
}

void University::generate_filename(char*& filename) const {
	size_t size = strlen("binary_") + strlen(name) + 1;
	filename = new char[size];
	strcpy_s(filename, size, "binary_");
	strcat_s(filename, size, name);
}

