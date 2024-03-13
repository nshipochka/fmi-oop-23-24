#include "String.h"
#include <cstring>
#include <iostream>

String::String()
{	
	std::cout << "Default\n";
	m_data = nullptr;
	m_size = 0;
	m_capacity = 0;
}

String::String(const char* str)
{	
	std::cout << "w/ Arguments\n";
	m_size = strlen(str);
	m_capacity = m_size + 1;
	m_data = new char[m_capacity];
	strcpy_s(m_data, m_capacity, str);
}

String::String(const String& other)
	:String(other.m_data)
{
	std::cout << "Copy\n";
}

String& String::operator=(const String& other)
{
	std::cout << "operator=\n";
	if (this != &other) {
		delete[] m_data;

		m_size = other.m_size;
		m_capacity = other.m_capacity;
		m_data = new char[m_capacity];
		strcpy_s(m_data, m_capacity, other.m_data);
	}

	return *this;
}

String::~String()
{	
	std::cout << "Destructor\n";
	delete[] m_data;
}

String::String(String&& other)
{	
	std::cout << "Move Copy\n";
	m_data = other.m_data;
	m_size = other.m_size;
	m_capacity = other.m_capacity;

	other.m_data = nullptr;
	other.m_size = 0;
	other.m_capacity = 0;
}

String& String::operator=(String&& other)
{
	std::cout << "Move operator=\n";
	if (this != &other) {
		//copy(other);
		m_data = other.m_data;
		m_size = other.m_size;
		m_capacity = other.m_capacity;

		other.m_data = nullptr;
		other.m_size = 0;
		other.m_capacity = 0;
	}
	return *this;
}

void String::print() const
{	
	if (!m_data) return;
	std::cout << m_data << std::endl;
}
