//ʱ�䣺2018��5��22�����ڶ�20ʱ1��
//���ܣ���������

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
	
	cout << "������Ԫ�ظ���" << endl;
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

	INSERTION_SORT(A,count);

	cout << "���������Ľ��Ϊ��" << endl;

	for (int i = 0; i < count; ++i)
		cout << A[i] << " ";
	cout << endl;

	delete[]A;
	system("pause");
	return 0;
}