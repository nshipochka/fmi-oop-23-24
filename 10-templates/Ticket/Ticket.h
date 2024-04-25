#pragma once
#include <ostream>

class Ticket {
public:
	Ticket();
	Ticket(const char* title, double price);
	
	Ticket(const Ticket& other);
	Ticket& operator=(Ticket& other);
	
	Ticket(Ticket&& other) noexcept;
	Ticket& operator=(Ticket&& other) noexcept;
	
	~Ticket();

	friend std::ostream& operator<<(std::ostream& out, const Ticket& t);

protected:
	void reduce_price(double amount);
	void copy(char*& dest, const char* src);

private:
	void copy(Ticket&& other);

private:
	char* title;
	double price;
};

