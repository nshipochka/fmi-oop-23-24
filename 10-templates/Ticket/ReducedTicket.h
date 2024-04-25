#pragma once
#include "Ticket.h"
class ReducedTicket : public Ticket {
public:
	ReducedTicket();
	ReducedTicket(const char* title, double price, const char* owner);
	
	ReducedTicket(const ReducedTicket& other);
	ReducedTicket& operator=(const ReducedTicket& other);
	
	ReducedTicket(ReducedTicket&& other);
	ReducedTicket& operator=(ReducedTicket&& other);
	
	~ReducedTicket();

	friend std::ostream& operator<<(std::ostream& out, const ReducedTicket& t);
private:
	char* owner;
};