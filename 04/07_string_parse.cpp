#include <iostream>
#include <string>
using namespace std;
/*
-------------------
문제 설명
1) 덧셈 문자열(예: "7+23+5+100")을 입력받아 합을 계산
- find(ch/str, start): start부터 문자/문자열 검색한 위치 반환, 없으면 npos(nonposition의 약자)
- substr(pos, len): pos부터 len만큼 반환
--> find + substr + stoi 문자열의 합 계산
2) '&'가 나올 때까지 여러 줄 텍스트를 입력받고, 찾을 문자열을 다른 문자열 모두 치환하여 출력한다.
- '&'가 나올 때까지 입력, 특정 문자열을 찾아 치환
- replace(pos, len, repl): pos부터 len만큼을 repl로 치환
-------------------
*/

int main(){
    // (1) 덧셈 문자열 합
    cout << "Enter sumexpression like 7+23+5: ";
    string expr;
    getline(cin >> ws, expr); // 공백 포함 한줄 전체 읽음
    int sum = 0;
    int pos = 0;
    while(true){
        int plus = expr.find('+', pos); // pos기준으로 +를 찾아 인덱스 반환

        if (plus == string::npos){
            // substr(pos): pos부터 끝까지
            string part = expr.substr(pos);
            sum += stoi(part);
            break;
        }
        string part = expr.substr(pos, plus - pos);
        sum += stoi(part);

        pos = plus + 1;
    }
    cout << "sum = " << sum << "\n";

    // (2) 멀티라인 find/replace
    cout << "Enter multi-line text. End with '&' character.\n";
    string text;
    // getline(...delim):delim 문자가 나올 때까지 읽음음 (멀티라인 가능)
    getline(cin >>ws, text, '&');

    cout << "Find: ";
    string from;
    getline(cin >> ws, from);
    
    cout << "Replace: ";
    string to;
    getline(cin >>ws, to);

    int idx = 0;
    while (true){
        // find(str, start) : start위치부터 문자열 str을 찾아 인덱스 반환
        idx = text.find(from, idx);
        if (idx == string::npos) break;
        // replace(pos, len, repl): pos부터 len만큼을 repl로 치환
        text.replace(idx, from.length(), to);
        idx += to.size();
    }
    cout << "-----------\n";
    cout <<text << "\n";
    return 0;
}