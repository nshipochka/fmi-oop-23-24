#ifndef __STUDENT__HEADER__INCLUDED__
#define __STUDENT__HEADER__INCLUDED__

#include <fstream>

class Student {
public:
	Student();
	Student(const char* name, unsigned short age);
	Student(const Student& other);
	Student& operator=(const Student& other);
	~Student();

	// Записва студента във файлов поток 
	void serialize(std::ofstream& out) const;

	// Чете студента от файлов поток
	void deserialize(std::ifstream& in);

	// Извежда студента в поток за писане (какъвто и да е, може и cout да подадем)
	void print(std::ostream& out) const;

private:
	void copy(char*& dest, const char* src);

private:
	char* name;
	unsigned short age;
};

#endif
