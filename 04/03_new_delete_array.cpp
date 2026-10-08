#include <iostream>
using namespace std;
/*
1) int *p = new int[n]; -> 힙에 int n개 (배열) 할당
2) 배열은 p[i]로 접근
3) 배열 반환 delete[] p; (대괄호 필수!!!)
*/
int main(){
    int n, sum = 0;
    cout << "How many integers? ";
    cin >> n;
    if (n <= 0) return 0;

    int *p = new int[n];    // 배열 동적 할당
    
    for(int i=0; i<n; i++){
        cin >> p[i];
    }

    sum = 0;
    for(int i=0; i<n; i++)
        sum+=p[i];

    cout << "avg = " << (double)sum/n << "\n";

    delete[] p;
    return 0;
}