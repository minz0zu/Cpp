#include "Circle.h"
/*
1) .cpp(소스): 클래스 구현(동작) 둔다. (.h에서 선언한 함수들을 구현)
2) #include "Circle.h"로 헤더 포함
*/
Circle::Circle() : Circle(1) {}
Circle::Circle(int r) : radius(r) {}
double Circle::getArea() {
    return 3.14159 * radius * radius;
}