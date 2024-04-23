#include "Company.h"

int main() {
	Company nai_dobrata_firma;

	nai_dobrata_firma.add_employee("Pesho", 21, 2000);
	nai_dobrata_firma.add_employee("Gosho", 20, 1900);
	nai_dobrata_firma.add_employee("Misho", 19, 1800);

	nai_dobrata_firma.print_all();
	
	std::cout << std::boolalpha
		<< nai_dobrata_firma.has_employee("Pesho") << std::endl
		<< nai_dobrata_firma.has_employee("Tosho") << std::endl;


	nai_dobrata_firma.print_employee("Pesho");
	nai_dobrata_firma.print_employee("Tosho");

	return 0;
}