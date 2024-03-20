# Rvalues & Lvalues (again)
`lvalue` - нещо, което има специфична локация в паметта - нещо, в което може да се сложи съдържание     
`rvalue` - нещо, което не е lvalue, генерално е временно (запазено в някакъв регистър на програмата) и с кратък живот - съдържанието, което се слага  
```c++
int y = &x // тук оператор& взима lvalue и от него създава rvalue (адреса)  
int* y = &666 // не може, защото 666 няма адрес, който да изведем от паметта 
// гледайте с какви съобщения гърми програмата и ги проверявайте какво значат
```

- Защо `const Test&` приема и lvalue, и rvalue - решава проблема, че за да подадем rvalue на функция, трябва да създаваме временна променлива
    ```c++
    void f(int& t) {...};

    f(5); // Не може, нарочно е наложено от езика
    

    int x = 5; 
    f(x);
    ```
    ```c++
    void f(const int& t) {...};

    f(5); // Всъщност отзад компилаторът прави горното
    ```
- Защо тогава има `Test&&`? За да може да има move семантиките
- Защо `noexcept`? За exception safety guarantee.

# Copy and Swap
 ```c++
    // Copy and Swap Idiom
    void String::swap(String& other) {
        using std::swap;
        swap(m_data, other.m_data);
        swap(m_size, other.m_size);
        swap(m_capacity, other.m_capacity);
    }

    String& String::operator=(const String& other) {
        String copy(other); // copy
        swap(copy); // and swap
        return *this;
    } 
```

# Git
1. [Сваляте Git](https://git-scm.com/downloads) и инсталирате
2. Отваряте `cmd` -> пишете `git config --global user.name <юзърнейма ви>` и `git config --global user.email <имейла ви>`
3. _(Optional) За по-сигурна връзка с репото: [Генериране на GitHub SSH ключ](https://docs.github.com/en/authentication/connecting-to-github-with-ssh/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent)_ 
4. Пишете `git clone <url на репото, което искате да свалите>` - това създава локално копие в папката, в която се намирате в конзолата
5. Решавате си задачите в тази папка
6. `git add <път към файл/папка, която искате да качите в репото>`
7. `git commit -m "<Съобщение, което да пише какви промени сте направили>"`
8. `git push`

[Допълнителна информация](https://github.com/semerdzhiev/reading/blob/main/git.adoc)

