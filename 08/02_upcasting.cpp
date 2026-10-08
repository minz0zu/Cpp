#include <iostream>
#include <string>
using namespace std;
/* 업캐스팅: Derived* -> Base*
1) 업캐스팅 자동 변환 가능: Point* p = (ColorPoint*)&cp;
2) Base*로 접근할 때는 Base에 존재하는 멤버만 호출 가능.
(파생 클래스만 가진 멤버는 호출 불가)
3) 업캐스팅은 "여러 파생 객체를 하나의 기반 타입으로 묶어 다루기 위해 필요한 것"
(공통 기능을 기준으로 처리할 때 쓴다.)
*/

class Point {
    int x, y; // private
public:
    void set(int x, int y){ this->x = x; this->y = y; }
    void showPoint() const{cout << "(" << x << ", " << y << ")\n"; }
};

class ColorPoint : public Point {
    string color;  // private
public:
    void setColor(string color){this->color = color;}
    void showColorPoint() const {cout << color << ":"; showPoint(); }
};

void printPoint(Point* p){
    p->showPoint();
}

int main(){
    ColorPoint cp;
    ColorPoint* pDer = &cp;

    // cp는 ColorPoint 객체이므로, Point 부분도 함께 존재한다.
    Point* pBase = pDer; // 자동 업캐스팅
    pDer->set(3,4);
    pBase->showPoint();

    pDer->setColor("Red");
    pDer->showColorPoint();

    // pBase는 Point로 보고 있으므로, Point에 있는 멤버만 호출 가능.
    // pBase->showColorPoint(); // Base에는 없음.

    Point p;
    p.set(1,2);
    printPoint(&p);
    printPoint(&cp);
    return 0;
}