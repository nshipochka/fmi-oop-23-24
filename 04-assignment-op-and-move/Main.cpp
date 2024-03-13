#include "String.h"
#include<iostream>

class Person {
public:
	Person() = default;
	Person(String&& name) :
		m_name(std::move(name))
	{}
private:
	String m_name;
};


int main() {
	String a("Pesho");
	Person p("Pesho");

	return 0;
}