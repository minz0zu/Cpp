#include <iostream>
using namespace std;
/*  참조가 "별명"임을 확인
1) 참조는 반드시 초기화해야 하며, 원본과 주소가 같다.
*/
bool average(int a[], int size, int &avg){
    int sum = 0;
    if (size <= 0) return false;
    for (int i=0; i<size; i++)
        sum += a[i];
    avg = sum / size;
    return true;
}

int main(){
    int n = 1;
    int &refn = n;
    refn = 2;
    refn++;
    cout << "n=" << n << " refn=" << refn << "\n";

    int *p = &refn; // 결국 n의 주소
    *p = 20;
    cout << "n=" << n << " refn=" << refn << "\n";

    int x[] = {1, 2, 3, 4, 5};
    int avg;

    if(average(x, -2, avg)) cout << "avg=" << avg << "\n";
    else cout << "error\n";

    return 0;
}