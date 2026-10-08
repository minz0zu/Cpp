#include <iostream>
#include "Adder.h"
#include "Calculator.h"
using namespace std;
/*
Calculator::run()에서 사용자 입력 받고, Adder 객체 생성하여 결과 출력
main()에서는 Calculator 객체 생성하여 run() 호출
*/
void Calculator::run() {
    int a, b;
    cout << "Enter two numbers to add: ";
    cin >> a >> b; // 사용자 입력 받기

    Adder adder(a, b);
    int result = adder.process(); // 두 수의 합 계산

    cout << "Result: " << result << "\n"; // 결과 출력력
}