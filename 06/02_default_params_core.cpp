#include <iostream>
#include <string>
using namespace std;
/*  디폴트 매개변수
1) 디폴트 매개변수는 "인수를 생략했을 때 자동으로 채워지는 값"
2) 보통 선언부에 적어야 함수 사용자가 기본값을 한눈에 볼 수 있다.
3) 디폴트 값은 뒤에서부터 연속으로만 줄 수 있다.
-> 잘 쓰면 비슷한 함수 여러 개를 만들 필요가 없어져 코드가 단순해진다.
*/
void star(int count = 5);
void msg(int id, string text = "");
void calc(int a, int b = 5, int c = 0, int d = 0);
void fillLine(int n =25, char c = '*');
// void calcBad(int a, int b=5, int c, int d=0); 이건 안됨. b=5이라면 그 뒤에 부터는 다 채워져야한다.

void star(int count){   // star() --> star(5)
    for(int i=0;i<count; i++)
        cout << "*";
    cout << "\n";
}
void msg(int id, string text){ // msg(10) --> msg(10, "")
    cout << "id=" << id << ", text=" << text << "\n";
}
void calc(int a, int b, int c, int d){  // calc(1), calc(1, 2)
    cout << "calc : " << a << "," << b << "," << c << "," << d << "\n";
}
void fillLine(int n, char c){
    for(int i=0; i<n; i++)
        cout << c;
    cout << "\n";
}

int main(){
    star();
    star(10);
    msg(10);
    msg(10, "Hello");

    calc(10);
    calc(10, 5);
    calc(10, 5, 20);
    calc(10, 5, 20, 30);

    fillLine();
    fillLine(10, '%');
    fillLine(12, '-');
    return 0;
}