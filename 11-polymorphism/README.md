# Множествено наследяване
[Пример](examples/multiple_inheritance.cpp)

# Полиморфизъм
- Позволява различни типове обекти да поддържат еднакъв интерфейс, но да имат различно поведение, специфично за тях.
- Видове:
  - `compile-time` / `static-binding`: преди да се изпълни програмата, вече знаем кой метод ще се извика    
    ```c++
    //Пример: overloading
    int print(int a);
    int print(int a, int b);

    //...
    print(5);
    print(5, 6);
    // По време на компилация очевидно знаем кой от двата метода сме извикали
    ```
  - `run-time` / `dynamic-binding`: по време на изпълнение се определя кой метод ще се изпълни. Постига се с виртуални функции.
   
    
    - Ако нямаме динамичен полиморфизъм   
        ```cpp
        Base b;
        b.withdraw(); // Base::withdraw()                
                                                                    
        Derived d;                                                       
        d.withdraw(1000); // Derived::withdraw()      

        Base* p = new Derived();
        p->withdraw(1000); // Base::withdraw(), а би ни се искало да е Derived::withdraw()
        ```
    - Ако имаме динамичен полиморфизъм    
        ```cpp
        Base b;
        b.withdraw(); // Base::withdraw()                
                                                                    
        Derived d;                                                       
        d.withdraw(1000); // Derived::withdraw()      

        Base* p = new Derived();
        p->withdraw(1000); // Derived::withdraw(), НО ТРЯБВА withdraw ДА Е ВИРТУАЛЕН!              
        ```
