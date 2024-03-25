#ifndef __STORE_HEADER_INCLUDED__
#define __STORE_HEADER_INCLUDED__

#include "Product.h"
#include <cstring>
#include <iostream>

class Store {
public:
	Store(size_t capacity); 
	// Тук можем да се аргументираме, че един магазин има ограничено място и не може по дефолт да го създаваме и после да ресайзваме
	// Може пък и да преценим, че е окей да се ресайзва - могат да си купят повече рафтове и да построят склад
	// Въпрос на преценка или според условието на задачата
	Store(const Store& other);
	Store& operator=(const Store& other);
	~Store();

	bool addProduct(const Product& product_to_add);
	bool addProduct(const char* name, const char* brand, double price, unsigned quantity);
	bool changeQuantity(const char* name, const char* brand, unsigned new_quantity);
	bool buy(const char* name, const char* brand);
	void printAvailableProducts() const;
	void printProductsByBrand(const char* brand) const;

private:
	void copy(const Store& other);
	void free();
	int find(const char* name, const char* brand) const;
	bool removeProduct(size_t i);

private:
	Product** products;
	size_t size;
	size_t capacity;
};

#endif