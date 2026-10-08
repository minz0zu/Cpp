#include <iostream>
using namespace std;
/*  증감/논리/체이닝 연산자
1) 전위 '++a'는 'a.operator++()'처럼 해석된다.
2) 후위 'a++'는 'a.operator++(0)'처럼 해석되고, int값은 구분하기 위한(전위와 후위를 구분하기 위한) 표식.
3) 전위는 증가된 자기 자신을 계속 써야하므로, 참조 반환이 자연스럽다.
4) 후위는 증가 전의 옛값을 돌려줘야 하므로, 보통 값 반환을 사용한다.
*/
class Power {
    int kick, punch;
public:
    Power(int k=0, int p=0) : kick(k), punch(p) {}
    void show() const {cout << "kick= " << kick << " , punch= " << punch << "\n"; }
    // ++a -> a.operator++()
    Power& operator++(){
        kick++; punch++;
        return *this;
    }
    // a++ -> aoperator++(0)
    Power operator++(int){
        Power tmp = *this;
        kick++; punch++;
        return tmp;
    }
    // !a -> a.operator!()
    bool operator!() const {
        // 둘 다 0이면 true
        return (kick == 0 && punch == 0);
    }
    // c << 3 -> c.operator<<(3)
    // c << 3 << 4 << 5
    Power& operator<<(int n){
        kick += n;
        punch += n;
        return *this;
    }

};
int main(){
    Power a(3, 5), b;
    b = ++a; a.show(); b.show(); // 전위
    b = a++; a.show(); b.show(); // 후위

    // !Power(0, 0)은 true
    cout << (!Power(0, 0) ? "zero\n" : "not zero\n");

    Power c(1, 2);
    c << 3 << 4 << 5; // 내부 변수값이 3만큼 증가
    c.show();

    return 0;
}