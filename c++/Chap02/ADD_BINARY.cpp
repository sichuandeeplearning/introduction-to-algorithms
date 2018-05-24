//时间：2018年5月22日星期二20时20分
//功能：实现两个n位二进制数的加法，将结果存在n+1位数组中
//说明：《算法导论》2.1-4
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int count;

	cout << "请第一个数组的输入元素个数" << endl;
	cin >> count;

	int* A = new int[count];
	for (int i = 0; i < count; ++i)
	{
		cout << "请输入第" << i << "个元素:" << endl;
		cin >> A[i];
	}
	cout << "所输入的数组为：" << endl;
	for (int i = count-1; i >=0; --i)
		cout << A[i] << " ";
	cout << endl;

	cout << "请第二个数组的输入元素个数" << endl;
	cin >> count;

	int* B = new int[count];
	for (int i = 0; i < count; ++i)
	{
		cout << "请输入第" << i << "个元素:" << endl;
		cin >> B[i];
	}
	cout << "所输入的数组为：" << endl;
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

	cout << "相加后的结果为：" << endl;
	for (int j = count; j >= 0; --j)
		cout << C[j] << " ";
	cout << endl;


	delete[]A;
	delete[]B;
	delete[]C;
	system("pause");
	return 0;
}