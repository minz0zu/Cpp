#include <iostream>
/*
1) 'clear name[10]'는 최대 9글자 + 문자열 끝('\0')만 저장 가능.
2) 'std::cin >> name'은 공백에서 입력이 끊김.
- Michael Jackson 입력시, Michael만 저장됨.
*/
int main(){
    char name[10];
    
    std::cout << "Name? ";
    std::cin >> name;
    std::cout << "You entered: " << name << "\n";

    return 0;
}