```c++
//Всеки медиен ресурс трябва да има уникален идентификационен номер (ISBN за книгите и код за DVD филмите), заглавие, година на издаване, жанр.

class Media {
public:
    Media(std::string id, std::string title, unsigned year, std::string genre);
    virtual ~Media(); //NB!

    virtual void print() = 0;
    virtual Media* clone() const = 0;

    friend bool compare_media(const Media& m1, const Media& m2); 

private:
    std::string id;
    std::string title;
    unsigned year;
    std::string genre;
};

// Сравнява дали 2 медийни ресурса имат еднакви id и еднакви имена
// Това може да е и под формата на operator==
bool compare_media(const Media& m1, const Media& m2);
```
```c++
//държава, град, улица, номер, пощенски код
struct Address {
    std::string country;
    std::string city;
    std::string street;
    unsigned short number;
    std::string postal_code;
};
```
```c++
//името на издателството, адреса (държава, град, улица, номер, пощенски код) и годината, в която е основано.  
class Publisher {
public:
    Publisher(std::string name, Address address, unsigned year);
    void print();

private:
    std::string name;
    Address addr;
    unsigned year;
}
```
```c++
// трябва да се съхранява информация за автора, издателя, броя на страници и ISBN.
class Book : public Media {
public:
    Book(std::string id, std::string title, unsigned year, std::string genre, std::string author, const Publisher& p, unsigned n_pages);
    virtual ~Book();

    virtual void print();
    virtual Media* clone() const;

private:
    std::string author;
    Publisher publisher;
    unsigned n_pages;
}
```
```c++
//трябва да се съхранява информация за режисьора, актьорския състав и регионален код.
class DVD : public Media {
public:
    DVD(std::string id, std::string title, unsigned year, std::string genre, 
    std::string director, std::vector<std::string> actors, std::string code);
    virtual ~DVD();

    virtual void print();
    virtual Media* clone() const;

private:
    std::string director;
    std::vector<std::string> actors;
    std::string code;
}
```
```c++
// озвучаващия актьор (narrator) и продължителност.
class AudioBook : public Book {
public:
    AudioBook(std::string id, std::string title, unsigned year, std::string genre, std::string author, const Publisher& p, unsigned n_pages, std::string narrator, unsigned duration);
    virtual ~AudioBook();

    virtual void print();
    virtual Media* clone() const;

private:
    std::string narrator;
    unsigned duration;
}
```
```c++
class Shelf {
public:
    Shelf();
    Shelf(Media** content, size_t size, size_t capacity);
    Shelf(const Shelf& other);
    Shelf(Shelf&&);
    Shelf& operator=(const Shelf& other);
    Shelf& operator=(Shelf&&);
    ~Shelf();

    void print_contents() const;
    void add(Media* m);
    void remove(std::string id);

private:
    Media** content;
    size_t size;
    size_t capacity;
}
```
```c++
class Library{
public:
    Library(const std::vector<Shelf>& shelves);
    
    void print_contents() const;
    void print_book(std::string id);
    
    void add(Media* m, size_t shelf_index);
    void remove(std::string id);
    void move(std::string id, size_t new_shelf);

private:
    std::vector<Shelf> shelves;
}
```
