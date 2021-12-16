#include <iostream>
using namespace std;

int add(int num1,int num2)
{
    int sum = num1 + num2;
    return sum;
}

int main(){
    
    system("chcp 65001");

    int a = 10;
    int b = 20;

    int c = add(a,b);

    cout <<"c="<<c<<endl;
    
    system("pause");

    return 0;
}