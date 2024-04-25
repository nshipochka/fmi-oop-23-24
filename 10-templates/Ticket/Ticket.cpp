#include "Ticket.h"
#include <cstring>
#include <iostream>

Ticket::Ticket() 
	: title(nullptr), price(0) 
{}

Ticket::Ticket(const char* title, double price) 
	: Ticket() {
	this->price = price;
	copy(this->title, title);
}

Ticket::Ticket(const Ticket& other) 
	: Ticket(other.title, other.price)
{}

Ticket& Ticket::operator=(Ticket & other) {
	if (this != &other) {
		price = other.price;
		copy(title, other.title);
	}
	return *this;
}

Ticket::Ticket(Ticket&& other) noexcept 
	: Ticket() {
	copy(std::move(other));
}

Ticket& Ticket::operator=(Ticket&& other) noexcept {
	if (this != &other) {
		copy(std::move(other));
	}
	return *this;
}

Ticket::~Ticket() {
	delete[] title;
}

void Ticket::reduce_price(double amount) {
	price = std::max(price - amount, 0.0);
}

void Ticket::copy(char*& dest, const char* src) {
	delete[] dest;

	if (!src) {
		dest = nullptr;
		return;
	}

	size_t sz = strlen(src) + 1;
	dest = new char[sz];
	strcpy_s(dest, sz, src);
}

void Ticket::copy(Ticket&& other) {
	price = other.price;
	
	delete[] title;
	title = other.title;
	other.title = nullptr;
}

std::ostream& operator<<(std::ostream& out, const Ticket& t) {
	out << t.title << " " << t.price;
	return out;
}