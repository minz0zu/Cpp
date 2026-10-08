#ifndef CIRCLE_H
// 헤더 가드: 중복 포함 방지, 헤더 파일이 여러번 포함되어도 내부 선언이 중복되지 않게 보호
// 즉, 헤더를 여러 .cpp 파일에서 포함해도, 컴파일러는 한 번만 처리한다.
#define CIRCLE_H
/*
1) .h(헤더): 클래스 선언(설계도)만 둔다. 
*/

class Circle {
private:
    int radius;
public:
    Circle();
    Circle(int r);
    double getArea();
};

#endif //CIRCLE_H