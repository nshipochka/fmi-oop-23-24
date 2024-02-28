#include "Employee.h"

int main() {
	Employee pesho("Pesho", 50, 1020);
	pesho.print();

	Employee gosho(pesho);
	gosho.print();

	return 0;
}