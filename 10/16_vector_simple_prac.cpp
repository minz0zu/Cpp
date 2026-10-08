#include <iostream>
#include <string>
#include <vector>
using namespace std;
/* 한 반의 시험 점수 목록에서 최고 점수를 찾고 싶다.
1) vector<int> 에 시험 점수 저장
2) printScores(), getMaxSores()
*/
void printScores(const vector<int>& scores, const string& title){
    cout << title;
    // iterator...
    for(vector<int>::const_iterator it=scores.begin(); it!=scores.end();it++){
        cout << *it << ' ';
    }
    cout <<"\n";
}
int getMaxScore(const vector<int>& scores){
    int maxScore = scores.at(0);
    // iterator...
    for(vector<int>::const_iterator it = scores.begin(); it!=scores.end();it++){
        if(maxScore<*it){
            maxScore = *it;
        }
    }
    return maxScore;
}
int main(){
    vector<int> scores;
    scores.push_back(88);
    scores.push_back(75);
    scores.push_back(92);
    scores.push_back(85);
    printScores(scores, "scores: ");
    cout << "max score:" << getMaxScore(scores) << "\n";
    return 0;
}