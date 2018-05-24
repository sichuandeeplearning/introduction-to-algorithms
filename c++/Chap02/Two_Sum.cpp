//时间：2018年5月23日星期三15时41分
//要求：运行时间为n*lg(n),给定n个整数集合S和另一个整数x，确定S中是否存在两个其和刚好
//为x的元素的坐标，若不存在则返回（0,0），《算法导论》2.3-7和Leetcode
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
//结论：运用一个空的map型结构