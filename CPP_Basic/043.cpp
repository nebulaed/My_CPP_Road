#include <iostream>
using namespace std;

int main(){
    
    system("chcp 65001");

    // 在32位操作系统下：占用4个字节空间，64位下占8个字节。

    int a = 10;
    int *p = &a;

    // 指针占用内存空间与数据类型无关，因为存放的都是16位数
    cout << "sizeof (int *) ="<<sizeof(int *)<<endl;
    cout << "sizeof (int *) ="<<sizeof(p)<<endl;
    cout << "sizeof (int *) ="<<sizeof(float *)<<endl;
    cout << "sizeof (int *) ="<<sizeof(double *)<<endl;
    cout << "sizeof (int *) ="<<sizeof(char *)<<endl;
    
    system("pause");

    return 0;
}