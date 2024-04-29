#include <iostream>
// Examples to show: 
// 1) nothing virtual
// 2) only print virtual
// 3) print & dtor virtual

class Base {
public:
	Base() 
		: data(nullptr) 
	{ 
		std::cout << "Base: default ctor\n"; 
	}

	Base(int _data) 
		: data(new int{ _data }) 
	{ 
		std::cout << "Base: ctor w/ arguments (" << *data << ")\n"; 
	}

	Base(const Base& other) 
		: data(new int{ *other.data }) 
	{ 
		std::cout << "Base: copy ctor (" << *data << ")\n"; 
	}

	Base& operator=(const Base& other) 
	{
		std::cout << "Base: operator= (" << *data << "->" << *other.data << ")\n";
		if (this != &other) {
			delete data;
			data = new int;
			data = other.data;
		}
		return *this;
	}

	virtual ~Base() 
	{ 
		std::cout << "Base: dtor, deletes "<< *data <<"\n";
		delete data;
	}

	virtual void print() const 
	{ 
		std::cout << "Base: print (" << *data << ")\n"; 
	}

private:
	int* data;
};

class Derived : public Base {
public:
	Derived() 
		: Base(), 
		data(nullptr) 
	{ 
		std::cout << "Derived: default ctor\n"; 
	}

	Derived(int base_data, char derived_data) 
		: Base(base_data), 
		data(new char{ derived_data }) 
	{ 
		std::cout << "Derived: ctor w/ arguments (" << *data << ")\n"; 
	}

	Derived(const Derived& other) 
		: Base(other), 
		data(new char{ *other.data }) 
	{
		std::cout << "Derived: copy ctor (" << *data << ")\n"; 
	}

	Derived& operator=(const Derived& other) 
	{
		std::cout << "Derived: operator= (" << *data << "->" << *other.data << ")\n";
		if (this != &other) {
			Base::operator=(other);
			delete data;
			data = new char{ *other.data };
		}
		return *this;
	}

	virtual ~Derived() 
	{ 
		std::cout << "Derived: dtor, deletes " << *data << "\n";
		delete data; 
	};

	virtual void print() const 
	{ 
		Base::print();
		std::cout << "Derived: print(" << *data << ")\n";
	}

private:
	char* data;
};

int main() {
	// Objects:

	/*Derived d(1, 'd');

	std::cout << "---------\n";

	Base b = d;

	std::cout << "---------\n";

	b.print();

	std::cout << "---------\n";*/

	// Pointers: 

	/*Derived* d = new Derived(2, 'd');
	std::cout << "---------\n";
	Base* b = d;
	std::cout << "---------\n";

	b->print();

	delete b;*/
	//delete d;

	// References:

	/*Derived d(3, 'd');
	std::cout << "---------\n";

	Base& b = d;
	std::cout << "---------\n";

	d.print();
	std::cout << "---------\n";

	b.print();
	std::cout << "---------\n";*/

	// Array
	Base** array = new Base * [5];

	array[0] = new Base(0);
	array[1] = new Derived(1, 'b');
	array[2] = new Derived(2, 'c');
	array[3] = new Base(3);
	array[4] = new Derived(4, 'e');
	std::cout << "---------\n";

	for (size_t i = 0; i < 5; ++i) {
		array[i]->print();
		std::cout << "---------\n";
	}

	for (size_t i = 0; i < 5; ++i)
		delete array[i];

	delete[] array;
	return 0;
}