#include <iostream>

class A {
public:
	A() {
		a = 1;
		std::cout << "A()\n";
	};

	~A() {
		std::cout << "~A()\n";
	};

	void print() {
		std::cout << a << std::endl;
	}

	int a;
};

class B : public A {
public:
	B() : A() {
		b = 2;
		std::cout << "B()\n";
	};

	~B() {
		std::cout << "~B()\n";
	};

	int b;
};

class C : public A {
public:
	C() : A() {
		c = 3;
		std::cout << "C()\n";
	};

	~C() {
		std::cout << "~C()\n";
	};

	int c;
};

class D : public B, public C {
public:
	D() : B(), C() {
		d = 4;
		std::cout << "D()\n";
	};

	~D() {
		std::cout << "~D()\n";
	};

	int d;
};

int main() {
	A a;
	std::cout << std::endl;

	B b;
	std::cout << std::endl;

	C c;
	std::cout << std::endl;

	D d;
	//d.a;
	//d.print();
	std::cout << std::endl;
}

//class A {
//public:
//	A() : a(1) {}
//
//	A(const A& other) : a(other.a) {}
//
//	A& operator=(const A& other) {
//		std::cout << "operator= A\n";
//		if (this != &other)
//			a = other.a;
//
//		return *this;
//	}
//
//	~A() {}
//
//	int a;
//};
//
//class B : virtual public A {
//public:
//	B() : A(), b(2) {};
//
//	B(const B& other) : A(other), b(other.b) {};
//
//	B& operator=(const B& other) {
//		std::cout << "operator= B\n";
//		if (this != &other) {
//			A::operator=(other);
//			b = other.b;
//		}
//		return *this;
//	};
//	
//	~B() {};
//
//	int b;
//};
//
//class C : virtual public A {
//public:
//	C() : A(), c(3) {};
//
//	C(const C& other) : A(other), c(other.c) {};
//
//	C& operator=(const C& other) {
//		std::cout << "operator= C\n";
//		if (this != &other) {
//			A::operator=(other);
//			c = other.c;
//		}
//		return *this;
//	};
//
//	~C() {};
//
//	int c;
//};
//
//class D : public B, public C {
//public:
//	D() : B(), C(), d(4) {};
//
//	D(const D& other) : B(other), C(other), d(other.d) {}; // Add A(other)
//
//	D& operator=(const D& other) {
//		std::cout << "operator= D\n";
//		if (this != &other) {
//			B::operator=(other);
//			C::operator=(other);
//			d = other.d;
//		}
//		return *this;
//	};
//
//	~D() {};
//
//	int d;
//};
//
//int main() {
//
//	D d1;
//	d1.d = 24;
//
//	D d2;
//	d2.d = 31;
//
//	d2 = d1;
//
//	std::cout << d2.d;
//
//	return 0;
//}