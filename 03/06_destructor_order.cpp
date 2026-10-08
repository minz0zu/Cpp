#include <iostream>
using namespace std;
/*  소멸자: 호출 시험과 순서(역순 소멸)
1) 소멸자: ~ClassName() 형태, 반환타입/매개변수 없음, 객체 소멸시 자동 호출
2) 지역 객체는 블록({}) 끝날 때 소멸
3) 소멸자 호출 순서: 지역 객체는 역순으로 소멸
*/
class Trace {
private:
    int id;
public:
    Trace(int i) : id(i) {cout << "Trace " << id << " 생성\n"; }
    ~Trace() { cout << "Trace " << id << " 소멸\n"; }
};

void func() {
    Trace t1(100); // func() 지역 객체
    Trace t2(200);
    Trace t3(300);
    cout << "func() 실행 중\n";
} // func() 끝나면 t3, t2, t1 순으로 소멸멸

int main(){
    Trace t0(0);
    func(); // func 호출
    cout << "main() 실행 중\n";
    return 0;
}