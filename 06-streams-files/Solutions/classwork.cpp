#include <ostream>
#include <istream>
#include <fstream>
#include <iostream>

struct Person {
	char* name;
	int fn;
};


std::ofstream& serialize(const Person& p, std::ofstream& out) {
	if (!out)
		return out;

	// With dynamic memory
	size_t size = strlen(p.name) + 1;
	out.write((const char*) &size, sizeof(size));
	out.write(p.name, size);
	out.write((const char*) &p.fn, sizeof(p.fn));

	// Static memory/ known sizes
	//out.write((const char*)&p, sizeof(p));
	return out;
}

std::ifstream& deserialize(Person& p, std::ifstream& in) {
	if (!in)
		return in;

	// With dynamic memory
	size_t size;
	in.read((char*) &size, sizeof(size));

	delete[] p.name;
	p.name = new char[size];

	in.read(p.name, size);
	in.read((char*) &p.fn, sizeof(p.fn));

	// Static memory/ known sizes
	//in.read((char*)&p, sizeof(p));
	return in;
}

std::ostream& write(const Person& p, std::ostream& out) {
	if (!out)
		return out;

	out << p.name << "\n";
	out << p.fn << "\n";
}

std::istream& read(Person& p, std::istream& in) {
	if (!in)
		return in;

	in >> p.name;
	in >> p.fn;
}


bool write_to_binfile(const Person& p, const char* filename) {
	std::ofstream out_file;
	out_file.open(filename, std::ios::binary);
	if (!out_file)
		return false;

	serialize(p, out_file);

	out_file.close();
	return true;
}

bool write_to_txtfile(const Person& p, const char* filename) {
	std::ofstream out_file;
	out_file.open(filename);
	if (!out_file)
		return false;

	write(p, out_file);

	out_file.close();
}

int main() {
	Person p;
	
	read(p, std::cin);
	write_to_binfile(p, "Student.bin");

	return 0;
}
