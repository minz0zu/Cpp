#include <iostream>
using namespace std;
/* 추상 클래스 Calculator -> GoodCalc 구현
- 순수 가상함수 3개 가진 Calculator 추상 클래스 만들기
- GoodCalc가 3개를 모두 구현하면, 객체 생성 가능
*/
class Calculator {
public:
    virtual int add(int a, int b) = 0;
    virtual int subtract(int a, int b) = 0;
    virtual double average(int a[], int size) = 0;
    virtual ~Calculator() {}
};


class GoodCalc : public Calculator {
public:
    int add(int a, int b) override {return a + b;}
    int subtract(int a, int b) override {return a - b;}
    double average(int a[], int size) override {
        double sum = 0;
        for (int i = 0; i < size; i++) {
            sum += a[i];
        }
        return sum / size;
    }
};


int main() {
    int a[] = {1, 2, 3, 4, 5};
    Calculator *p = new GoodCalc();
    // 사용하는 쪽은 Calculator의 인터페이스만 알면 된다.
    cout<<p->add(10, 20) << "\n";
    cout<<p->subtract(10, 20) << "\n";
    cout<<p->average(a, 5) << "\n";
    delete p;
    return 0;

}
