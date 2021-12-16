#include <iostream>
using namespace std;

void swap1(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swap2(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main(){
    
    system("chcp 65001");

    // 指针和函数
    // 1. 值传递
    int a = 10;
    int b = 20;
    swap1(a,b);

    cout <<"a="<<a<<endl;
    cout <<"b="<<b<<endl;
    // 2.地址传递
    swap2(&a,&b);
    cout <<"a="<<a<<endl;
    cout <<"b="<<b<<endl;
    
    system("pause");

    return 0;
}