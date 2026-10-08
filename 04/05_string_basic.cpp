#include <iostream>
#include <string>
using namespace std;
/*  string 기본 + 입력 + stoi
1) string은 가변 길이 문자열 클래스
2) append(str): 문자열 뒤에 str을 붙임 /length() 문자열 길이 반환
3) getline(cin >> ws, s): 앞 공백 제거 후, 공백 포함 한줄 입력
4) stoi(str): 문자열을 int로 변환
*/
int main(){
    // 1) string 생성/복사
    string str;
    string address("Kookmin university");
    string copyAddress(address);

    char text[] = {'L', 'o', 'v', 'e', '\0'};
    string title(text);

    cout << "str=[" << str << "]\n";
    cout << address << "\n";
    cout << copyAddress << "\n";
    cout << title << "\n";

    // 2) append/length
    str.append("I love ");
    str.append("C++.");
    cout << str << "\n";
    cout << "length = " << str.length() << "\n";
    
    // 3) getline 입력 (공백 포함)
    string line;
    cout << "Enter a line: ";
    getline(cin >> ws, line);
    cout << "line = " << line << "\n";

    // 4) stoi
    string s = "123";
    int n= stoi(s);
    cout << "stoi(" << s << ") = " << n << "\n";
    return 0;
}