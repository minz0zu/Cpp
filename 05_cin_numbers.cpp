#include <iostream>
/*
1) 'std::cin은 키보드 입력을 읽는다.
2) '>>' 공백/탭/줄바꿈을 구분자로 사용해서 값을 순서대로 변수에 저장한다.
3) 'std::cin >> w >> h;'는 한 줄 입력 ('3 4')도 되고, 여러 줄 입력도
*/
int main(){
    int w, h;

    std::cout << "Enter width and height:";
    std::cin >> w >> h;
    std::cout << "Area = " << (w*h) << "\n";

    return 0;
}