//ʱ�䣺2018��5��22�����ڶ�20ʱ20��
//���ܣ�ʵ������nλ���������ļӷ������������n+1λ������
//˵�������㷨���ۡ�2.1-4
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int count;

	cout << "���һ�����������Ԫ�ظ���" << endl;
	cin >> count;

	int* A = new int[count];
	for (int i = 0; i < count; ++i)
	{
		cout << "�������" << i << "��Ԫ��:" << endl;
		cin >> A[i];
	}
	cout << "�����������Ϊ��" << endl;
	for (int i = count-1; i >=0; --i)
		cout << A[i] << " ";
	cout << endl;

	cout << "��ڶ������������Ԫ�ظ���" << endl;
	cin >> count;

	int* B = new int[count];
	for (int i = 0; i < count; ++i)
	{
		cout << "�������" << i << "��Ԫ��:" << endl;
		cin >> B[i];
	}
	cout << "�����������Ϊ��" << endl;
	for (int i = count - 1; i >= 0; --i)
		cout << B[i] << " ";
	cout << endl;

	int* C = new int[count + 1];
	int carry = 0;
	int k = 0;

	for (; k < count; ++k)
	{
		C[k] = (A[k] + B[k] + carry) % 2;
		carry = (A[k] + B[k] + carry) / 2;
	}
	C[k] = carry;

	cout << "��Ӻ�Ľ��Ϊ��" << endl;
	for (int j = count; j >= 0; --j)
		cout << C[j] << " ";
	cout << endl;


	delete[]A;
	delete[]B;
	delete[]C;
	system("pause");
	return 0;
}