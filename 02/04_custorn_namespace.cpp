#include <iostream>
/*
1) namespace는 이름(함수/변수/클래스)의 "구역"을 만들어 이름 충돌을 줄인다.
2) 같은 이름 함수라도 'kitae::print()', 'bob::print()'처럼 구분 호출
3) 'using' 지시어를 사용하면 'namespace::' 접두사 생략 가능
*/
namespace kitae{
    void print() { std::cout << "kitae::print()\n"; }
}

namespace bob{
    void print() { std::cout << "bob::print()\n"; }
}

int main(){
    kitae::print();
    bob::print();

    // using을 쓰면 더 짧게 호출
    using namespace kitae;
    print(); // kitae::print()가 호출

    return 0;
}