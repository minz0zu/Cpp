#include <iostream>
using namespace std;
/*  기본생성자 자동생성 / 자동생성이 안 되는 경우
1) 생성자가 하나도 없으면, 컴파일러가 기본생성자를 자동으로 만들어준다.
2) 생성자가 하나라도 있으면, 기본생성자는 자동생성되지 않는다.
- 이때, 기본 생성자가 필요하면, 직접 만들어야 한다.
*/
class A {
public:
    int x; // 생성자 없음 -> A() 기본 생성자 자동생성
};
class B {
public:
    int x;
    B(int a) : x(a) {} // 생성자 있음 -> B() 기본 생성자 자동생성 안됨.
};
int main(){
    A a;    // OK: 컴파일러가 A()를 만들어줄 수 있음.
    cout << "A ok\n";
    B b(5); // OK: B(int) 생성자 호출
    cout << "B(5) ok\n";
    cout << "B2 ok\n";

    return 0;
}