# templates
**На български казваме шаблони на това, понякога и на design patterns, но не са едно и също! За templates може да си мислим като за универсални функции/класове.**

## Шаблони на фунцкии

```c++
void print(int value) {
    std::cout << value;
}

void print(const char* value) {
    std::cout << value;
}

void print(const Animal& value) {
    std::cout << value;
}

int main() {
    print(5);
    print("Hello world!");
    print(Animal("Tera", 2));

    return 0;
}

```
Компилаторът генерира код за нас, според някакви предварителни правила, които сме задали (шаблона).

```c++
template<typename T> // може и <class T>, в съвременния C++ няма съществена разлика
void print(const T& value) {
    std::cout << value;
}

int main() {  
    // Тук всички функции пак работят, но не сме ги писали ние, а компилатора.
    print<int>(5); 
    print("Hello world!"); 
    print(Animal("Tera", 2)); 

    return 0;
}
```
- При извикването на функцията `print` за даден тип, компилаторът генерира кода на функцията за подадения тип.  

- Ако типът може да се разпознае според аргумента, може да се вика `print(5)`, вместо `print<int>(5)`.  

- Ако не викаме функцията, кодът не се компилира с останалата част от програмата; ако има грешки в него, компилаторът няма да се оплаче _(MSVC)_.   

- Ако имаме вече дефинирана функцията за някой тип, тази дефиниция е с приоритет пред шаблона:  
    ```c++
    void print(int value) { 
        std::cout << "This is an int: " << value; 
    }

    void print(T value) {
        std::cout << value;
    }

    int main() {

        print(5); // Тук ще се извика горната функция
    }
    ```

- Хубаво е да пишем `void print(const T& value)`, вместо `void print(T value)`, защото не знаем предварително какво ще ни се подаде и нямаме гаранция, че ще са само прости типове. 

- Може да има повече от един параметризиран тип:    
    ```c++
    template <typename T, typename U>
    void print(T obj1, U obj2){
        std::cout << obj1 << " " << obj2;
    }
    ```

- Може да има стойност по подразбиране за типа: 
    ```c++
    template <typename T, typename U = int>
    void print(T obj1, U obj2){ 
        std::cout << obj1 << " " << obj2;
    }

    int main(){
        print<char, double>('a', 2.1);
        print<double>(2.1, 1); // <double, int> 

        return 0;
    }
    ```

- Може да има и нетипови параметри:     
    ```c++ 
    template <const size_t SIZE> //why const
    class Array {
    public:
        const size_t get_size() const {
            return SIZE:
        }
    private:
        int data[SIZE];
    }

    // По време на компилацията, ще се създаде клас с фиксиран размер на масива, който сме подали като аргумент
    Array<10> arr;
    ```

## Шаблони на класове
- Ако използваме някой метод, той ще се генерира, а каквото не използваме, най-вероятно няма: [може да проверим какъв код се генрира](https://cppinsights.io/)

### Проблеми при разделянето на декларации от дефиниции
Следния код ще води до linker errors: 
```c++
// Array.h
template <typename T>
class Array {
public:
	Array();
	~Array();

	void add(const T& element);
	void print();

private:
	T* arr;
	size_t size;
};
```
```c++
// Array.cpp
#include <iostream>
#include "Array.h"

const size_t MAX_SIZE = 10;

template <typename T>
Array<T>::Array() {
	arr = new T[MAX_SIZE];
	size = 0;
}

template <typename T>
Array<T>::~Array() {
	delete[] arr;
}

template <typename T>
void Array<T>::add(const T& element) {
	if (size >= MAX_SIZE)
		return;

	arr[size] = element;
	size++;
}

template <typename T>
void Array<T>::print() {
	for (int i = 0; i < size; ++i)
		std::cout << arr[i] << ' ';

	std::cout << std::endl;
}
```
```c++
// main.cpp
int main() {
    Array<int> arr;
    arr.print();
    return 0;
}
```
- решение: всичко се пише в .h
- решение: използва се .inc файл, вместо .cpp

# Задачи
### Task 1
Да се реализира универсален/темплейтен клас [`Queue`](https://www.geeksforgeeks.org/queue-data-structure/).

### Task 2
Да се реализира клас `Ticket`, представящ билет за театрално представление.
Билетът съдържа информация за името на представлението и цена.
Всеки нормален билет важи за един зрител.

Съществува още билет с намаление за студенти и пенсионери,
чиято цена е 50% от цената на нормалния. Той е поименен и при закупуване трябва
да се предостави подходящ документ.

Съществува и групов билет, който важи най-малко за 20 човека
и цената му се намалява с 2 лева за всеки човек.

За всеки вид билет да се напише метод `print`, който извежда информация за
билета.

В `main` създайте опашка от билети и изведете информацията за всеки билет, според реда им на пристигане.


