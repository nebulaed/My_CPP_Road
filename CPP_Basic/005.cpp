#include <iostream>
using namespace std;

int main()
{

    system("chcp 65001");

    //默认情况下输出一个小数，会显示6位有效数字

    float f1 = 3.14f; //加f的目的是让编译器认识到3.14是一个float变量，不加的话3.14会被认为是double，要多经过一个转换过程

    cout << "f1=" << f1 << endl;

    double d1 = 3.14;

    cout << "d1=" << d1 << endl;

    //统计float和double占用内存空间
    cout << "float占用内存空间为：" << sizeof(f1) << endl;
    cout << "double占用内存空间为：" << sizeof(d1) << endl;

    //科学计数法
    float f2 = 3e2f; //3*10^2
    cout << "f2=" << f2 << endl;

    float f3 = 3e-2f; //3*0.1^2
    cout << "f3=" << f3 << endl;

    system("pause");

    return 0;
}