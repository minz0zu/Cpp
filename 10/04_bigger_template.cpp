#include <iostream>
using namespace std;

/*
    T bigger(T a, T b): 비교연산(>)이 가능한 타입만 사용 가능
*/

template <class T>
T bigger(T a, T b){
    return (a>b) ? a : b;

}

int main() {
    int a = 20, b =50;
    char c = 'a', d='z';
    cout << bigger(a, b) << "\n";
    cout << bigger(c, d) << "\n";
    return 0;
}