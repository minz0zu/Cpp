#include <iostream>
using namespace std;

template <class T>
void myswap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

int main(){
	int a=1, b=2;
	myswap(a, b);

	double c=0.1, d=0.12;
	myswap(c, d)

	return 0;
}