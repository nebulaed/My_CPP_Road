#include<iostream>
#include<list>
using namespace std;

// list���� ���ݴ�ȡ
void test01()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	// list��֧��[]��at����Ԫ�أ�ԭ����list�������������������������Կռ�洢���ݣ�������Ҳ�ǲ�֧��������ʵ�

	cout << "��һ��Ԫ��Ϊ��" << L1.front() << endl;
	cout << "���һ��Ԫ��Ϊ��" << L1.back() << endl;

	// ��֤�������ǲ�֧��������ʵ�
	list<int>::iterator it = L1.begin();

	// listֻ֧�ֵ�����++��--����֧��+1��+2��+3�Ȼ�-1��-2��-3��
}

int main()
{
	test01();
	system("pause");
	return 0;
}