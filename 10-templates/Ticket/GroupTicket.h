#pragma once
#include "Ticket.h"
const size_t MIN_GROUP_SIZE = 20;

class GroupTicket : public Ticket {
public:
	GroupTicket();
	GroupTicket(const char* title, double price, size_t group_size);

	friend std::ostream& operator<<(std::ostream& out, const GroupTicket& t);

private:
	size_t group_size;
};