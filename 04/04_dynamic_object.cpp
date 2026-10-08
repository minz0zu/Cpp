#include <iostream>
using namespace std;
/* 동적 객체: new Circle(...) / delete */
/* 동적 객체 배열: new Circle[n] / delete[] */
/* this 포인터: 자기 자신 반환
1) this는 "현재 멤버 함수를 실행중인 객체 자신"을 가리키는 포인터
2) 매개변수 이름과 멤버 이름이 같은 때:
    this->radius = radius; (멤버 radius에 매개변수 radius를 대입)
3) return this; (메서드 체이닝 등에서 사용가능)
*/
class Circle{
    int radius;
public:
    Circle() : radius(1) {cout << "[C] radius = " << radius << "\n";}
    Circle(int radius) { this->radius = radius; }
    // Circle(int r) : radius(r) {cout << "[C] radius = " << radius << "\n";}
    ~Circle() {cout << "[D] radius = " << radius << "\n"; }
    void setRadius(int radius){ this->radius = radius; }
    double getArea() { return 3.14*radius*radius; }
    Circle *self() {return this; } // 자기 자신 포인터 반환
};

int main(){
    int r;
    while(true){
        cout << "radius(negative to quit) : ";
        cin >> r;
        if (r < 0) break;

        Circle *p = new Circle(r);
        cout << "area = " << p->getArea() << "\n";
        delete p;
    }

    cout << "How many circles? ";
    int n;
    cin >> n;
    if (n <= 0) return 0;

    Circle *arr = new Circle[n]; // 동적 객체 배열
    for(int i=0; i<n; i++){
        int r;
        cin >> r;
        arr[i].setRadius(r);
    }
    for(int i=0; i<n; i++){
        cout << arr[i].getArea() << "\n";
    }

    delete[] arr;
    Circle c1;
    Circle c2(2);

    c1.setRadius(4);
    c1.setRadius(5);

    cout << (c1.self() == &c1 ? "same\n" : "diff\n");
    return 0;
}