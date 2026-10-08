#include <iostream>
#include <string>

/*
1) std::string은 길이 관리/복사/비교가 쉬운 C++ 표준 문자열 타입
2) '+' 연산으로 문자열 결합이 가능
3) 길이는 'length()(또는 size())로 확인.
4) '=='로 내용 비교가 가능 (C문자열보다 직관적)
*/
int main(){
    std::string a = "Hello";
    std::string b = "C++";
    std::string c = a + " " + b + "!";

    std::cout << c << "\n";

    std::cout << "Length: " << c.length() << "\n";

    if (b == "C++"){
        std::cout << "b is exactly C++\n";
    }

    return 0;
}