# Теоретични въпроси
```c++
// Каква е видимостта на всяка от променливите?
class T {
  int t1;
private:
  int t2;
  int t3;
public:
  int t4;
};
```
```c++
// За всяко извикване обяснете дали е коректно или е грешка и какво се случва при подаването.
 class Test {
 };
 void by_ref(Test& param) {}
 void by_cref(const Test& param) {}
 void by_value(Test param) {}
 void by_cvalue(const Test param) {}

int main() {
   by_ref(Test());
   by_cref(Test());
   by_value(Test());
   by_cvalue(Test());
 }
```
# Assignment Operator
```c++
String(const String&);
String& operator=(const String&);
```

# Move Semantics
```c++
String(String&&);
String& operator=(String&&);
```
