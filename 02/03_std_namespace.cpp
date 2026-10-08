#include <iostream>
/*
    1) C++ 표준 라이브러리 이름(cout, end1... 등)은 std 네임스페이스에 있다.
    2) std 사용 방식 3가지
        - std::cout 처럼 접두사 사용
        - 둘 사이의 하이브리드처럼 using std::cout; 처럼 필요한 이름만 가져오기
        - using namespace std; 전체 가져오기 (편하지만 이름 충돌 위험)
*/
int main(){
    std::cout << "(1) Using std:: prefix\n";

    using std::cout;
    using std::endl;
    cout << "(2) Using selected names (cout, end1)" << endl;

    using namespace std;
    cout << "(3) Using namespace std\n" << endl;

    return 0;
}