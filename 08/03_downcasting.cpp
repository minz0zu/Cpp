#include <iostream>
#include <string>
using namespace std;
/* 다운캐스팅: Base* -> Derived* (주의)
1) 다운캐스팅은 자동 변환 아님. 명시적 캐스팅이 필요
2) "실제로 가리키는 객체"가 평생 클래스일때만 안전
(Base 객체를 Derived*로 잘못 캐스팅하면 정의되지 않은 동작 발생 가능)
3) 다운캐스팅은 "기반 타입으로 보관하던 객체를 다시 파생 타입 기능까지 쓰기 위해" 필요
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

int main(){
    ColorPoint cp;

    Point* pBase = &cp; // 업캐스팅
    pBase->set(3, 4);
    pBase->showPoint();

    // 이제 ColorPoint만의 기능(setColor...)이 필요해짐
    // 따라서 기반 클래스 포인터를 다시 파생 클래스 포인터로 다운캐스팅
    ColorPoint* pDer = (ColorPoint*)pBase; // 다운캐스팅(강제), 여기서는 다운이라 생략하면 안됨.
    pDer->setColor("Red");
    pDer->showColorPoint();
    // pBase가 실제로 ColorPoint 객체 cp를 가리키므로 안전.
    // 실제 객체가 그냥 Point였다면 이 캐스팅은 아주 위험.
    
    return 0;
}