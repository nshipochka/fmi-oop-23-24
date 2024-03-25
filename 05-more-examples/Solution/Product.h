#ifndef __PRODUCT_HEADER_INCLUDED__
#define __PRODUCT_HEADER_INCLUDED__

class Product {
public:
	Product();
	Product(const char* name, const char* brand, double price, unsigned quantity);
	Product(const Product& other);
	Product& operator=(const Product& other);
	~Product();

	void swap(Product& other);

	void setName(const char* name);
	void setBrand(const char* brand);
	void setPrice(double price);
	void setQuantity(unsigned quantity);

	const char* getName() const;
	const char* getBrand() const;
	double getPrice() const;
	unsigned getQuantity() const;

	void print() const;

private:
	void copy(char*& dest, const char* src);

private:
	char* name;
	char* brand;
	double price;
	unsigned quantity;
};

#endif