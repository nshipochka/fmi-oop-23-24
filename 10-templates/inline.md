# inline
```c++
inline void f(int a, int b) {
    if(a < b) cout << "yes";
}

int main() {
    f(10, 20); // -> if(10 < 20) cout << "yes" 
    // Компилатора може да оптимизира допълнително и да спести част от кода на програмата
}
```
- За да може да е `inline`, трбява компилаторът да ѝ вижда дефиницията, не само декларацията `inline void f(int a, int b);`

- Позволява се да е дефинирана една и съща `inline` функция в различни transaltion unit-и, при условие, че тялото е едно и също:   
    ```c++
    //one.cpp
    inline void f() { std::cout << "Hello"; }

    //two.cpp
    inline void f() { std::cout << "Hello"; } // Окей

    //three.cpp
    inline void f() { std::cout << "abc"; } // Недефинирано поведение
    ```
