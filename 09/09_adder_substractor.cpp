#include <iostream>
#include <string>
using namespace std;
/* Adder/Substractor/Multiyply
-부모가 run()으로 공통 흐름을 고정
-자식은 실제 계산 방식
- 공통흐름: 제목출력 -> 입력확인 -> 계산 -> 식출력
*/
class Calculator {
protected:
    int a, b;
    virtual string getTitle() const = 0;
    virtual char getSymbol() const =0;
    virtual int cal() const = 0;
public:
    void setValue(int x, int y) {
        a= x;
        b= y;

    }
    void run() const{ // 전체 실행 순서를 고정
        cout << "[" << getTitle() << "]\n";
        cout << a << getSymbol() << b << " = " << cal() << "\n";
    }
    virtual ~Calculator() {}

};

class Adder : public Calculator {
protected:
    string getTitle() const override {return "Adder";}
    char getSymbol() const override {return '+';}
    int cal() const override {return a + b;}
};

class Substractor : public Calculator {
protected:
    string getTitle() const override {return "Substractor";}
    char getSymbol() const override {return '-';}
    int cal() const override {return a - b;}
};

class Multiplier : public Calculator {
protected:
    string getTitle() const override {return "Multiplier";}
    char getSymbol() const override {return '*';}
    int cal() const override {return a * b;}
};


int main() {
    Adder adder;
    Substractor sub;
    Multiplier mul;
    Calculator* p[3] = {&adder, &sub, &mul};

    // 부모 타입 포인터 배열로, 자식 객체들을 한꺼번에 다룬다.
    for (int i = 0; i < 3; i++) {
        p[i]->setValue(10, 20);
        p[i]->run();
    }

    return 0;
}