#include <iostream>
#include <utility>
using namespace std;
/*  호출 방식 (값 / 주소 / 참조)
swap 구현
1) 값 전달: 복사본이라 원본 바뀌지 않음
2) 주소 전달: 포인터로 원본 직접 수정
3) 참조 전달: 별명으로 원본 직접 수정
*/
void swapByValue(int a, int b){
    int tmp = a;
    a = b;
    b = tmp;
}
void swapByAddress(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void swapByRef(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

int main(){
    int a =1, b = 2;
    swapByValue(a, b);
    cout << "Value: a=" << a << " b=" << b << "\n";
    swapByAddress(&a, &b);
    cout << "Address: a=" << a << " b=" << b << "\n";
    swapByRef(a, b);
    cout << "Ref: a=" << a << " b=" << b << "\n";
}