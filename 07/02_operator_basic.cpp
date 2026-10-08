#include <iostream>
using namespace std;
/*  연산자 오버로딩 기본 (+, ==, +=)
- 연산자 오버로딩은 'operator연산자 기호'형태의 멤버 함수로 정의할 수 있다.
- 'a+b'는 멤버 함수로 쓰면 'a.operator+(b)'처럼 해석됨
- 'a==b'는 'a.operator==(b)'처럼 해석
- 'a+=b'는 'a.operator+=(b)'처럼 해석
*/
class Power {
    int kick, punch;
public:
    Power(int k=0, int p=0) : kick(k), punch(p) {}
    void show() const {cout << "kick= " << kick << ", punch= " << punch << "\n"; }
    // 멤버 연산자 함수
    // 반환형 operator 연산자기호(오른쪽피연산자) [const]
    // a+b -> a.operator{b}
    Power operator+(const Power& op2) const{
        // a+b -> 새로운 Power로 생성
        return Power(kick + op2.kick, punch + op2.punch);
    }
    // 코드를 만들어 보라고 함
    // ==는 비교해서 bool 반환
    bool operator==(const Power& op2) const {
        return (kick==op2.kick && punch==op2.punch);
    }

    // +=는 결과적으로 왼쪽 객체 자신을 바꾸는 연산
    // "자기 자신을 수정하는 연산"에서는 참조 반환이 많음
    Power& operator+=(const Power& op2){
        kick += op2.kick;
        punch += op2.punch;
        return *this;
    }
};

// 코드를 만들어 보라고 함.
int main(){
    Power a(3, 5), b(4, 6), c;

    c = a + b;
    a.show(); b.show(); c.show();
    
    // a == b -> a.operator==(b)
    cout << (a==b ? "same\n" : "diff\n");

    // a += b -> a.operator+=(b)
    a.show(); b.show();
    c = (a += b);
    a.show(); b.show(); c.show();
    (a += b) += c;
    a.show(); b.show(); c.show();
    return 0;
}