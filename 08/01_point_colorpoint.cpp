#include <iostream>
#include <string>
using namespace std;
/*  상속 선언: Point -> ColorPoint
1) class ColorPoint : public Point (public 상속)
2) 파생 클래스 객체는 "기본 클래스 부분 + 파생 클래스 부분"을 함께 가지게 된다.
3) 기본 클래스의 private 멤버는 파생 클래스에서도 직접 접근
4) 파생 클래스는 기본 클래스의 public 멤버 함수는 그대로 사용할 수 있다.
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
    cp.set(3, 4); // basic
    cp.setColor("Red"); // derived
    cp.showColorPoint();
    return 0;
}