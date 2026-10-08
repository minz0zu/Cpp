#include <iostream>
using namespace std;
/* 기본 클래스에 기본 생성자 없는 경우
- 파생 클래스 생성자 기본적으로 Base()를 호출
- 그런데 Base()없고, Base(int)만 있으면, 
파생 클래스에서 어던 Base 생성자를 호출할 지 "명시"해야 한다.
*/
class A{
public:
    A(int x) {cout << "Ctor A(int) " << x << "\n"; }
};
class B : public A {
public:
    B() : A(10) { cout << "Ctor B\n"; }
    B(int x) : A(x + 3) { cout << "Ctor B(int) " << x << "\n";}
};
int main(){
    B b;
    B b2(5);
    return 0;
}