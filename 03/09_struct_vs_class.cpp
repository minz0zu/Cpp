#include <iostream>
using namespace std;
/* struct vs class: 기본 접근 제어자 차이
1) struct: 기본 접근 제어자 public, class: 기본 접근 제어자 private
두 개가 동일하기에 struct를 쓸 일이 없을 것이다.
*/
struct PointStruct {
    int x; // 기본적으로 public
    int y; // 기본적으로 public
};
class PointClass {
    int x; // 기본적으로 private
    int y; // 기본적으로 private
public:
    PointClass() : x(0), y(0) {} //생성자: 객체 생성시 x, y 초기화화
};
int main() {
    PointStruct ps;
    ps.x = 1;
    ps.y = 2;
    cout << "PointStruct: (" << ps.x << ", " << ps.y << ")\n";
}