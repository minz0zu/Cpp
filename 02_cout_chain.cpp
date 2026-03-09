#include <iostream>

int main(){
    int a = 10, b = 3;

    std::cout << "a = " << a << ", b = " << b << "\n";
    std::cout << "a + b = " << (a + b) << "\n";
    std::cout << "a / b = " << (a / b) << "   (integer division)\n";

    // 줄바꿈 비교
    std::cout << "Line 1\n";
    std::cout << "Line 2" << std::endl; // endl은 줄바꿈 + flush(개념)
    return 0;
}