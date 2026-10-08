#include <iostream>
#include <string>
using namespace std;
/*
복사 생성자: 언제 자동 호출되는가?
1) 복사 생성자 형태: ClassName(const ClassName& other)
2) 자동 호출 대표 상화
- Person son = father; (대입연산자 초기화)
- function(father); (값 전달)
*/
class Person {
    string name;
public:
    Person(string n) : name(n) {}
    Person(const Person &p) : name(p.name){
        cout << "[CopyC] " << name << "\n";
    }
};
void func(Person p){

}
int main(){
    Person father("Kitae");
    Person son = father;
    func(father);
    return 0;
}