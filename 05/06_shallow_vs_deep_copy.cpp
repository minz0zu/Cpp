#include <iostream>
#include <cstring>
using namespace std;
/*  얕은 복사 vs 깊은 복사 (포인터 멤버(높은 확률로 배열같은 주소를 받을 확률이 있다.)관리의 중요성)
문제 배경:
 - 객체가 포인터 멤버(동적 메모리)를 가질 때, 복사 방식이 결과 좌우
 - 디폴트 복사생성자: 얕은 복사만 한다.(포인터 값만 복사, 즉 같은 동적 메모리 공유)
해결방법: 깊은 복사 구현 (복사 생성자에서 새로운 동적 메모리 할당 후 내용 복사)
핵심: 동적 메모리를 멤버로 가지면 "복사 생성자" 구현하기
*/
class PersonShallow{
    char *name; // 동적 할당 문자열 주소
    int id;
public:
    PersonShallow(int id, const char* n) : id(id) {
        int len = strlen(n);
        name = new char[len + 1]; // NULL 포함
        strcpy(name, n);
    }
    ~PersonShallow() {cout << "D\n"; delete[] name; }
        void changeName(const char *n) {
            if(strlen(n) > strlen(name)) return;

        }
        void show(){
            cout << id << "," << name << "\n";
        }
    };
    
    class PersonDeep{
        char *name; // 동적 할당 문자열 주소
        int id;
    public:
        PersonDeep(int id, const char* n) : id(id) {
            int len = strlen(n);
            name = new char[len + 1]; // NULL 포함
            strcpy(name, n);
        }
        // 복사 생성자 명시적 구현
        PersonDeep(const PersonDeep& p) : id(p.id){
            int len = strlen(p.name);
            name = new char[len + 1];
        strcpy(name, p.name);
        cout << "[CopyC] " << name << "\n";
        }
        ~PersonDeep() {cout << "D\n"; delete[] name;}
            void changeName(const char *n) {
                if(strlen(n) > strlen(name)) return;
    
            }
            void show(){
                cout << id << "," << name << "\n";
            }
        };

    int main(){
        PersonDeep father(1, "kitae");
        father.show();
        PersonDeep daughter(father);
        daughter.show();
        return 0;
    }