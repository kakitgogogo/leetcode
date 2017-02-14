#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <stack>
#include <map>
using namespace std;

class Solution
{
public:
	vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) 
	{
		vector<int> res(findNums.size());
		stack<int> stk;
		map<int, int> res_map;

		for(auto num:nums)
		{
			res_map[num] = -1;
			while(!stk.empty() && stk.top() < num)
			{
				res_map[stk.top()] = num;
				stk.pop();
			}
			stk.push(num);
		}

		for(int i = 0; i < res.size(); ++i)
		{
			res[i] = res_map[findNums[i]];
		}

		return res;
	}
};

int main()
{
	Solution S;
	ifstream fin("input.txt");

	vector<int> findNums({4,1,2});
	vector<int> nums({1,3,4,2});

	vector<int> res = S.nextGreaterElement(findNums, nums);

	for(auto item : res)
	{
		cout << item << endl;
	}

	return 0;
}