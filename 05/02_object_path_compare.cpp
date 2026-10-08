#include <iostream>
using namespace std;
/*  객체 전달 방식 비교 (값 / 주소 / 참조)
*/
class Circle {
    int radius;
public:
    Circle(int r) : radius(r) { cout << "[C]" << radius << "\n"; }
    // 복사생성자
    Circle(Circle& c) : radius(c.radius){cout << "[CopyC]" << radius << "\n"; }
    ~Circle() {cout << "[D]" << radius << "\n"; }
    int getRadius() { return radius; }
    void setRadius(int r) { radius = r; }
};
void incByValue(Circle c){  // 값 전달
    c.setRadius(c.getRadius() + 1);
}
void incByAddress(Circle *c){   // 주소 전달
    c->setRadius(c->getRadius() + 1);
}
void incByRef(Circle &c){  // 참조 전달
    c.setRadius(c.getRadius() + 1);
}
int main(){
    Circle waffle(30);
    incByValue(waffle);
    cout << "after Value : " << waffle.getRadius() << "\n";
    incByAddress(&waffle);
    cout << "after Value : " << waffle.getRadius() << "\n";
    incByRef(waffle);
    cout << "after Value : " << waffle.getRadius() << "\n";

    return 0;
}