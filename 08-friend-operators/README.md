# friend

```c++
class Dog {
public:
    friend int compare(const Dog& a, const Dog& b);
protected:
    char* name;
private:
    int age;
}

int compare(const Dog& a, const Dog& b) {
    if(a.age == b.age)
        return 0;
    return (a.age < b.age ? -1 : 1);
}
```
- `compare` има достъп до всички членове на `Dog` - и `private`, и `protected`
- разликата с методите на класа е, че няма указател `this`, защото не е член на класа, а е нормална функция и трябва да получава обекта като аргумент, за да работи върху него
- обявяването, че фунцкия или клас е приятелски може да се случи където и да е в класа

# operator overloading
## Kакво беше предефиниране?
```c++
void print(int* arr, size_t size);
void print(char* str);
void print(const Dog& dog);
```

## Предефиниране на оператори
[В cppreference](https://en.cppreference.com/w/cpp/language/operators)
[Increment/Decrement](https://en.cppreference.com/w/cpp/language/operator_incdec)

*"Предефинираме"* операторите, защото те вече са написани за простите типове в езика, а ние пишем нови за дефинираните от нас.

Например вече има оператор `==` дефиниран за `int`, но няма за нашия тип `Dog`. Ако напишем оператор равно за `Dog` с някаква смислена функционалност, кодът става по-четим, а и по-лесен за писане:

```c++
Dog chihuahua("Ares", 2);
Dog husky("Mars", 10);

//За да видим дали кучетата имат еднакви имена и възраст, досега трябваше да правим така:
if(!strcmp(chihuahua.getName(), husky.getName() 
    && chihuahua.getAge() == husky.getAge())) {
    //...
}

//Ако имаме operator== за класа Dog, можем да си спестим доста код
if(chihuahua == husky) {
    //...
}
```

*НЕ МОГАТ* да се предефинират следните оператори:
- . (точка) 
- :: 
- ?: 
- sizeof    

[Обеснение от Бярне Строуструп защо не може.](https://www.stroustrup.com/bs_faq2.html#overload-dot]) 

## Операторите могат да са:
- част от класа - всички унарни операции - `!, ++, [], etc.` или такива, които променят единия аргумент - `+=, *=, etc.` 

- приятелски - не са членове на класа, но са му `friend` функции и могат да виждат неговите `private` член данни и методи   

- глобални - не са членове на класа и не им се налага да виждат неговите член-данни, могат да използват публичните методи на класа

