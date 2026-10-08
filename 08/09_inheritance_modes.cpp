/*
1. 상속이란?
- 기존 클래스의 멤버를 물려받아 새 클래스 만드는 방법
- 'public' 상속은 기존 인터페이스를 유지한채 확장한다는 의미 가장 자주 사용되는 상속 모드

2. 상속에서 접근 가능 멤버
- public 멤버: 외부에서도 접근 가능
- protected 멤버: 외부에서는 접근 불가, 파생 클래스 내부에서는 접근 가능
- private 멤버: 오직 그 클래스 내부에서만 접근 가능

3. 업캐스팅과 다운캐스팅
- 업캐스팅: 파생 클래스 포인터를 기반 클래스 포인터로 바꾸는 것
- 다운캐스팅: 기반 클래스 포인터를 파생 클래스 포인터로 바꾸는 것

4. 생성자와 소멸자 호출순서
- 상속에서는 기반 클래스가 먼저 생성, 파생 클래스가 나중에 생성
- 소멸은 반대

5. 상속 방식에 다른 접근 수준 변화
- public 상속:
 기반 public -> 파생 public, 기반 protected -> 파생 protected
- protected 상속:
 기반 public/protected -> 파생 protected
- privqte 상속:
 기반 public/protected -> 파생 private

 핵심:
 - 상속 방식은 "파생 클래스 안에서 쓸 수 있느냐"보다 "외부에서 그 멤버가 어떤 수준으로 보이느냐"를 바꾼다.
*/
#include <iostream>
using namespace std;

class Base {
public:
    void publicFunc(){
        cout << "Base::publicFunc()\n";
    }
protected:
    void protectedFunc(){
        cout << "Base::protectedFunc()\n";
}
private:
    int secret = 1234;
};

class PublicDerived : public Base {
public:
    void showInsideAccess(){
        cout << "Inside PublicDerived\n";
        publicFunc();
        protectedFunc();
    }
};

class ProtectedDerived : protected Base {
    public:
        void showInsideAccess(){
            cout << "Inside ProtectedDerived\n";
            publicFunc();
            protectedFunc();
        }
    };

class PrivateDerived : private Base {
    public:
        void showInsideAccess(){
            cout << "Inside PrivateDerived\n";
            publicFunc();
            protectedFunc();
            //cout << Base::secret; // inaccessible
        }
    };

int main(){
    PublicDerived pubobj;
    ProtectedDerived protobj;
    PrivateDerived privobj;

    cout << "1. Access inside derived classed\n";
    pubobj.showInsideAccess();
    protobj.showInsideAccess();
    privobj.showInsideAccess();

    cout << "2. Access from main\n";
    pubobj.publicFunc();
    // protobj.publicFunc(); // inaccessible
    // privobj.publicFunc(); // inaccessible

    // pubobj.protectedFunc(); // inaccessible

    return 0;
}