#include<iostream>
#include "University.h"

int main() {
	University su("Sofiiski-universitet");

	su.add_student("Pesho", 19);
	su.add_student("Gosho", 20);

	su.serialize();
	su.deserialize();

	su.print(std::cout);

	return 0;
}