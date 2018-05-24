//时间：2018年5月22日星期二20时1分
//功能：插入排序

#include <iostream>
#include <cstdlib>

using namespace std;

void INSERTION_SORT(int* A, int count)
{
	for (int j = 1; j < count; ++j)
	{
		int key = A[j];
		int i = j - 1;
		while ((i >= 0) && (A[i] > key))
		{
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = key;
	}
}

int main()
{
	int count;
	
	cout << "请输入元素个数" << endl;
	cin >> count;

	int* A = new int[count];
	for (int i = 0; i < count; ++i)
	{
		cout << "请输入第" << i << "个元素:" << endl;
		cin >> A[i];
	}
	cout << "所输入的数组为：" << endl;
	for (int i = 0; i < count; ++i)
		cout << A[i] << " ";
	cout << endl;

	INSERTION_SORT(A,count);

	cout << "插入排序后的结果为：" << endl;

	for (int i = 0; i < count; ++i)
		cout << A[i] << " ";
	cout << endl;

	delete[]A;
	system("pause");
	return 0;
}