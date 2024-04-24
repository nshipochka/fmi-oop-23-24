#include "Queue.h"

int main() {
	Queue<int> q;
	q.enqueue(5);
	q.enqueue(6);
	q.print();
	std::cout << std::endl << q.peek();
	q.dequeue();
	std::cout << std::endl;
	q.print();
}