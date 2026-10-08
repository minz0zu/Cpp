#include <iostream>
using namespace std;
/*  동적할당 new + delete
1) int *p = new int; -> 힙(heap)에 int 1개 할당
2) *p = 5;  -> 그 공간에 값 저장
3) delete p;  -> 반드시!! 반환(메모리 누수 방지)
4) delete 후 p는 "댕글링 포인터"가 될 수 있어 접근하면 위험
(실무팁: delete 후 p = nullptr; )
*/
int main(){
    int *p = new int(10);   // 동적할당
    *p = 5;
    cout << "*p = " << *p << "\n";
    delete p;   // 반환
    p = nullptr; // delete를 한 다음에 *p가 남아있으면 안됨. 이상한 숫자가 나옴->이거 하면 괜찮음.
    cout << *p;

    return 0;
}