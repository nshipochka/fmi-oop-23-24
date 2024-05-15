Ако искаме да имаме приятелска функция в темплейтен клас, ако функцията сама по себе си е темплейтна, трябва да я напишем така:  
```c++
template<typename T>
class Test {
public:
	template<typename U>
	friend void print(const Test<U>& t);
	T data;
};

template<typename T>
void print(const Test<T>& t) {
	std::cout << t.data;
}
```

Ако само класът е темплейтен, а функцията е дефинирана за конкретен тип:  
```c++
template<typename T>
class Test {
public:
	friend void print(const Test<T>& t);
	T data;
};

void print(const Test<int>& t) { //Дефинирана само за обекти Test<int>
	std::cout << t.data;
}

int main() {
	Test<int> a;
	a.data = 1;

	print(a);

	return 0;
}
```
