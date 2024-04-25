#include "GroupTicket.h"
#include <iostream>

GroupTicket::GroupTicket() 
	:Ticket(), group_size(0)
{}

GroupTicket::GroupTicket(const char* title, double price, size_t group_size) 
	: Ticket(title, price * group_size) {
	if (group_size < MIN_GROUP_SIZE)
		throw std::invalid_argument("Group size too small");

	this->group_size = group_size;
	reduce_price(group_size * 2);
}

std::ostream& operator<<(std::ostream& out, const GroupTicket& t) {
	out << (Ticket)t << ", group of " << t.group_size << " people";
	return out;
}
