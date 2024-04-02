#ifndef __ANIMAL__HEADER__DEFINED__
#define __ANIMAL__HEADER__DEFINED__

#include <fstream>

class Animal {
public:
	Animal();
	Animal(const char*, const char*, unsigned short, const char*);
	Animal(const Animal&);
	Animal& operator=(const Animal&);
	~Animal();

	void serialize(std::ofstream&) const;
	void deserialize(std::ifstream&);

	void output(std::ofstream&) const;
	void input(std::ifstream&);

	void write_to_file(const char*) const;
	void read_from_file(const char*);

	void print() const;

private:
	void copy(char*&, size_t, const char*);
	void copy(const Animal&);
	void free();
	void serialize_str(std::ofstream&, const char*) const;
	void deserialize_str(std::ifstream&, char*&);
	void input_str(std::ifstream&, char*&);

private:
	char* name;
	char* breed;
	unsigned short age;
	char* owner;
};


#endif
