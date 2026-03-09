#include <iostream>
#include <string> // strcmp
/*
std::string은 '=='으로 내용 비교 가능능
*/
int main(){
    std::string correct = "program123";
    std:: string input;

    std::cout << "Password: ";
    std::cin >> input; // 공백 없는 입력으로 가정.

    if (input == correct)
        std::cout << "Access granted\n";
    else
        std::cout << "Access denied\n";

    return 0;

}