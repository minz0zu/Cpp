#include <iostream>
using namespace std;
/*
1) ������: ��ü ������ �ڵ�ȣ��Ǿ� �ʱ�ȭ�� ���
2) ������ �̸��� Ŭ���� �̸��� ����, ���� Ÿ���� ����(������ void�� X)
3) ������ �����ε�(���� ��): �Ű����� ���°� �ٸ��� ���� �����ڸ� �� �� �ִ�.
4) � �����ڰ� ȣ��Ǵ� �� ������� Ȯ���Ѵ�.
*/
class Circle {
private:
    int radius; //��ȣ�� ���� (�ܺ� ���� ���� �Ұ�)
public:
    Circle(); // �⺻ ������
    Circle(int r); // �Ű������� �ִ� ������
    double getArea();
};
Circle::Circle() {
    radius = 1;
    cout << "�⺻������ ȣ�\n";
}

Circle::Circle(int r) {
    radius = r;
    cout << "�Ű����� �ִ� ������ ȣ��\n";
}

double Circle::getArea() {
    return 3.14159 * radius * radius;
};

int main(){
    Circle donut; // ��ü ����:Circle Ÿ���� �ν��Ͻ� donut ����
    cout << "Donut area: " << donut.getArea() << "\n";
    
    Circle pizza(10);
    cout << "Pizza area: " << pizza.getArea() << "\n";
    return 0;
}