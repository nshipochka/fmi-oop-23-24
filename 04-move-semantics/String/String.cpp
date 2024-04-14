#include "String.h"
#include <cstring>
#include <iostream>

String::String() 
	:m_data(nullptr)
	,m_size(0)
	,m_capacity(0)
{
	std::cout << "Default constructor\n";
}

String::String(const char* str)
{
	m_capacity = strlen(str) + 1;
	m_data = new char[m_capacity];
	strcpy_s(m_data, m_capacity, str);
	m_size = m_capacity;

	std::cout << "Constructor w/ arguments\n";
}

String::String(const String& other)
{	
	std::cout << "Copy constructuctor\n";
	copy(other);
}

String& String::operator=(const String& other) // String a; a = a;
{	
	std::cout << "Assignment operator\n";

	if (this != &other) {
		delete[] m_data;
		copy(other);
	}

	return *this;
}

String::String(String&& other)
{	
	std::cout << "Move copy constructor\n";

	m_capacity = other.m_capacity;
	m_size = other.m_size;
	m_data = other.m_data;

	// Тук имаше грешка - нулираха се член-данните вместо тези на подадения обект
	other.m_data = nullptr;
	other.m_size = 0;
	other.m_capacity = 0;
}

String& String::operator=(String&& other)
{	
	std::cout << "Move operator=\n";
	if (this != &other) {
		m_capacity = other.m_capacity;
		m_size = other.m_size;
		
		delete[] m_data;
		m_data = other.m_data;

		other.m_data = nullptr;
		other.m_size = 0;
		other.m_capacity = 0;
	}
	return *this;
}

String::~String()
{	
	std::cout << "Destructor\n";
	free();
}

void String::print() const
{	
	if (!m_data) return;
	std::cout << m_data << std::endl;
}

String& String::append(const String& other)
{
	//"hello" + " world"
	if (m_capacity <= (m_size - 1) + other.m_size)
		resize(other.m_size);

	strcpy_s((m_data + m_size - 1), other.m_size, other.m_data);

	return *this;
}

void String::resize(size_t extra_size)
{	
	std::cout << "Resize\n";

	char* new_data = new char[m_capacity + extra_size];
	strcpy_s(new_data, m_capacity, m_data);

	delete[] m_data;
	m_data = new_data;
	
	m_capacity += extra_size;
}

void String::copy(const String& other)
{
	m_capacity = other.m_capacity;
	m_data = new char[m_capacity];
	strcpy_s(m_data, m_capacity, other.m_data);
	m_size = other.m_size;
}

void String::free()
{
	delete[] m_data;
	//m_size = 0;
	//m_capacity = 0;
}
