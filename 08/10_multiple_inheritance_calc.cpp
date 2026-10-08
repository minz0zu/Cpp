#include <iostream>
using namespace std;
/*  다중 상속: 하나의 클래스가 여러 부모 클래스를 동시에 상속받는 것
(Calculator = Adder + Subtractor)

주의：
－ 다중 상속은 이름 충돌/다이아몬드 문제 등 복잡성을 만들 수 있다.
*/
class Adder {
protected:
    int add(int a, int b){ return a+b; }
};
class Subtractor {
protected:
    int minus(int a, int b){ return a-b; }
};

class Calculator : public Adder, public Subtractor {
public:
    int calculate(int op, int a, int b){
        switch(op){
            case '+' :  return add(a, b);
            case '-' : return minus(a, b);
            default: return 0;
        }
    }
};

int main(){
    Calculator c;
    cout << "2+4=" << c.calculate('+', 2, 4) << "\n";
    cout << "2-4=" << c.calculate('-', 2, 4) << "\n";


    return 0;
}