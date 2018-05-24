//时间：2018年5月23日星期三15时16分
//功能：二分查找算法
//说明：输入一个数组，先用插入排序将其排序，在用二分查找法查找

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

bool Binary_Search(int* A,int count, int target)
{
	int i = 0;
	int j = count - 1;
	int mid;
	while (i <= j)
	{
		mid = (i + j) / 2;
		if (A[mid] == target)
			return true;
		else if (A[mid] > target)
			j = mid -1;
		else
			i = mid +1;
	}
	return false;
}

int main()
{
	int count;
	int target;
	cout << "请输入元素个数:" << endl;
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

	cout << "输入需要查找的值：" << endl;
	cin >> target;

	INSERTION_SORT(A, count);

	cout << "插入排序后的结果为：" << endl;

	for (int i = 0; i < count; ++i)
		cout << A[i] << " ";
	cout << endl;

	if (Binary_Search(A, count, target))
		cout << "数组中有此元素！！" << endl;
	else
		cout << "没有找到此元素！！" << endl;


	delete[]A;
	system("pause");
	return 0;
}

//结论：在二分查找时，在数组坐标start和end进行更新时，不要包含已包含的元素
//如，start = mid + 1;而不是start = mid;
//end = mid - 1;而不是end = mid;