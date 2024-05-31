#include <iostream>
template <typename T>
void print(T* arr, size_t arr_size) {
    for (size_t i = 0; i < arr_size; ++i) 
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

// Example 1: 

template <typename T>
void sort(T* arr, size_t arr_size, bool (*compare)(const T&, const T&)) {
    int min_idx;
    for (int i = 0; i < arr_size - 1; i++) {
        min_idx = i;
        for (int j = i + 1; j < arr_size; j++) {
            //if (arr[j] < arr[min_idx]) 
            if(compare(arr[j], arr[min_idx]))
                min_idx = j;
        }

        if (min_idx != i)
            std::swap(arr[min_idx], arr[i]);
    }
}

template <typename T>
bool ascending(const T& a, const T& b) {
    return a < b;
}

template <typename T>
bool descending(const T& a, const T& b) {
    return a > b;
}

int main() {
    int arr[] = { 1, 4, -2, 16, -19, 1, 2, 10, 15, 71, -3 };
    size_t arr_size = sizeof(arr) / sizeof(int);
    print(arr, arr_size);

    sort(arr, arr_size, ascending);
    print(arr, arr_size);

    sort(arr, arr_size, descending);
    print(arr, arr_size);

	return 0;
}

// Example 2: 

template <typename T>
void map(T* arr, size_t arr_size, void (*f)(T&)) {
	for (size_t i = 0; i < arr_size; ++i)
		f(arr[i]);
}

template <typename T>
void increase_by_two(T& element) {
	element += 2;
}

template <typename T>
void increase_by_n(T& element, const T& n) {
	element += n;
}

template <typename T>
void nullify(T& element) {
	element = 0;
}

//int main() {
//	int arr[] = { 1, 4, -2, 16, -19, 1, 2, 10, 15, 71, -3 };
//	size_t arr_size = sizeof(arr) / sizeof(int);
//	print(arr, arr_size);
//
//	map(arr, arr_size, increase_by_two);
//	print(arr, arr_size);
//	//map(arr, arr_size, increase_by_n); - не може, защото не е правилния брой аргументи
//
//	map(arr, arr_size, nullify);
//	print(arr, arr_size);
//
//	return 0;
//}
