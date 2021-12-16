#include<iostream>
using namespace std;

// ʵ��ͨ�� �������������ĺ���
// ����Ӵ�С
// �㷨 ѡ������
// ���� char���顢int����

// ��������ģ��
template<class T>
void swapvalue(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

// �����㷨
template<class T>
void sortArray(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i; // �϶����ֵ���±�
		for (int j = i + 1; j < len; j++)
		{
			// �϶������ֵ �� ����������ֵ ҪС��˵��j�±��Ԫ�ز������������ֵ
			if (arr[max] < arr[j])
			{
				max = j; // �������ֵ�±�
			}
		}
		if (max != i)
		{
			// ����max��iԪ��
			swapvalue(arr[max], arr[i]);
		}
	}
}

// �ṩ��ӡ����ģ��
template<class T>
void printArray(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}


void test01()
{
	// ����char����
	char charArr[] = "badcfe";
	int len = sizeof(charArr) / sizeof(char);
	printArray(charArr, len);
	sortArray(charArr, len);
	printArray(charArr, len);
}

void test02()
{
	// ����int����
	int intArr[] = { 5,8,3,9,2,0,1,7,4,6 };
	int len = sizeof(intArr) / sizeof(int);
	printArray(intArr, len);
	sortArray(intArr, len);
	printArray(intArr, len);
}

int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}