//ʱ�䣺2018��5��23��������15ʱ16��
//���ܣ����ֲ����㷨
//˵��������һ�����飬���ò����������������ö��ֲ��ҷ�����

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
	cout << "������Ԫ�ظ���:" << endl;
	cin >> count;

	int* A = new int[count];
	for (int i = 0; i < count; ++i)
	{
		cout << "�������" << i << "��Ԫ��:" << endl;
		cin >> A[i];
	}
	cout << "�����������Ϊ��" << endl;
	for (int i = 0; i < count; ++i)
		cout << A[i] << " ";
	cout << endl;

	cout << "������Ҫ���ҵ�ֵ��" << endl;
	cin >> target;

	INSERTION_SORT(A, count);

	cout << "���������Ľ��Ϊ��" << endl;

	for (int i = 0; i < count; ++i)
		cout << A[i] << " ";
	cout << endl;

	if (Binary_Search(A, count, target))
		cout << "�������д�Ԫ�أ���" << endl;
	else
		cout << "û���ҵ���Ԫ�أ���" << endl;


	delete[]A;
	system("pause");
	return 0;
}

//���ۣ��ڶ��ֲ���ʱ������������start��end���и���ʱ����Ҫ�����Ѱ�����Ԫ��
//�磬start = mid + 1;������start = mid;
//end = mid - 1;������end = mid;