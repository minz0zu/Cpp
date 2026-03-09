#include <iostream>
/*
    C++ 프로그램은 main()에서 시작
    표준 실력은 std::cout을 사용
    줄바꿈은 '\n' 또는 std::end1로 할 수 있다.
    return 0;은 프로그램이 정상 종료되었음을 의미

*/

int main(){

    // 선택 가이드:
    // 일반 출력(대부분) : '\n'
    // 입력 직전 안내처럼 "지금 당장 보여야 하는" 출력: std::endl 사용
    
    std::cout << "Hello C++!" << std::endl;
    std::cout << "This program ends\n";

    return 0;
}