#include <iostream>
using namespace std;

// 值传递的时候，函数的形参发生改变，并不会影响实参
void swap(int num1,int num2)
{
    cout <<"交换前："<<endl;
    cout<<"num1="<<num1<<endl;
    cout<<"num2="<<num2<<endl;

    int temp = num1;
    num1 = num2;
    num2 = temp;

    cout <<"交换后："<<endl;
    cout<<"num1="<<num1<<endl;
    cout<<"num2="<<num2<<endl;
}

int main(){
    
    system("chcp 65001");

    int a = 0;
    int b = 1;

    cout <<"交换前："<<endl;
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;

    swap(a,b);

    cout <<"交换后："<<endl;
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
    
    system("pause");

    return 0;
}