## Виртуални функции (виртуалната таблица да нарисувам)
- Виртуалните функции не се `overload`-ват, a се `override`-ват
- Overriden functions се свързват **динамично** 
- Позволяват ни да третираме различни обекти от наследени типове като обекти от родителския тип
- [Виртуална таблица](https://www.learncpp.com/cpp-tutorial/the-virtual-table/)

### Деклариране на виртуални функции
```cpp
class Base{
public:
    virtual void withdraw(double amount);
};
```
- Декларираме функцията като `virtual` в основния клас
- От този момент тази функция става виртуална във всички класове наследници
- Ще се свърже динамично, когато използваме указател или псевдоним към базовия клас


### Override на метода в наследниците
```cpp
class Derived : public Base{
public:
    virtual void withdraw(double amount);
};
```
- **сигнатурата** и **връщания тип** трябва да са еднакви с тези на функцията в родителския клас
- думата `virtual` в наследниците не е задължителна, но е добра праткика да я пишем
- ако няма предоставена `override`-ната версия в наследника, функцията се наследява от родителския клас

### Виртуални деструктори (ВАЖНО!)
- За да могат правилно да се разрушават полиморфни обекти, трябва деструкторите да са виртуални   
    ```c++
    virtual ~Base() { 
        delete //...
    }
    ```
- Ако нямаме динамични данни в базовия клас, пак трябва да напишем деструктора, ако искаме да е виртуален. _(Дефолтно генериран деструктор няма да е виртуален, освен ако не е за клас, който наследява родител с виртуален деструктор)_   
    ```c++
    virtual ~Base() {}
    ```
- Ако се изтрие обект от тип `Derived` през указател към него от тип `Base` и деструкторите не са виртуални, това е недефинирано поведение  
    ```c++
    //Base
    ~Base() { 
        delete //...
    }

    // Derived
    ~Derived() {
        delete //...
    }
    
    // main
    Base* b = new Derived();
    delete b; // Тук ще има проблем
    ```

### override спецификатор
```cpp
class Base {
public:
	virtual void print() const {
		std::cout << "Base: print\n";
	}

	virtual ~Base();
};
```
```c++
class Derived : public Base {
public:
	virtual void print() {              // Тук сме "изпуснали" const - значи не е overriding, а предефиниране
		std::cout << "Derived: print\n"; // значи ще имаме static binding (и недефинирано поведение като използваме указател към тип Base)
	}

	virtual ~Derived();
};							
```
Спецификаторът `override` гарантира, че компилаторът ще се оплаче и ще си спестим такива грешки
```c++
class Derived : public Base {
public:
	virtual void print() const override {  // Ако тук изпуснем const, компилаторът ще каже, че не override-ваме
		std::cout << "Derived: print\n";   
	}

	virtual ~Derived();
};
```
### final спецификатор
```cpp
class MyClass final {	// final казва, че MyClass не може да се наследява
	//...
};

class Derived : public MyClass {}; // Не може
```
```cpp
class A {
public:
	virtual void foo();
};

class B : public A {
	virtual void foo() final;	// final казва, че в наследниците на B, foo() не може да се override-ва
};

class C : public B {
	virtual void foo();	// compiler error - "cannot override 'final' function B::foo"     
};  
```

## Абстрактни класове (интерфейси)
- Не могат да се създават обекти от такъв тип
- Често базовите класове в някаква йерархия са такива
- Обикновено представляват някакво общо понятие - `Shape`, `Animal`, a наследниците са по-конкретни - `Square`, `Circle` или `Dog`, `Cat`, etc.
- Трябва да съдържа поне една чисто виртуална функция

### pure virtual functions
- Прави абстрактни класовете, в които се използва
- Указва се с `= 0` след декларацията
  - `virtual void function() = 0;` -> pure virtual function
- Обикновено не пишем имплементация (но е позволено да има такава)
- Когато наследяваме абстрактен клас **ТРЯБВА да override-нем** чисто виртуалната функция, иначе наследникът също ще е абстрактен
- Използват се, когато някаква функционалност няма смисъл в базовия клас

## Интерфейс
- Абстрактен клас който има **само** чисто виртуални методи
- Всеки метод трябва да се имплементира в наследника
- Всеки наследник е свободен да ги имплементира както е удобно

```cpp
//                                    EXAMPLE
//We want to create intefece I_Printable in which we will define a print function

#include <iostream>

class I_Printable {
	friend std::ostream& operator<<(std::ostream& os, const I_Printable& obj);
public:
	virtual void print(std::ostream& os) const = 0;
};

std::ostream& operator<<(std::ostream& os, const I_Printable& obj) {
	obj.print(os);
	return os;
}

class Account : public I_Printable {
public:
	virtual void withdraw(double amount) {
		std::cout << "Account::withdraw\n";
	}
	virtual void print(std::ostream& os) const override {
		os << "Account print";
	}
	virtual ~Account() { std::cout << "Account::destructor\n"; }
};

class CheckingAccount : public Account {
public:
	virtual void withdraw(double amount) {
		std::cout << "CheckingAccount::withdraw\n";
	}
	virtual void print(std::ostream& os) const override {
		os << "CheckingAccount print";
	}
	virtual ~CheckingAccount() { std::cout << "CheckingAccount::destructor\n"; }
};

class SavingsAccount : public Account {	
public:
	virtual void withdraw(double amount) {
		std::cout << "SavingsAccount::withdraw\n";
	}
	virtual void print(std::ostream& os) const override {
		os << "SavingsAccount print";
	}
	virtual ~SavingsAccount() { std::cout << "SavingsAccount::destructor\n"; }
};

class TrustAccount : public Account {
public:
	virtual void withdraw(double amount) {
		std::cout << "TrustAccount::withdraw\n";
	}
	virtual void print(std::ostream& os) const override {
		os << "TrustAccount print";
	}
	virtual ~TrustAccount() { std::cout << "TrustAccount::destructor\n"; }
};

//The good point is we can do:
class Dog : public I_Printable {
public:
	virtual void print(std::ostream& os) const override {
		os << "Woof wooof";
	}
};

void print(const I_Printable& obj) {
	std::cout << obj << std::endl;
}

int main()
{
	Dog* dog = new Dog();
	print(*dog);

	Account* p1 = new Account();
	std::cout << *p1 << std::endl;

	Account* p2 = new CheckingAccount();
	std::cout << *p2 << std::endl;

	delete dog;
	delete p1;
	delete p2;
}
```