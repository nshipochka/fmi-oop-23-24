#pragma once
#include "Animal.h"

class Pet : public Animal {
public:
	Pet() : Animal(), owner(nullptr), phone(0) {}

	Pet(const char* _name, unsigned _age,
		const char* _owner, unsigned _phone) 
		: Animal(_name, _age),
		owner(nullptr),
		phone(_phone)
	{
		copy(owner, _owner);
	}

	Pet(const Pet& other) 
		:Animal(other),
		owner(nullptr),
		phone(other.phone)
	{
		copy(owner, other.owner);
	}

	Pet& operator=(const Pet& other) {
		if (this != &other) {
			Animal::operator=(other);
			copy(owner, other.owner);
			phone = other.phone;
		}
		return *this;
	}

	void print() const {
		Animal::print();
		std::cout << owner << ", " << phone << std::endl;
	}

	void changeOwner(const char* _owner, unsigned _phone) {
		copy(owner, _owner);
		phone = _phone;
	}

private:
	char* owner;
	unsigned phone;
};

