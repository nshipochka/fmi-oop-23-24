#include <iostream>

class Base {
private:
	char* base_str;

public:
	Base();
	Base(const char* str);
	Base(const Base& other);
	Base& operator=(const Base& other);
	~Base();

    Base(Base&& other);
    Base& operator=(Base&& other);

    void print() const;
    void print_newline() const;
};

class Derived : public Base {
private:
	char* derived_str;

public:
	Derived();
	Derived(const char* base_str, const char* derived_str);
	Derived(const Derived& other);
	Derived& operator=(const Derived& rhs);
	~Derived();

    Derived(Derived&& other);
    Derived& operator=(Derived&& other);

    void print() const;
};

// Constructors
Base::Base() 
    : base_str(nullptr) 
{
    std::cout << "Base: default constructor\n";
}

Base::Base(const char* str) 
{ 
    if(!str) base_str = nullptr;
    else{
        base_str = new char[strlen(str) + 1];
        strcpy_s(base_str, strlen(str) + 1, str);
    }
    std::cout << "Base: constructor w/ arguments\n";
}

Base::Base(const Base& other)
    : Base(other.base_str)
{
    std::cout << "Base: copy constructor\n";
}

Derived::Derived() 
    : Base(), // Трябва да викнем конструктор на Base - избираме дефолтния, защото и тук пишем дефолтен конструктор
    derived_str(nullptr)
{
    std::cout << "Derived: default constructor\n";
}

Derived::Derived(const char* base_str, const char* derived_str) 
    : Base(base_str) // Трябва да викнем конструктор на Base - избираме си този с аргумент
{
    if(!derived_str) this->derived_str = nullptr;
    else{
        this->derived_str = new char[strlen(derived_str) + 1];
        strcpy_s( this->derived_str, strlen(derived_str) + 1, derived_str);
    }

    std::cout << "Derived: constructor w/ arguments\n";
} 

Derived::Derived(const Derived& other) 
    : Base(other) // Трябва да викнем конструктор на Base - избираме копи конструктора 
{
    if(!other.derived_str) derived_str = nullptr;
    else{
        derived_str = new char[strlen(other.derived_str) + 1];
        strcpy_s(derived_str, strlen(other.derived_str) + 1, other.derived_str);
    }

    std::cout << "Base: copy constructor\n";
}

// Destructors
Base::~Base() {
    delete[] base_str;
    std::cout << "Base: destructor\n";
}

Derived::~Derived() {
    delete[] derived_str;
    std::cout << "Derived: destructor\n";
}

// Operator=
Base& Base::operator=(const Base& other) {
	if (this != &other) {
		if(!other.base_str) base_str = nullptr;
        else{
            base_str = new char[strlen(other.base_str) + 1];
            strcpy_s(base_str, strlen(other.base_str) + 1, other.base_str);
        }
	}

    std::cout << "Base: operator=\n";
	return *this;
}

Derived& Derived::operator=(const Derived& other) {
	if (this != &other) {

        Base::operator=(other); // Трябва експлицитно да викнем оператор= на родителя

		if(!other.derived_str) derived_str = nullptr;
        else{
            derived_str = new char[strlen(other.derived_str) + 1];
            strcpy_s(derived_str, strlen(other.derived_str) + 1, other.derived_str);
        }
	}

    std::cout << "Derived: operator=\n";
	return *this;
}

// move semantics

Base::Base(Base&& other) {
    base_str = other.base_str;
    other.base_str = nullptr;
    std::cout << "Base: move copy constructor\n";
}

Base& Base::operator=(Base&& other) {
    if(this != &other) {
        delete[] base_str;
        base_str = other.base_str;
        other.base_str = nullptr;
    }

    std::cout << "Base: move operator=\n";
    return *this;
}

Derived::Derived(Derived&& other) 
    : Base(std::move(other)) 
{
    derived_str = other.derived_str;
    other.derived_str = nullptr;
    std::cout << "Derived: move copy constructor\n";
}

Derived& Derived::operator=(Derived&& other) {
    if(this != &other) {
        Base::operator=(std::move(other));

        delete[] derived_str;
        derived_str = other.derived_str;
        other.derived_str = nullptr;
    }

    std::cout << "Derived: move operator=\n";
    return *this;
}

// Overriding

void Base::print() const {
    std::cout << "Base: " << base_str;
}

void Base::print_newline() const {
    std::cout << std::endl;
}

void Derived::print() const {
    Base::print(); 
    print_newline(); 
    std::cout << "Derived: " << derived_str;
}

int main() {
    Base b("Hello"); 
    b.print(); // Вика Base::print() -> "Base: Hello"

    Derived d("Hello", "World");
    d.print(); // Вика Derived::print() -> "Base: Hello
                //                          Derived: World"

    d.Base::print(); // Вика Base::print() -> "Base: Hello"

    Base* ptr = new Derived("Hello", "World");
    ptr->print();

    delete[] ptr;
    return 0;
}
