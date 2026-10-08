#include <iostream>
#include <string>
using namespace std;
/* protected 접근 지정자
- protected 멤버
1) 클래스 내부 OK
2) 파생 클래스 내부 OK
3) 외부(함수/다른 클래스)에서는 접근 불가
*/

class Point {
protected:
    int x, y;
public:
    void set(int x, int y){ this->x = x; this->y = y; }
    void showPoint() const{cout << "(" << x << ", " << y << ")\n"; }
};

class ColorPoint : public Point {
    string color;  // private
public:
    void setColor(string color){this->color = color;}
    void showColorPoint() const {cout << color << ":"; showPoint(); }
    bool equals(const ColorPoint& p) const {
        // 파생 클래스 내부라 (protected) x, y 직접 접근이 가능.
        return (x==p.x && y==p.y && color==p.color);
    }
};
int main(){
    Point p;
    p.set(2, 3);
    // p.x = 5; // Error: protected여서 접근이 안된다.

    ColorPoint a; a.set(3, 4); a.setColor("Red");
    ColorPoint b; b.set(3, 4); b.setColor("Red");
    cout << (a.equals(b) ? "true\n" : "false\n");

    return 0;
}