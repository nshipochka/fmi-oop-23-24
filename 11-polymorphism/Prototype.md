## Prototype Design Pattern
Как да се добавя в хетерогенни контейнери?

```c++
class Container{
public:
    //...
    void add(Base* element);
private: 
    Base** container;
    //...
}
```
За да добавим и да запазим типа, който подаваме, трябва да добавяме по указател:
```c++
Container c;
Derived obj;

c.add(&obj);
```
Следната реализация за `add` ще ни позволи това, но има проблем с паметта:
```c++
void Container::add(Base* element){
    //...
    container[size] = element;
    size++;
}
```
Проблемът с горния код идва когато някой промени или изтрие обекта отвън, защото ние сме присвоили в контейнера само адреса му, т.е. имаме плитко копие и нашите данни не са защитени.

```c++
//Тогава нека го копираме?
void Container::add(Base* element){
    //...
    container[size] = new Base(*element); // Тук не знаем element oт какъв тип е и не можем да 
    size++;                               // създадем друго освен обект от тип Base,
                                          // aко изобщо е възможно (класът не е абстрактен).
}
```
Тук имаме нов проблем - взима се само `Base` частта от `element`, който може да е всякакъв друг клас-наследник, и се присвоява само тя в нов обект, който си е от тип `Base`. 

Решението е метод `clone()`.    
Класове, които позволяват клониране се наричат _прототипи_.

```c++
class Base{
public:
//...
    virtual Base* clone() = 0; // Първо се деифнира чисто виртуално в базовия
}

class Derived: public Base{
public:
//...
    virtual Base* clone() override { // предефинира се фунцкията, така че
        return new Derived(*this);  // да връща указател от тип Base, сочещ към нов динамично заделен
    }                               // обект, който е копие на текущия

    // тук вече знаем точно от какъв тип е обекта и можем да използваме съответния констуктор, а не този на Base
}

class OtherDerived: public Base{
public:
//...
    virtual Base* clone() override {     // предефинира се фунцкията, така че
        return new OtherDerived(*this);  // да връща указател от тип Base към нов динамично заделен
    }                                    // обект oт тип класа наследник
}
```
В такъв случай `add` ще се имплементира така:
```c++
void Container::add(Base* element) {
    //...
    container[size] = element->clone();
    size++;
}
```
Така добавяме обект, който копира подадените данни изцяло, независимо какъв тип се крие зад указаделя по време на изпълнението на програмата и продължаваме да поддържаме полиморфната функционалност.

_Забележка:_ Когато добавяме по този начин, не трябва да забравяме да изтрием всички обекти, които сме създали в деструктора!