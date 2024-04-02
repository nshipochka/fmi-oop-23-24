#include "Animal.h"
#include <iostream>
#include <fstream>

int main() {
	std::ofstream out_bin("file.dat", std::ios::binary);
	std::ofstream out_txt("file.txt");

	if (!out_bin || !out_txt)
		std::cerr << "One (or more) file(s) cannot be opened!\n";

	Animal cow("Milka", "alpiiska krava", 3, "Baba Mila");
	cow.serialize(out_bin);
	cow.output(out_txt);

	out_bin.close();
	out_txt.close();

	std::ifstream in_bin("file.dat", std::ios::binary);
	std::ifstream in_txt("file.txt");

	if(!in_bin || !in_txt)
		std::cerr << "One (or more) file(s) cannot be opened!\n";

	Animal cow_cpy1;
	Animal cow_cpy2;

	cow_cpy1.deserialize(in_bin);
	cow_cpy1.print();

	cow_cpy2.input(in_txt);
	cow_cpy2.print();

	in_bin.close();
	in_txt.close();

	return 0;
}
