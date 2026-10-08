#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
/* 템플릿 함수와 vector 를 함게 사용
----------------------------------
문제상황
-> 어떤 반의 시험 점수 목록에서 최고 점수를 찾고 싶다.
-> 학생 이름 목록에서 사전순으로 가장 뒤에 오는 이름도 찾고 싶다.
--> 두 문제는 "자료타입"만 다르고, "목록에서 가장 큰 값을 찾는다"는 작업
*/
template <class T>
void printVector(const vector<T>& v, const string& title){
    cout << title;
    for(typename vector<T>::const_iterator it = v.begin(); it!=v.end(); it++){
        cout << *it << ' ';
    }
    cout << "\n";
}
template <class T>
T getMax(const vector<T>& v){
    T maxScore = v.at(0);
    // iterator...
    for(typename vector<T>::const_iterator it = v.begin()+1; it!=v.end();it++){
        if(maxScore < *it){
            maxScore = *it;
        }
    }
    return maxScore;
}
int main(){
    // 문제1: 시험 점수 목록에서 최고점수
    vector<int> scores;
    scores.push_back(88);
    scores.push_back(75);
    scores.push_back(92);
    scores.push_back(85);
    printVector(scores, "scores: ");
    cout << "max score:" << getMax(scores) << "\n";

    // 문제2: 이름 목록에서 사전순으로 가장 뒤 이름 찾기
    vector<string> names;
    names.push_back("Kim");
    names.push_back("Lee");
    names.push_back("Park");
    names.push_back("Choi");
    printVector(names, "Names: ");
    cout << "max name:" << getMax(names) << "\n";
    return 0;
}