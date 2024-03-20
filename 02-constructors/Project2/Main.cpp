#include <cstring>

class Person {
public:
	/*Person(const char* name, int age) {
		size_t len = strlen(name) + 1;
		m_name = new char[len];
		strcpy_s(m_name, len, name);

		m_age = age;
	}*/

	Person() {
		m_name = nullptr;
		m_age = 0;
	}

	/*Person(const Person& other) {	
		m_name = nullptr;
		m_age = 0;
	}*/

private:
	char* m_name;
	int m_age;
};


int main() {
	
	

		

	return 0;
}