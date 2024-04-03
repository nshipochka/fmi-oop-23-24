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

	// ������� �������� ��� ������ ����� 
	void serialize(std::ofstream& out) const;

	// ���� �������� �� ������ �����
	void deserialize(std::ifstream& in);

	// ������� �������� � ����� �� ������ (������� � �� �, ���� � cout �� �������)
	void print(std::ostream& out) const;

private:
	void copy(char*& dest, const char* src);

private:
	char* name;
	unsigned short age;
};

#endif
