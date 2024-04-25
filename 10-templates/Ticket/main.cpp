#include "Ticket.h"
#include "ReducedTicket.h"
#include "GroupTicket.h"
#include "../Queue/Queue.h"

int main() {
	Ticket t("Otello", 20);
	ReducedTicket rt("Otello", 20, "Pesho");
	GroupTicket gt("Otello", 20, 21);

	std::cout << "Normal print: \n";
	std::cout << t << std::endl;
	std::cout << rt << std::endl;
	std::cout << gt << std::endl;

	Queue<Ticket> q;
	q.enqueue(t);
	q.enqueue(rt);
	q.enqueue(gt);

	std::cout << "------------\n";
	std::cout << "Print from queue: \n";
	q.print();
	// Next time we'll see the reason for this difference ;)

	return 0;
}