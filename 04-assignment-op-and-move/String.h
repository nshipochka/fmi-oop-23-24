#pragma once
class String {
public:
	String(); //default

	String(const char* str);

	String(const String& other);
	String& operator=(const String& other);
	~String();

	String(String&& other);
	String& operator=(String&& other);

	void print() const;

	char at(size_t pos) const;
	String& append(const String& other);
	String& insert(size_t pos, char c);
	String& erase(size_t pos);

	int compare(const String& str) const; 
	// 0 - equal, <0 current is "smaller", >0 passed is "smaller"

private:
	/*void copy(String&& other) {
		m_data = other.m_data;
		m_size = other.m_size;
		m_capacity = other.m_capacity;

		other.m_data = nullptr;
		other.m_size = 0;
		other.m_capacity = 0;
	}*/
private:
	char* m_data;
	size_t m_size;
	size_t m_capacity;
};