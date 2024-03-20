#pragma once
class Employee {
public:
	Employee();
	Employee(const char* name, unsigned age, double salary);
	Employee(const Employee& other);
	~Employee();

	const char* getName() const;
	unsigned getAge() const;
	double getSalary() const;

	void setName(const char* name);
	void setAge(unsigned age);
	void setSalary(double salary);

	void print() const;

private:
	char* name;
	unsigned age;
	double salary;
};