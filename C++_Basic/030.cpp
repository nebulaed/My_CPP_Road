#include <iostream>
using namespace std;

int main(){
    
    // system("chcp 65001");

    // continue语句

    for (int i=0;i<=100;i++)
    {
        if (i%2==0)
        {
            continue;
        }
        cout<<i<<'\t';
    }
    
    system("pause");

    return 0;
}