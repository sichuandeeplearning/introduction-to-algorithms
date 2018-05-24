//时间：2018年5月22日星期二21时48分
//功能：插入排序
//说明：插入排序的递归版本，《算法导论》2.3-5

#include <iostream>
#include <cstdlib>

using namespace std;

void INSERTION_SORT(int* A, int count)
{
	if (count > 1)
	{
		INSERTION_SORT(A, count - 1);
		int key = A[count - 1];
		int i = count - 2;
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

	INSERTION_SORT(A, count);

	cout << "插入排序后的结果为：" << endl;

	for (int i = 0; i < count; ++i)
		cout << A[i] << " ";
	cout << endl;

	delete[]A;
	system("pause");
	return 0;
}
//递归和循环有时可以互相转换，循环的主结构体和递归的主结构体是一样的