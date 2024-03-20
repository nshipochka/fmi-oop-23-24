#ifndef __STRING_HEADER_INCLUDED__
#define __STRING_HEADER_INCLUDED__

class String {
public:
	//ctor
	String(); 
	String(const char* str); // String name("Pesho");
	String(const String& other);
	String& operator=(const String& other); // name = otherstring = originalstring // a = b = 5;

	//move 
	String(String&& other);
	String& operator=(String&& other);

	~String();

	void print() const;

	String& append(const String& other);
	//String& append(String&& other);

private:
	void resize(size_t size);
	void copy(const String& other);
	void free();
	
private:
	char* m_data;
	size_t m_size; // used
	size_t m_capacity; // allocated
};

#endif