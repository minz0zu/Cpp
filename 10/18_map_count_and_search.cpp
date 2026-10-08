#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
/* map으로 판매 횟수 집계하기
---------------------------
문제상황
- 하루동안 팔린 상품 이름이 순서대로 기록되어 있다.
- 가게 주인은 어떤 상품이 몇 번 팔렸는지 집계하고 싶다.
- 또 특정 상품이 실제로 팔렸는지, 몇 번 팔렸는지도 확인하고 싶다.

문제설명
1) vector에 "판매된 상품 이름 목록"을 저장
2) map<string, int>로 각 상품이 몇 번 팔렸는지 집계한다.
3) find()로 특정 상품의 판매 횟수를 조회
*/

void printSales(map<string, int>& salesCount){
    for(map<string, int>::iterator it = salesCount.begin(); it!=salesCount.end(); it++){
        cout << it->first << " : " << it->second << "\n";
    }
    cout << "\n";
}

void searchItem(map<string, int>& salesCount,const string& itemName){
    map<string, int>::iterator it = salesCount.find(itemName);

    if(it==salesCount.end()){
        cout << itemName << ": No sold record\n";
    }
    else{
        cout << itemName << " : " << it->second << "sold\n";
    }
}

int main(){
    vector<string> soldItems;
    soldItems.push_back("apple");
    soldItems.push_back("banana");
    soldItems.push_back("apple");
    soldItems.push_back("milk");
    soldItems.push_back("apple");
    soldItems.push_back("banana");
    soldItems.push_back("apple");
    soldItems.push_back("apple");

    map<string, int> salesCount;

    // 판매 기록을 하나씩 보면서, 상품별 판매 횟수를 센다.
    for(vector<string>::const_iterator it=soldItems.begin(); it!=soldItems.end();it++){
        // *it에 해당되는 key가 아직 업승면 새 항목이 만들어지고,
        // value 타입은 int이므로 
        salesCount[*it]++;
    }
    // 집계 결과 출력
    printSales(salesCount);

    searchItem(salesCount, "apple");
    searchItem(salesCount, "orange");
    return 0;
}