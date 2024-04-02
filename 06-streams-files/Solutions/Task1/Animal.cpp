#include "Animal.h"
#include <iostream>

Animal::Animal() 
	:name(nullptr),
	breed(nullptr),
	age(0),
	owner(nullptr)
{}


Animal::Animal(const char* name, const char* breed, unsigned short age, const char* owner)
	:Animal() 
	// За да можем да викаме copy, в което се трие, 
	// трябва указателите ни да са nullptr (или да сочат някаква валидна памет), 
	// което го правим наготово с констр. по подразбиране
{
	copy(this->name, strlen(name) + 1, name);
	copy(this->breed, strlen(breed) + 1, breed);
	this->age = age;
	copy(this->owner, strlen(owner) + 1, owner);
}

Animal::Animal(const Animal& other)
	: Animal() 
{
	copy(other);
}

Animal& Animal::operator=(const Animal& other) {	
	if (this != &other) {
		free();
		copy(other);
	}
	return *this;
}

Animal::~Animal() {
	free();
}

void Animal::serialize(std::ofstream& fout) const {
	serialize_str(fout, name);
	serialize_str(fout, breed);
	fout.write(reinterpret_cast<const char*>(&age), sizeof(unsigned short));
	serialize_str(fout, owner);
}

void Animal::deserialize(std::ifstream& fin) {
	deserialize_str(fin, name);
	deserialize_str(fin, breed);
	fin.read(reinterpret_cast<char*>(&age), sizeof(unsigned short));
	deserialize_str(fin, owner);
}

void Animal::output(std::ofstream& fout) const {
	if (!name || !breed || !owner)
		return;

	fout << name << std::endl;
	fout << breed << std::endl;
	fout << age << std::endl;
	fout << owner << std::endl;
}

void Animal::input(std::ifstream& fin) {
	input_str(fin, name);
	input_str(fin, breed);
	fin >> age;
	fin.get(); // Взимаме непрочетения нов ред
	input_str(fin, owner);
}

void Animal::write_to_file(const char* filename) const {
	std::ofstream fout;
	fout.open(filename, std::ios::binary);
	if (!fout)
		throw std::exception("File can't be opened!\n");

	serialize(fout);
	fout.close();
}

void Animal::read_from_file(const char* filename) {
	std::ifstream fin;
	fin.open(filename, std::ios::binary);
	if (!fin)
		throw std::exception("File can't be opened!\n");

	deserialize(fin);
	fin.close();
}

void Animal::print() const {
	if (!name || !breed || !owner)
		return;

	std::cout << name 
		<< " " << breed 
		<< " " << age 
		<< " " << owner 
		<< std::endl;
}

void Animal::copy(char*& dest, size_t size, const char* src) {
	delete[] dest;
	dest = new char[size];
	strcpy_s(dest, size, src);
}

void Animal::copy(const Animal& other) {
	copy(name, strlen(other.name) + 1, other.name);
	copy(breed, strlen(other.breed) + 1, other.breed);
	age = other.age;
	copy(owner, strlen(other.owner) + 1, other.owner);
}

void Animal::free() {
	delete[] name;
	delete[] breed;
	delete[] owner;

	name = nullptr;
	breed = nullptr;
	owner = nullptr;
}

void Animal::serialize_str(std::ofstream& fout, const char* str) const {
	if (!str)
		return;

	size_t size = strlen(str) + 1;
	fout.write(reinterpret_cast<const char*>(&size), sizeof(size_t));
	fout.write(str, size * sizeof(char));
	// Понеже записваме масив от char-ове, чиито размер е по 1 байт, size * sizeof = size
	// Ако е масив от друг тип, size * sizeof(<type>) дава размера в битове на масива 
}

void Animal::deserialize_str(std::ifstream& fin, char*& str) {
	size_t size;
	fin.read(reinterpret_cast<char*>(&size), sizeof(size_t));

	// Като ще четем нещо и ще го презаписваме, не трябва да забравяме
	// да си освободим дотук паметта и да заделим нова с подходящ размер
	delete[] str;
	str = new char[size];

	fin.read(str, size * sizeof(char));
}

void Animal::input_str(std::ifstream& fin, char*& str) {
	char buffer[1024];
	fin.getline(buffer, 1024);
	size_t size = strlen(buffer) + 1;
	
	// Освобождаваме паметта 
	delete[] str;
	str = new char[size];

	strcpy_s(str, size, buffer);
}
