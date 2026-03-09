#include <iostream>
#include <string>
#include <limits>
/*
1) std::string은 C++표준문자열타입으로 길이를 자동관리해 char[]보다 다루기 쉽다.
2) 실무 기본 문자열 공백포함 입력은 std::string + std::getline의 조합.
3) 다만 getline앞에서 '>>'를 쓰면, 엔터('\n')가 버퍼에 남아, 다음 'getline'이 빈 문자열이 될 수 있음.
4) 해결책: std::cin.ignore(....., '\n');
--> 암기: '>>' 다음에 'getline'이면 'ignore'을 작성해줘야한다.
*/
int main(){
    int age;
    std::string intro; // 클래스 이름인건데, 타입의 이름을 적은 거다. std공간에 있는 string 타입으로 하겠다.

    std::cout << "Enter age: ";
    std::cin >> age;

    // 버퍼에 남은 엔터 제거
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout <<"Enter an intro: ";
    std::getline(std::cin, intro); //std 라이브러리에 있는 getline -> 공백포함 한 줄 입력

    std::cout << "age = " << age << "\n";
    std::cout << "intro : " << intro << "\n";

    return 0;
}

// 버퍼에 엔터가 남기 때문에, ignore을 붙여서 입력을 두 번 다 확실하게 할 수 있게 만듦.