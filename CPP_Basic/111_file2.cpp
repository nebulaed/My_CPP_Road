#include<iostream>
#include<fstream>
#include<string>
using namespace std;

// 文本文件 读文件
void test01()
{
	// 1、包含头文件
	// 2、创建流对象
	ifstream ifs;

	// 3、打开文件 并且判断是否打开成功
	ifs.open("test.txt", ios::in);

	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	// 4、读数据

	// 第一种
	//char buf[1024] = { 0 };
	//while (ifs >> buf) // 当ifs中的数据全部放到buf中后，ifs>>buf会返回false
	//{
	//	cout << buf << endl;
	//}

	// 第二种
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf, sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}

	// 第三种
	//string buf;
	//while (getline(ifs, buf))
	//{
	//	cout << buf << endl;
	//}

	//第四种(不推荐，逐个字节读，效率低)
	char c;
	while ((c = ifs.get()) != EOF) // EOF: end of file，文件尾
	{
		cout << c;
	}

	// 5、关闭文件
	ifs.close();
}

int main()
{
	test01();

	system("pause");

	return 0;
}