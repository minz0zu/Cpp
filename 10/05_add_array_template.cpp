#include <iostream>
using namespace std;
/*
    T add(~~~)
*/
template <class T>
T add(T data[], int n){
    T sum = 0;

    for (int i = 0; i< n; i++){
        sum += data[i];
    }
    return sum ;
}

int main() {
    int x[] = {1, 2, 3, 4, 5};
    double d[] = {1.2, 2.2, 3.2, 4.2, 5.2};
    cout << add(x, 5) << "\n";
    cout << add(d, 5) << "\n";

    return 0;
}