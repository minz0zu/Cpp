#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/* STL 알고리즘 sort(begin, end)
- sort는 <algorithm> 헤더의 전역 함수 템플릿
- sort(v.begin(), v.end()) [begin, end)
- 기본은 오름차순(원소의 operator< 사용)
- 내림차순은 sort(..., greater<int>())
*/

int main(){
    vector<int> v;
    
    for(int i=0;i<5;i++){
        int n; cin >> n;
        v.push_back(n);
    }
    sort(v.begin(), v.end());

    for(vector<int>::iterator it=v.begin(); it!=v.end(); it++)
        cout << *it << ' ';
    cout << "\n";

    // greator<int>() 비교자를 주면, 내림차순 정렬
    sort(v.begin(), v.end(), greater<int>());
    for(vector<int>::iterator it=v.begin(); it!=v.end(); it++)
        cout << *it << ' ';
    cout << "\n";

    return 0;
}