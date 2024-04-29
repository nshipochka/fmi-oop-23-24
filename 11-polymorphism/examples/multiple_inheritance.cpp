#include <iostream>

class Base_1 {
public:
	Base_1() : data(-1) {
		std::cout << "Base_1: default ctor\n";
	}

	Base_1(int _data) : data(_data) {
		std::cout << "Base_1: ctor w/ arguments (" << data << ")\n";
	}

	Base_1(const Base_1& other) : data(other.data) {
		std::cout << "Base_1: copy ctor (" << data << ")\n";
	}

	Base_1& operator=(const Base_1& other) {
		std::cout << "Base_1: operator= (" << data << "->" << other.data << ")\n";
		if (this != &other)
			data = other.data;
		return *this;
	}

	~Base_1() {
		std::cout << "Base_1: dtor\n";
	}
	
	void print() const {
		std::cout << "Base_1: print (" << data << ")\n";
	}

private:
	int data;
};

class Base_2 {
public:
	Base_2() : data(-1) {
		std::cout << "Base_2: default ctor\n";
	}

	Base_2(int _data) : data(_data) {
		std::cout << "Base_2: ctor w/ arguments (" << data << ")\n";
	}

	Base_2(const Base_2& other) : data(other.data) {
		std::cout << "Base_2: copy ctor (" << data << ")\n";
	}

	Base_2& operator=(const Base_2& other) {
		std::cout << "Base_2: operator= (" << data << "->" << other.data << ")\n";
		if (this != &other)
			data = other.data;
		return *this;
	}

	~Base_2() {
		std::cout << "Base_2: dtor\n";
	}

	void print() const {
		std::cout << "Base_2: print (" << data << ")\n";
	}

private:
	int data;
};

class Derived : public Base_1, public Base_2 {
public:
	Derived() : Base_2(), Base_1(), data('\0') {
		std::cout << "Derived: default ctor\n";
	}

	Derived(int base_1_data, int base_2_data, char derived_data)
		: Base_1(base_1_data), Base_2(base_2_data), data(derived_data) {
		std::cout << "Derived: ctor w/ arguments (" << data << ")\n";
	}

	Derived(const Derived& other)
		: Base_1(other), Base_2(other), data(other.data) {
		std::cout << "Derived: copy ctor (" << data << ")\n";
	}

	Derived& operator=(const Derived& other) {
		std::cout << "Derived: operator= (" << data << "->" << other.data << ")\n";
		if (this != &other) {
			Base_1::operator=(other);
			Base_2::operator=(other);
			data = other.data;
		}
		return *this;
	}

	~Derived() {
		std::cout << "Derived: dtor, deletes " << data << "\n";
	};

	void print() const {
		Base_1::print();
		Base_2::print();
		std::cout << "Derived: print(" << data << ")\n";
	}

private:
	char data;
};

int main() {
	Derived d(1, 2, 'd');

	return 0;
}