#include <iostream>
#include "Circle.h"
using namespace std;
/*
1) main.cpp는 클래스를 "사용" (선언은 헤더에서 가져옴)
2) #include "Circle.h"로 헤더 포함하여 Circle 클래스 선언 사용
3) 컴파일 시 main.cpp만 빌드하면, 구현(Circle.cpp)이 링크 되지 않는다!!
--> 반드시 Circle.cpp도 함께 컴파일 해야 한다.
--> 명령 예시: g++ main.cpp Circle.cpp -o run.exe
*/
int main(){
    Circle donut;
    cout << "Donut area: " << donut.getArea() << "\n";
    
    Circle pizza(10);
    cout << "Pizza area: " << pizza.getArea() << "\n";
    return 0;
}

// 헤더 말고 나머지 g++ .\main.cpp .\Circle.cpp -o run.exe 같이 실행 시켜야 함.