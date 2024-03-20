#include "String.h"
#include <iostream>

class Person {
public:
	Person() = default;
	/*Person(const String& name) 
		:name(name)
	{}*/
	Person(String&& name)
		:name(std::move(name))
	{}
private:
	String name;
};

int main() {
	String pesho("Pesho");
	String gosho("Gosho");

	pesho.append(gosho);
	pesho.print();

	return 0;
}