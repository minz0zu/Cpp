#include <iostream>
#include <string>
using namespace std;
/*  모호성 사례
1) 오버로딩은 편리하지만, 후보가 둘 이상 똑같이 그럴듯하면 컴파일러도 결정.
2) 디폴트 매개변수는 호출 함수를 늘리기 때문에 모호성을 만들기 쉽다.
3) 자동 형 변환이 여러 방향으로 가능하면 의도하지 않은 충돌이 생긴다.
4) 의미가 다른 함수는 명확하게 이름을 분리하는 편이 안전.
*/
namespace DefaultParamConflict{
// 각각은 가능해보여도, 함께 두면 msg(10) 같은 호출이 충돌할 수 있다.
void msg(int id, string text = ""){
    cout << "msg(int, string)->" << id << ":" << text << "\n";
}
}
namespace CastAmbiguity{
// square(3)에서는 int가 float와 double로 모두 변환 가능
float square(float value){ return value*value; }
double square(double value){ return value*value; }
}
namespace ReferenceAmbiguity {
// add(a, b) 호출 -> 호출 문법이 같으면 컴파일러 입장에서도 구분 근거가
int add(int a, int b){ return a+b; }
int add(int a, int &b){ b += a; return b; }
}
namespace BetterDesign {
// 의미가 다른 함수는 이름을 나눠 두는 편이 더 분명
int addValue(int a, int b) {return a+b;}
int addInPlace(int a, int &b) { b += a; return b;}
}

int main(){
    DefaultParamConflict::msg(5, "Good");
//  DefalutParamConflict::msg(5);
    cout << "square(3.0) = " << CastAmbiguity::square(3.0) << "\n";
//  cout << "square(3) = " << CastAmbiguity::square(3) << "\n"; 3은 double, float 다 됨.
    int s = 10;
    int t = 20;
    cout << "ReferenceAmbiguity::add(10, 20) =" << ReferenceAmbiguity::add(10, 20) << "\n";
//  cout <<  ReferenceAmbiguity::add(s, t); 안됨.
    cout << BetterDesign::addValue(s, t) << "\n";
    cout << BetterDesign::addInPlace(s, t) << "\n";


    return 0;
}