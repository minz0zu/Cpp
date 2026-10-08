#ifndef ADDER_H
#define ADDER_H

class Adder {
private:
    int a, b; // 더할 두 수
public:
    Adder(int x, int y); // 생성자: 객체 생성시 두 수 초기화
    int process(); // 두 수의 합을 반환하는 멤버 함수
};

#endif //ADDER.H