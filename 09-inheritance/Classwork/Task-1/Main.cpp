#include <iostream>
#include "Animal.h"
#include "Pet.h"

int main() {
	Pet p("Tera", 1, "Nadi", 888);
	p.print();
	p.changeName("Mars");
	p.print();

	return 0;
}