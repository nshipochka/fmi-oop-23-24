# static
В C++ има три случая, в които може да се използва `static`:

- Къде живеят статичнте данни?

- Статични променливи във функция:
    - променливата се създава веднъж и съществува до края на програмата
    - ако се вика многократно функцията, променливата помни стойността от предното извикване  
    ```c++
    void printSum(int n){
        static int sum = 0; //променливата се инициализира само при първото извикване на фунцкията
        sum += n;

        std::cout << sum << '\n';
    }

    int main(){
        printSum(5); // 5
        printSum(4); // 9
        printSum(1); // 10

        return 0;
    }
    ```
- Статични член-данни: 
    - инициализират се само веднъж и са общи за всеки обект от този тип, т.е. принадлежи на класа като цяло, а не на конкретния обект. 
    ```c++
    class Object{
    public: 
        Object(){
            s = 16; // Тук не я дефинираме, а се сменя стойността на съществуваща променлива
        }
    private: 
        static int s; // Тук само я декларирамене. Тук не можем да я дефинираме, ако не е константна.
    };

    int Object::count = 0; // Тук се дефинира

    int main(){
        std::cout << Object::s; // 0 

        Object first;
        std::cout << first.s; //16

        Object second;
        std::cout << second.s;  // 16
        std::cout << first.s;   // 16
        std::cout << Object::s; // 16   
    }
    ```

- Статични методи: 
    - общи за класа и не се отнасят за конкретни различни обекти
    - в тях няма указателя `this`
    - не могат да са const: `static void get() const { ... }`
    - могат да достъпват само статични член-данни или други статични методи от класа
    ```c++
    class Object{
    public:
        //...
        static void print_s(){
            std::cout << s;
            std::cout << n; // Не може да я ползва, защото не е статична променлива. 
        }
    private:
        static int s;
        int n;
    };

    int main(){
        Object first;

        first.print_s(); // Може, но не е добра практика
        Object::print_s(); // ДА
    }
    ```

# enum
`Enum` и `enum class` са типове данни, които позволяват дефинирането на изброим тип (enumeration). Те се използват за дефиниране на константни множества от стойности.

## enum (просто изброим тип)
```cpp
enum Color {
    RED, //0
    GREEN, //1
    BLUE //2
};

Color c1 = RED;
Color c2 = Color::GREEN;

std::cout << c2; // 1
```
- Enum е тип данни, който дефинира набор от именовани константи.
- По подразбиране стойностите на елементите в enum се започват от 0 и нарастват с единица за всеки следващ елемент.
- Може да се преобразува до int.

### Задаване на стойности
```cpp
enum Color {
    RED = 5, //5
    GREEN, //6
    BLUE = 2, // 2
    YELLOW // 3
}
```
### Цикъл по стойностите на enum
```cpp
enum Color {
    INVALID = -1,
    RED, //0
    GREEN, //1
    BLUE, // 2
    COUNT //3
}
```
```cpp
const char* color_names[] = {"red", "green", "blue"};

for (Color c = (Color)0; c < COUNT; c = (Color)(c + 1)) {
    std::cout << color_names[c] << std::endl;
}
```

## enum class
```cpp
enum class Status {
    OK,
    ERROR
};

Status s1 = OK; // OK не е видимо в цялата област -> проблем
Status s2 = Status::OK;

std::cout << Color::BLUE; // Не може имплицитно да кастне към нещо, за което има дефиниран operator<<
std::cout << (int)Color::BLUE;
```
Enum class е подобен на обикновения enum, но с някои особености:
- Всички елементи на enum class са скрити в областта на този тип, което предотвратява конфликти и замъгляване на имената.
- Стойностите на елементите трябва явно да бъдат декларирани.
- Не допуска автоматично преобразуване към int и други типове.
- При enum class трябва да се използва спецификаторът на типа `Status::OK`, за да се достъпи константата.

### Цикъл по стойностите на enum class
```cpp
for (Color c = (Color)0; c <= Color::BLUE; c = (Color)((int)c + 1)) {
        std::cout << color_names[(int)c] << std::endl;
    }
```

# move семантики (преговор)
[lvalues & rvalues](https://github.com/nshipochka/fmi-oop-23-24/tree/main/05-more-examples)