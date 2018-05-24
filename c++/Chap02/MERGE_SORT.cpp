//时间：2018年5月22日星期二20时30分
//功能：归并排序，并且使用哨兵
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
	int *L = new int[n1 + 1];
	int *R = new int[n2 + 1];

	for (int i = 0; i < n1; ++i)
		L[i] = A[p + i];

	for (int i = 0; i < n2; ++i)
		R[i] = A[q + i + 1];

	L[n1] = INT_MAX;
	R[n2] = INT_MAX;

	int i = 0;
	int j = 0;

	for (int k = p; k <= r; ++k)
	{
		if (L[i] <= R[j])
		{
			A[k] = L[i];
			i++;
		}
		else
		{
			A[k] = R[j];
			j++;
		}
	}

	delete[]L;
	delete[]R;
}


int main()
{
	//int A[10] = { 3,5,9,3,4,24,34,5,2,6 };
	//int count = getarraylen(A);
	int count;
	int p = 0;
	int r;

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

	if ((p >= 0) && (p < count) && (r >= 0) && (r < count - 1) && (p <= r))
	{
		MERGE_SORT(A, p, r);
	}
	else
	{
		cout << "范围错误" << endl;
		system("pause");
		exit(0);
	}
		
	cout << "插入排序后的结果为：" << endl;

	for (int i = p; i <= r; ++i)
		cout << A[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}