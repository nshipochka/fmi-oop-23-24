#include "Product.h"
#include <cstring>
#include <iostream>

Product::Product()
	:name(nullptr)
	,brand(nullptr)
	,price(0)
	,quantity(0)
{}

Product::Product(const char* name, const char* brand, double price, unsigned quantity)
	:name(nullptr)
	,brand(nullptr)
	,price(price)
	,quantity(quantity)
{	
	copy(this->name, name);
	copy(this->brand, brand);
}

Product::Product(const Product& other)
	:Product()
{
	copy(name, other.name);
	copy(brand, other.brand);
	price = other.price;
	quantity = other.quantity;
}

Product& Product::operator=(const Product& other)
{
	Product other_copy(other);
	swap(other_copy);
	return *this;
}

Product::~Product()
{
	delete[] name;
	delete[] brand;
}

void Product::swap(Product& other)
{	
	using std::swap;
	swap(name, other.name);
	swap(brand, other.brand);
	swap(price, other.price);
	swap(quantity, other.quantity);
}

void Product::copy(char*& dest, const char* src)
{
	delete[] dest;
	dest = new char[strlen(src) + 1];
	strcpy(dest, src);
}

void Product::setName(const char* name) {
	copy(this->name, name); // copy сме си го написали така, че и да трие досегашното this->name 
}

void Product::setBrand(const char* brand) {
	copy(this->brand, brand);
}

void Product::setPrice(double price) {
	this->price = price;
}

void Product::setQuantity(unsigned quantity) {
	this->quantity = quantity;
}

const char* Product::getName() const {
	return name;
}

const char* Product::getBrand() const {
	return brand;
}

double Product::getPrice() const {
	return price;
}

unsigned Product::getQuantity() const {
	return quantity;
}

void Product::print() const
{
	std::cout << name << " by " << brand << std::endl;
	std::cout << price << "lv." << std::endl;
}

