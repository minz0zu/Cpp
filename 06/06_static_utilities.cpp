#include <iostream>
using namespace std;
/*  static 활용
1) 객체 상태가 필요없는 함수는 static 멤버 함수로 묶어 유틸리티처럼 사용할 수 있다.
2) static 변수는 객체수와 상관없이 하나만 존재하므로 개수 세기 같은 역할
3) static 함수는 객체없이 호출되므로 this 포인터가 없다.
4) 따라서 static 함수는 non-static 멤버를 직접 읽을 수 없고, 객체를 따로 받아야한다.
*/
class Math {
public:
// 객체 상태가 필요없는 함수는 static으로 묶어두면 사용이 분명해진다.
    static int abs(int a){ return (a>=0) ? a : -a; }
    static int max(int a, int b){ return (a>b) ? a : b; }
    static int min(int a, int b){ return (a<b) ? a: b; }
};
class Circle {
private:
    static int numOfCircles;
    int radius;
public:
    Circle(int r = 1) : radius(r){ numOfCircles++;}
    ~Circle(){ numOfCircles--; }
    static int getNumOfCircles(){ return numOfCircles; }
    int getRadius() const { return radius; }
};
int Circle::numOfCircles = 0;

class PersonError {
private:
    int money;
public:
    PersonError() : money(0) {}
    void setMoney(int value) { money = value; }

    // static 함수는 this가 없어서(자기 자신이라는 개념이 없음) non-static 멤버를 직접 읽을 수 없다.
    // 따라서 필요한 객체를 인자로 받으면 그 객체의 값을 읽는 것은 가능
    static int getMoney(const PersonError &person){
        return person.money;
    }
};
int main(){
    // 전역 함수처럼 보이는 기능을 클래스 안 static으로 정리한 예제
    cout << "Math::abs(-5) = " << Math::abs(-5) << "\n";
    cout << "Math::max(10, 8) = " << Math::max(10, 8) << "\n";
    cout << "Math::min(-10, -5) = " << Math::min(-10, -5) << "\n";

    // static변수는 객체수와 무관하게 하나만 있어서, 카운터 역할에 적합.
    cout << "처음 개수 = " << Circle::getNumOfCircles() << "\n";
    Circle a;
    {
        Circle b(5);
        cout << "블록 안 개수 = " << Circle::getNumOfCircles() << "\n";
    }
    // 블록을 벗어나면지역 객체가 소멸
    cout << "블록 밖 개수 = " << Circle::getNumOfCircles() << "\n";

    Circle *arr = new Circle[3];
    cout << "블록 생성 후 개수 = " << Circle::getNumOfCircles() << "\n"; 
    delete[] arr;
    cout << "블록 삭제 후 개수 = " << Circle::getNumOfCircles() << "\n";

    PersonError person;
    person.setMoney(100);
    cout << "getMoney(person) = " << PersonError::getMoney(person) << "\n"; 
    return 0;
}