
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

template<typename T>
int getarraylen(T& array)
{
	return (sizeof(array) / sizeof(array[0]));
}

class Data {
public:
	int left_i;
	int right_j;
	double sum;
};

Data FindMaxCrossingArray(double* a, int i, int mid, int j)
{
	int left = mid;
	int right = mid + 1;
	Data total;
	double left_sum = 0;
	double sum_l = 0;
	double right_sum = 0;
	double sum_r = 0;
	for (int k = mid; k >= i; k--)
	{
		sum_l += *(a + k);
		if (left_sum < sum_l)
		{
			left = k;
			left_sum = sum_l;
		}
	}
	for (int h = mid + 1; h <= j; h++)
	{
		sum_r += *(a + h);
		if (right_sum < sum_r)
		{
			right = h;
			right_sum = sum_r;
		}
	}
	total.left_i = left;
	total.right_j = right;
	total.sum = sum_l + sum_r;
	return total;
}

Data FindMaximumSubarray(double* a, int low, int high)
{
	Data summ;
	Data sum_l;
	Data sum_r;
	Data sum_m;
	if (high < low)
	{
		cout << "下标顺序错误!" << endl;
		exit(0);
	}
	if (high == low)
	{
		summ.left_i = low;
		summ.right_j = high;
		summ.sum = *(a + low);
		return summ;
	}
	else
	{
		int mid = int((high + low) / 2);
		sum_l = FindMaximumSubarray(a, low, mid);
		sum_r = FindMaximumSubarray(a, mid + 1, high);
		sum_m = FindMaxCrossingArray(a, low, mid, high);
		if ((sum_l.sum > sum_r.sum) && (sum_l.sum > sum_m.sum))
			return sum_l;
		else if ((sum_r.sum > sum_l.sum) && (sum_r.sum > sum_m.sum))
			return sum_r;
		else
			return sum_m;
	}
}

int main()
{
	cout << "此程序是实现《算法导论》中求最大子数组的算法" << endl;
	int count;
	//double a[10] = { 1,2,5,-4,5,1,2,-4,2,3 };
	//double a[4] = { 1,-4,3,-4 };
	cout << "请输入元素个数" << endl;
	cin >> count;

	double* a = new double[count];
	for (int i = 0; i < count; ++i)
	{
		cout << "请输入第" << i << "个元素:" << endl;
		cin >> a[i];
	}
	cout << "所输入的数组为：" << endl;
	for (int i = 0; i < count; ++i)
		cout << a[i] << " ";
	cout << endl;
	
	
	Data total_crossing;
	/*if (getarraylen(a) == 0)
	{
		cout << "此数组为空，请输入一个非空数组" << endl;
		system("pause");
		exit(0);
	}*/
	total_crossing = FindMaximumSubarray(a, 0, count - 1);
	if (total_crossing.left_i == total_crossing.right_j)
		cout << "There is only one element in Subarray:low = right =" << total_crossing.left_i << ". The maximum sum is: " << total_crossing.sum << endl;
	else
		cout << "low: " << total_crossing.left_i << ", right: " << total_crossing.right_j << ", sum: " << total_crossing.sum << endl;
	
	
	system("pause");
	return 0;
}