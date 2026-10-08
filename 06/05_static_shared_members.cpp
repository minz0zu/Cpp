#include <iostream>
using namespace std;
/*  static 공유 멤버와 클래스 스코프 접근
1) 일반 멤버는 객체마다 따로 존재하지만, static 멤버는 클래스 전체가 하나를 공유
2) 따라서 static 값은 어느 객체로 접근하든 결국 같은 데이터를 가리킨다.
3) static 멤버는 객체 없이도 존재하므로, '클래스명::멤버' 형태로 접근할 수 있다.
4) static 멤버 변수는 선언만으로 끝나지 않고, 클래스 밖에서 한 번 정의해야 한다.(must)
*/
class Person{
public:
    int money;
    static int sharedMoney;

    // money는 개체마다 따로 가지는 값값
    Person(int money = 0) : money(money) {}

    void addMoney(int amount){ money += amount; }

    // 이 함수는 특정 객체가 아니라, 클래스 전체의 sharedMoney를 바꾼다.
    static void addShared(int amount){
        sharedMoney += amount;
    }
    static void printShared(){
        cout << "SharedMoney = " << sharedMoney << "\n";
    }
};
// static 멤버 변수는 클래스 밖에서 한 번 정의해야 실제 저장공간이 생긴다.
int Person::sharedMoney = 10;

int main(){
    Person han(100);
    Person lee(150);

    han.addMoney(50);
    lee.addMoney(200);
    cout << "han.money = " << han.money << "\n";
    cout << "lee.money = " << lee.money << "\n";

    // sharedMoney는 클래스 전체가 공유하는 하나의 값이다.
    han.sharedMoney = 200;
    cout << "han.sharedmoney = " << han.sharedMoney << "\n";
    cout << "lee.sharedmoney = " << lee.sharedMoney << "\n";

    // 객체 없이도 클래스명으로 static 접근
    Person::addShared(100);
    Person::printShared();

    Person::sharedMoney = 500;
    cout << Person::sharedMoney << "\n";
    cout << han.sharedMoney << "\n";

    return 0;
};