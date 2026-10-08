#include <iostream>
using namespace std;
/*
1) privte 멤버 변수는 클래스 밖에서 접근 불가
2) 생성자도 privte 가능: 외부에서 객체 생성이 제한될 수 있음
*/
class PrivateAccessError {
private:
    int a;
    PrivateAccessError() {a=1; b=2;} // 생성자도 private 가능
    void f() { a = 5; } // private 멤버 함수도 클래스 밖에서 접근 불가
public:
    int b;
    PrivateAccessError(int n) {}
    void g() { b = 10;} // public 멤버 함수는 클래스 밖에서 접근 가능
};
int main(){
    // PrivateAccessError obj; // ERROR; 생성자가 privtae이므로 객체 생성 불가
    PrivateAccessError obj(5); // OK: public 생성자 호출
    // obj.a = 3 // ERROR
    // obj.f(); // ERROR
    obj.b = 4; // OK
    obj.g(); //OK
    return 0;
}