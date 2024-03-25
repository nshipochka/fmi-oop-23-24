#include "Store.h"

Store::Store(size_t capacity)
	:size(0)
	, capacity(capacity) {
	products = new Product * [capacity];
}

Store::Store(const Store& other) {
	copy(other);
}

Store& Store::operator=(const Store& other) {
	if (this != &other) {
		free();
		copy(other);
	}
	return *this;
}

Store::~Store() {
	free();
}

bool Store::addProduct(const Product& product_to_add) {
	if (size >= capacity)
		return false; // Няма място в магазина и не можем да добавяме нови стоки

	products[size++] = new Product(product_to_add);
	// Тук се заделя памет за един нов обект от тип Product, към който ще сочи указателят на място size в масива.
	// Обектът се създава с копи конструктор, копирайки данните на product_to_add.
	return true;
}

bool Store::addProduct(const char* name, const char* brand, double price, unsigned quantity) {
	if (size >= capacity)
		return false; // Няма място в магазина и не можем да добавяме нови стоки

	products[size++] = new Product(name, brand, price, quantity);
	// Тук се заделя памет за един нов обект от тип Product, към който ще сочи указателят на място size в масива.
	// Обектът се създава с конструктора с аргументи.
	return true;
}

bool Store::changeQuantity(const char* name, const char* brand, unsigned new_quantity) {
	int index = find(name, brand);
	if (index < 0) return false;

	products[index]->setQuantity(new_quantity);
	return true;
}

bool Store::buy(const char* name, const char* brand) {
	int index = find(name, brand);
	if (index < 0) return false;

	std::cout << "You just bought ";
	products[index]->print();

	// Като се купи нещо, трябва да намалим наличното количество и ако стане 0,
	// да го премахнем от предлаганите стоки в магазина
	// Алтернативно, може да си седи и просто про купуване да проверавяме дали количеството е >0 и може да се купи
	unsigned quantity = products[index]->getQuantity();
	quantity--;

	if (quantity == 0)
		removeProduct(index);
	else
		products[index]->setQuantity(quantity);

	return true;
}

void Store::printAvailableProducts() const {
	std::cout << "Available products: " << std::endl;
	// Ако сме ползвали алтернативния метод за купуване, тук принтваме само тези, чието quantity > 0
	for (size_t i = 0; i < size; ++i)
		products[i]->print();
}

void Store::printProductsByBrand(const char* brand) const {
	for (size_t i = 0; i < size; ++i)
		if (!strcmp(products[i]->getBrand(), brand))
			products[i]->print();
}


void Store::copy(const Store& other) {
	size = 0; // Защото addProduct автоматично ни го увеличава
	capacity = other.capacity;
	products = new Product * [capacity];
	for (size_t i = 0; i < other.size; ++i)
		addProduct(*other.products[i]); // преизползваме си вече писан код
}

void Store::free() {
	for (size_t i = 0; i < size; ++i)
		delete products[i];

	delete[] products;
}

int Store::find(const char* name, const char* brand) const {
	for (size_t i = 0; i < size; ++i) {
		if (!strcmp(name, products[i]->getName())
			&& !strcmp(brand, products[i]->getBrand()))
			return i;
	}
	return -1;
}

bool Store::removeProduct(size_t i) {
	if (i > size) return false;

	products[i]->swap(*products[size]);
	delete products[size];
	size--;
	return true;
}
