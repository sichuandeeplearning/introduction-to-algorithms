//时间：2018年5月22日星期二21时1分
//归并排序且不使用哨兵
//改进后的分治算法：在归并阶段，子数组不多留一位来存放哨兵，即一个子数组归并
//完以后，直接将另一个子数组复制到原数组里面去。

#include <iostream>
#include <cstdlib>

using namespace std;

void MERGE_SORT(int* A, int p, int r);
void MERGE(int* A, int p, int q, int r);

template<typename T>
int getarraylen(T& array)
{
	return (sizeof(array) / sizeof(array[0]));
}

void MERGE_SORT(int* A, int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		MERGE_SORT(A, p, q);
		MERGE_SORT(A, q + 1, r);
		MERGE(A, p, q, r);
	}
}

void MERGE(int* A, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int *L = new int[n1];
	int *R = new int[n2];

	for (int i = 0; i < n1; ++i)
		L[i] = A[p + i];

	for (int i = 0; i < n2; ++i)
		R[i] = A[q + i + 1];

	for (int m = 0; m < n1; ++m)
		cout << L[m] << " ";
	cout << endl;

	for (int m = 0; m < n2; ++m)
		cout << R[m] << " ";
	cout << endl;

	int i = 0;
	int j = 0;

	for (int k = p; k <= r; ++k)
	{
		if (i ==n1)
		{
			A[k] = R[j];
			j++;
			continue;
		}
		else if (j == n2)
		{
			A[k] = R[i];
			i++;
			continue;
		}
		else if (L[i] <= R[j])
		{
			A[k] = L[i];
			i++;
		}
		else if(L[i] > R[j])
		{
			A[k] = R[j];
			j++;
		}
		cout << A[k] << endl;
	}

	delete[]L;
	delete[]R;
}


int main()
{
	//int A[10] = { 3,5,9,3,4,24,34,5,2,6 };
	//int count = getarraylen(A);
	//int A[6] = { 5,2,6,3,9,4 };
	int count = 6;
	int p = 0;
	int r = count -1;

	cout << "请输入元素个数" << endl;
	cin >> count;
	r = count - 1;

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

	cout << "请输入要排序的范围" << endl;
	cin >> p >> r;
	p--;
	r--;

	if ((p >= 0) && (p <= count) && (r >= 0) && (r <= count) && (p <= r))
	{
		MERGE_SORT(A, p, r);
	}
	else
	{
		cout << "范围错误" << endl;
		system("pause");
		exit(0);
	}

	cout << "分治排序后的结果为：" << endl;

	for (int i = p; i <= r; ++i)
		cout << A[i] << " ";
	cout << endl;


	system("pause");
	return 0;
}
//结论：增加两个判断语句来实现所要求的功能