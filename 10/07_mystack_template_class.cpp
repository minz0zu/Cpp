#include <iostream>
using namespace std;

/*
    템플릿 클래스 MyStack<T>
    정의 시:template <class T> class MyStack{~~~~}
    사용할 때: MyStack<int> / Mystack<double>처럼 타입을 지정해야 함
*/

template <class T>
class MyStack{
    int tos;
    T data[100];
public:
    MyStack() : tos(-1) {}
    void push(T element){
        if(tos ==99) {
            cout << "stack full \n";
            return;
        }
        data[++tos] = element;


    }

    T pop(){
        if(tos ==-1){
            T tmp;
            cout << "stack empty\n";
            return tmp; //return T();
        }
        return data[tos--];
    }

};

int main(){
    MyStack<int> iStack;
    iStack.push(3);
    cout << iStack.pop() << "\n";

    MyStack<double> dStack;
    dStack.push(1.1);
    dStack.push(3.1);
    cout << dStack.pop() << "\n";

    MyStack<char>* p = new MyStack<char>();
    p->push('a'); p->push('b');
    cout<< p->pop() << "\n";
    delete p;

    return 0;
}