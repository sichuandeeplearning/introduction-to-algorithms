//ʱ�䣺2018��5��22�����ڶ�21ʱ48��
//���ܣ���������
//˵������������ĵݹ�汾�����㷨���ۡ�2.3-5

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

	INSERTION_SORT(A, count);

	cout << "���������Ľ��Ϊ��" << endl;

	for (int i = 0; i < count; ++i)
		cout << A[i] << " ";
	cout << endl;

	delete[]A;
	system("pause");
	return 0;
}
//�ݹ��ѭ����ʱ���Ի���ת����ѭ�������ṹ��͵ݹ�����ṹ����һ����