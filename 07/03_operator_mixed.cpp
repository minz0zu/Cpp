#include <iostream>
using namespace std;
/*  int와의 혼합 연산자(+): a+2, 2+a
- 멤버 연산자 함수는 '왼쪽객체.operator+(오른쪽 값)'형태로 해석
ex1) 'a+2' -> 'a.operator+(2)'
ex2) '2+a' -> 왼쪽이 int라서 'int' 클래스에 멤버 함수를 추가할 수 없다.
ex2의 경우, 외부함수 'operator+(int, xonst Power&)'형태가 필요
외부 함수가 private 멤버를 읽어야 하므로 friend를 사용
--> a+2와 2+a를 모두 지언하려면 멤버+friend가 필요
*/
class Power {
    int kick, punch;
public:
    Power(int k=0, int p=0) : kick(k), punch(p) {}
    void show() const {cout << "kick= " << kick << ", punch= " << punch << "\n"; }
    // a+2 -> a.operator+(2)
    Power operator+(int op2) const{
        return Power(kick+op2, punch+op2);
    }
    // 2+a
    friend Power operator+(int op1, const Power& op2);
};
// 외부함수 문법: 반환형 operator 연산자 기호(왼쪽 피연산자, 오른쪽 피연산자)
// 2+a -> operator+(2, a)
Power operator+(int op1, const Power& op2){
    return Power(op1+op2.kick, op1+op2.punch);
}

int main(){
    Power a(3, 5), b, c;
    b = a + 2; // 멤버
    c = 2 + a; // friend
    // 멤버로 할 수 없는 경우가 있기에 friend가 생긴거다.
    a.show(); b.show(); c.show();

    return 0;
}