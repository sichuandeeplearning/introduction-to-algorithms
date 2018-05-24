//ʱ�䣺2018��5��23��������15ʱ41��
//Ҫ������ʱ��Ϊn*lg(n),����n����������S����һ������x��ȷ��S���Ƿ����������͸պ�
//Ϊx��Ԫ�ص����꣬���������򷵻أ�0,0�������㷨���ۡ�2.3-7��Leetcode
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		std::map<int, int> nums_map;
		for (int i = 0; i < nums.size(); i++) {
			int comp = target - nums[i];
			if (nums_map.find(comp) != nums_map.end())
				return{ nums_map[comp], i };
			else
				nums_map[nums[i]] = i;
		}
		return{ 0, 0 };
	}
};

int main()
{
	Solution test;
	vector<int> number;
	vector<int> ans;
	number.push_back(3);
	number.push_back(2);
	number.push_back(4);
	int target = 6;

	ans = test.twoSum(number, target);
	for (auto i : ans)
		cout << i << " ";
	cout << endl;
	system("pause");
	return 0;
}
//���ۣ�����һ���յ�map�ͽṹ