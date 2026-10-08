#include "Adder.h"

Adder::Adder(int x, int y) : a(x), b(y) {} // 생성자: 객체 생성시 두 수 초기화화
int Adder::process() {
    return a + b; // 두 수의 합을 반환환
}