#include <iostream>
using namespace std;
/*  오버로딩 핵심
1) 함수 이름이 같아도 매개변수의 개수나 타입이 다르면 공존할 수 있다.
2) 컴파일러는 "호출하는 모양"을 보고 어떤 함수를 부를지 결정.
3) 리턴 타입은 호출 시점에 보이지 않으므로 오버로딩 기준이 될 수 없다.
4) 같은 이름으로 묶는 것이 가능하더라도, 의미를 너무 많이 섞으면 설계가 불분명해질 수 있다.
*/
void printTitle(const char* title){
    cout << "[" << title << "]\n";
}
namespace BasicSum {
int sum(int a, int b){  return a+b;}
int sum(int a, int b, int c){  return a+b+c;}
double sum(double a, double b){  return a+b;}
}

namespace RangeExample {
int sum(int last){
    int total = 0;
    for(int i=0; i<=last; i++)
        total += i;
    return total;
}
int sum(int first, int last){   // 매개변수 2개, first <= last
    int total = 0;
    for (int i=first; i<=last; i++)
        total += i;
    return total;
}
}
int big(int a, int b){  return (a>b) ? a : b;}
int big(const int value[], int size){
    int result = value[0];
    for (int i = 1; i < size; i++)
        if (result < value[i])
            result = value[i];
    return result;     
}

int main(){
    // 컴파일러가 호출 모양을 어떻게 해석하는 지 유의 
    printTitle("기본 오버로딩");
    cout << "BasicSum::sum(2, 6) = " << BasicSum::sum(2, 6) << "\n";
    cout << "BasicSum::sum(2, 6, 33) = " << BasicSum::sum(2, 6, 33) << "\n";
    cout << "BasicSum::sum(12.5, 33.6) = " << BasicSum::sum(12.5, 33.6) << "\n";

    // 배열 버전은 매개변수 형태가 완전히 다르므로 다른 함수로 구분된다.
    printTitle("호출 모양이 다른 오버로딩");
    int value[5] = {1, 2, 3, 4, 5};
    cout << "big(2, 3) = " << big(2, 3) << "\n";
    cout << "big(value, 5) = " << big(value, 5) << "\n";

    printTitle("의미가 다른 sum 오버로딩");
    cout << "RangeExample::sum(3) = " << RangeExample::sum(3) << "\n";
    cout << "RangeExample::sum(3, 5) = " << RangeExample::sum(3, 5) << "\n";
    return 0;
}