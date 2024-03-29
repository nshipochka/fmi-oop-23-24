# Classes 
Разлика със структури:
- видимост: в class по подразбиране всичко е private, в struct - public
- идея: struct е съвкупност от данни, class си го представяме като някакви смислено свързани неща

[Кое кога да използваме?](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#c2-use-class-if-the-class-has-an-invariant-use-struct-if-the-data-members-can-vary-independently)
- Като нещо ще е публично и с малко методи/ако може данните да варират независимо -> структура
- Ако очакваме някакво коректно състояние на обекта като цяло, за да можем да работим с него -> клас

## Спецификатори за достъп
### public 
Членовете могат да се виждат и достъпват извън класа
### private
Членовете **не** могат да се виждат и достъпват извън класа
### protected
Членовете **не** могат да се виждат извън класа, освен от наследяващи го класове


## Конструктори и деструктор
- Могат да се генерират сами 
- Викат се по време на създаване на обекта
- Полезни са за инициализация на обекта и неговите данни
- Могат да се overload-ват (важно е да имат различни аргументи, за да могат да се различават)
- Конструкторът по подразбиране няма да се генерира от компилатора, ако експлицитно сме написали друг конструктор

### Default Constructor
```c++
class Player {
public:
    Player() {
        health = 100;
        xp = 0;
    }

    Player(int health) {
        this->health = health;
        xp = 0;
    }

    Player(int health, int xp) {
        this->health = health;
        this->xp = xp;    
    }

    // Player(int health = 0, int xp = 0); - Този замества и трите
    // Не би заместил Player(int xp) { ... }

private:
    int health;
    int xp;
};
```

### Инициализиращ списък   
В горните примери създаваме обекта, т.е. инициализират се член данните и тогава им просвояваме нови стойности в тялото на конструктора.     

С инициализиращите списъци казваме какви да са стойностите на данните преди да се изпълни тялото на конструктора, като данните се инициализират в реда, в който са декларирани в класа, а не реда, в който са написани в списъка.   

Това е начинът да даваме стойности на константни член-данни.    

```c++
Player() : health(0), xp(0) {}
Player(int health) : health(health), xp(xp) {}
Player(int xp) : health(0), xp(0) {}
Player(int health, int xp) : health(health), xp(xp) {}
```

### Преизползване на конструктори     
```c++
Player(int health, int xp) : health(health), xp(xp) {}
Player(int health) : Player(health, 0) {}
Player(int xp) : Player(0, xp) {}
Player() : Player(0, 0) {}
```

### Copy Constructor
Когато искаме да създадем обект, копие на вече съществуващ, се вика копиращ конструктор.    

Имаме нужда от копие, когато:
- Подаваме обект по стойност като параметър
- Функция връща обект по стойност

Също се генерира автоматично от компилатора, ако не сме го написали експлицитно

```c++
Player(const Player& other) : health(other.health), xp(other.xp) {}

//...

int main() {
    Player p;

    // И двете използват copy constructor
    Player p_copy(p);
    Player p_copy = p;
}
```

### Деструктор
- Генерира се сам, ако не сме го декларирали
- Само един е

```c++
~Player() {
    // Ако имаме някаква динамично заделена памет
    delete data;
    delete[] data;
}
```
```c++
int main() {
    Player* p = new Player;
    delete p; // Тук се вика деструктора на Player за p
}
```

## Вложени обекти
```c++
class Point {
public:
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    ~Point() {}

private:
    double x;
    double y;
};

class Circle {
public:
    // Не може Circle(double x, double y, double radius) : x(x), y(y), radius(radius) {}
    Circle(double x, double y, double radius) : center(x, y), radius(radius) {} // За center се вика конструктора на Point
    ~Circle() {} // Когато обект от тип Circle се разрушава, автоматично се вика деструктора на Point, който да разруши center

private:
    Point center;
    double radius;
}
```

## При член-данни с динамично заделена памет 
### Shallow Copy
```c++
class Shallow {
public:
    Shallow(int d); // default contructor
    Shallow(const Shallow& source); // copy contstructor
    ~Shallow(); //destructor
private:
    int* data; 
};

Shallow::Shallow(int d) {
    data = new int; // При създаването на обекта, трябва да заделим паметта
    *data = d;
};

Shallow::~Shallow() {
    delete data;
};

Shallow::Shallow(const Shallow& source) : data{ source.data } {};

void f(Shallow s) {
    //...
    // В края на блока се вика деструктора на s и освобождава паметта на мястото, което data сочи
}

int main() {
    Shallow obj1(100);
    Shallow obj2(obj1);
    // Тук и data и на двата обекта сочи една и съща заделена памет 
    // Ако се опитаме да променим *data в единия, ще променим стойността и за другия

    f(obj1); 
    // Тук вече data на obj1 и obj2 сочат към изтрита памет

    return 0;
    // В края на блока, когато се викат деструкторите, ще се опитаме да трием една и съща памет два пъти
}
```

### Deep Copy
```c++
class Deep {
public:
    Deep(int d);
    Deep(const Deep& other); 
    ~Deep();

private:
    int* data;
};

Deep::Deep(int d) {
    data = new int;
    *data = d;
}

Deep::~Deep() {
    delete data;
}

Deep::Deep(const Deep& other) {
    data = new int; // Заделяме си нова памет
    *data = *other.data; // Присвояваме ѝ стойността на данната на копирания обект
}
// С преизползване на първия конструктор: 
Deep::Deep(const Deep& other) : Deep(*other.data) {}

void f(Deep d) {
    //...
    // Тук се вика деструктора на d, но тъй като е дълбоко копие, освобождава само неговата си памет.
}

int main() {
    Deep obj1(100);
    Deep obj2(obj1);
    // Тук указателите от двата обекта сочат на различни места в heap-a
    // Можем да променяме стойностите независимо
    // Края на живота на единия обект, не се отразява на променливата на другия

    f(obj1);
    // Тук и obj1, и obj2 са във валидно състояние и викането на функция с някой от тях като аргумент, подаден по стойност, не им се отразява

    return 0;
    // В края на блока се викат деструкторите на obj1 и на obj2 и няма проблем, защото нямат споделена памет
}
```
### =delete
"Забранява" съответния метод, т.е. не може да се дефинира, не може да се ползва. Ако искаме например експлицитно да забраним копирането на обекти от някакъв тип, ще забраним копиращия конструктор.    

Може всякакви методи да се забраняват.

```c++
class Player {
    Player() = delete;
    ~Player() = delete;
    Player(const Player&) = delete; 
}
```
### =default
Експлицитно казва, че се иска по подразбиране

### Rule of 0
Ако класът не се занимава директно със собствеността на някакви данни (т.е. заделяне на памет), значи няма нужда да пишем експлицитно конструктор/деструктор/оператор за присвояване, те ще се генерират и ще вършат коректна работа.

### Rule of 3
Ако в класа сме дефинирали/забранили експлицитно някое от:
- Destructor
- Copy Constructor
- Assignment Operator (ще го видим по-нататък)

Значи вероятно трябва да дефнириаме/забраним и трите за да гарантираме **correctness**.

## Селектори и мутатори (getters & setters)
```c++
class Player {
    // Ctors & Dtor
    // ...

    // Setters
    void setName(char* name) {
        delete[] this->name; // Подсигуряваме се, че няма да ни изтече памет
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    void setXp(int xp) {
        this->xp = xp;
    }

    // Getters
    const char* getName() const {
        return name;
    }

    int getXp() const {
        return xp;
    }

private:
    char* name;
    int xp;
};
```
# Задачи
Да се напишат следните класове

### Employee
Работниците имат следните атрибути:
- Име с не повече от 50 символа
- Възраст 
- Месечна заплата 
- Съответните конструктори, деструктор, селектори и мутатори
- Метод за извеждане на пълната информация за служител

### Company
Фирмата има следните атрибути:
- До 1000 служителя
- Съответните конструктори, деструктор, селектори и мутатори
- Метод, който проверява дали фирмата е празна (без служители)
- Метод, който добавя служител към фирмата
- Метод, който уволнява служител по дадено име (първия срещнат такъв) и връща false, ако такъв не съществува
- Метод, който сортира служителите по име
- Метод, който пресмята общо колко пари се плащат за заплати на месец
- Метод, който увеличава заплатата на даден служител (по име, първия срещнат такъв) с даден процент
- Метод, който извежда информация за всичките служители