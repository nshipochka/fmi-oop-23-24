//#include<iostream>
//
//class Object {
//public:
//	Object() : n(0) {}
//	
//	void set_n(int _n) { n = _n; }
//	int get_n() const { return n; }
//
//	void set_shared(int _shared) { shared = _shared; }
//	int get_shared() const { return shared; }
//
//	static void set_shared_s(int _shared) { shared = _shared; /*n = _shared;*/ }
//	static int get_shared_s() /*const*/ { return shared; }
//
//private:
//	int n; // instance variable
//	static int shared; // тук ДЕКЛАРИРАМЕ статичната променлива
//};
//
//// тук даваме ДЕФИНИЦИЯ (както правим с методите)
//int Object::shared = 0; // начална стойност
//
////int main() {
////	Object o1, o2; 
////	std::cout << "n:      " << o1.get_n() << " " << o2.get_n() << std::endl;
////	std::cout << "shared: " << o1.get_shared() << " " << o2.get_shared() << std::endl;
////	std::cout << "---\n";
////
////	o1.set_n(4);
////	o1.set_shared(4);
////	std::cout << "n:      " << o1.get_n() << " " << o2.get_n() << std::endl;
////	std::cout << "shared: " << o1.get_shared() << " " << o2.get_shared() << std::endl;
////	std::cout << "---\n";
////
////	o2.set_n(2);
////	o2.set_shared(2);
////	std::cout << "n:      " << o1.get_n() << " " << o2.get_n() << std::endl;
////	std::cout << "shared: " << o1.get_shared() << " " << o2.get_shared() << std::endl;
////	std::cout << "---\n";
////
////	Object::set_shared_s(1);
////	//std::cout << Object::get_n() << std::endl; // Това не можем да го правим
////	//std::cout << Object::get_shared() << std::endl; // Това не можем да го правим 
////	std::cout << Object::get_shared_s() << std::endl;
////
////	return 0;
////}
//
//template <typename T>
//class Calculator {
//public:
//	static T add(const T& a, const T& b) { return a + b; }
//	static T substract(const T& a, const T& b) { return a - b; }
//	static T multiply(const T& a, const T& b) { return a * b; }
//	static T divide(const T& a, const T& b) { return a / b; }
//};
//
//int main() {
//	std::cout << Calculator<int>::add(1, 3) << std::endl;
//	std::cout << Calculator<double>::divide(1, 3) << std::endl;
//};

#include <iostream>
enum Color {
    INVALID = -1,
    RED = 0, //0
    GREEN = 0, //1
    BLUE = 2, // 2
    COUNT //3
};

//const int RED = 5;

int main() {

    //const char* color_names[] = { "red", "green", "blue" };

    for (Color c = (Color)0; c < COUNT; c = (Color)(c + 1)) {
        std::cout << c << std::endl;
    }
    
    RED;

    return 0;
}