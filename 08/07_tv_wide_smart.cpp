#include <iostream>
#include <string>
using namespace std;
/*  생성자 매개변수 전달: TV -> WideTV -> SmartTV
파생 클래스 생성자에서 초기화 리스트로 부모 생성자를 호출해
"기본 클래스 부분"을 원하는 값으로 초기화
*/
class TV {
int size;
public:
    TV() : size(20) {}
    TV(int size) : size(size) {}
    int getSize() const {return size;}
};

class WideTV : public TV {
bool videoIn;
public:
    WideTV(int size, bool videoIn) : TV(size), videoIn(videoIn) {}
    bool getVideoIn() const { return videoIn; }
};

class SmartTV : public WideTV {
string ipAddr;
public:
    SmartTV(string ip, int size) : WideTV(size, true), ipAddr(ip) {}
    string getIpAddr() const { return ipAddr; }
};

int main(){
    SmartTV htv("192.0.0.100", 64);
    cout << "size=" << htv.getSize() << "\n";
    cout << "videoIn=" << htv.getVideoIn() << "\n";
    cout << "Ip=" << htv.getIpAddr() << "\n";

    return 0;
}