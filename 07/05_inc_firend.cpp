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
    void show() const {cout << "kick= " << kick << ", punch= " << punch << "\n"; }
    
    // a+2 --> a.operator+(2)
    Power operator+(int op2) const{
        return Power(kick + op2, punch + op2);
    }

    // ++a -> 외부함수 operator++(a)
    friend Power& operator++(Power& op);
    // a++ -> 외부함수 aoperator++(a, 0)
    friend Power operator++(Power& op, int);   
};

Power& operator++(Power& op){
    op.kick++; op.punch++;
    return op;
}
Power operator++(Power& op, int){
    Power tmp = op;
    op.kick++; op.punch++;
    return tmp;
}

int main(){
    Power a(3, 5), b;
    b = ++a; a.show(); b.show(); // 전위
    b = a++; a.show(); b.show(); // 후위

    return 0;
}