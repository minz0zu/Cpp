#include <iostream>
using namespace std;
/* mcopy(T1, T2): 서로 다른 타입 배열 복사
- 템플릿 타입 2개 사용
T1: source 타입, T2: destination 타입
- dest[i] = (T2)src[i]로 캐스팅
*/
template <class T1, class T2>
void mcopy(T1 src[], T2 dest[], int n){
    for(int i =0; i<n; i++){
        dest[i] = (T2)src[i];
    }
}

int main() {
    int x[] = {1, 2, 3, 4, 5};
    double d[5];
    char c[5] {'h', 'e', 'l', 'l', 'o'}, e[5];
    
    
    mcopy(x, d, 5);
    mcopy(c, e, 5);
    for(int i =0 ; i<5; i++) cout << d[i] << ' ';
    cout << "\n";
    for(int i =0 ; i<5; i++) cout << e[i] << ' ';
    cout << "\n";
    return 0;

}