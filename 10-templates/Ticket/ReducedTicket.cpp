#include "ReducedTicket.h"
#include <iostream>

ReducedTicket::ReducedTicket()
	: Ticket(), owner(nullptr)
{}

ReducedTicket::ReducedTicket(const char* title, double price, const char* owner)
	:Ticket(title, price), owner(nullptr) {
	copy(this->owner, owner);
	reduce_price(price * 1 / 2);
}

ReducedTicket::ReducedTicket(const ReducedTicket& other) 
	: Ticket(other), owner(nullptr) {
	copy(owner, other.owner);
}

ReducedTicket& ReducedTicket::operator=(const ReducedTicket& other) {
	if (this != &other) {
		Ticket::operator=((Ticket)other);
		copy(owner, other.owner);
	}
	return *this;
}

ReducedTicket::ReducedTicket(ReducedTicket&& other)
	: Ticket(std::move(other)), owner(nullptr) {
	owner = other.owner;
	other.owner = nullptr;
}

ReducedTicket& ReducedTicket::operator=(ReducedTicket&& other) {
	if (this != &other) {
		Ticket::operator=(std::move(other));
		
		delete[] owner;
		owner = other.owner;
		other.owner = nullptr;
	}
	return *this;
}

ReducedTicket::~ReducedTicket() {
	delete[] owner;
}

std::ostream& operator<<(std::ostream& out, const ReducedTicket& t) {
	out << (Ticket)t << ", " << t.owner;
	return out;
}