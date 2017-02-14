#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <functional>
using namespace std;

class Solution
{
public:
	bool makesquare(vector<int>& nums) 
	{
		int n = nums.size();
		if(n < 4) return false;

		sum = accumulate(nums.begin(), nums.end(), 0);
		if(sum % 4 != 0) return false;

		len = sum / 4;
		sort(nums.begin(), nums.end(), greater<int>());

		vector<int>curlen(4, 0);
		res = false;
		dfs(nums, curlen, 0);
		return res;
	}
private:
	int sum, len;
	bool res;
	void dfs(vector<int>& nums, vector<int>& curlen, int idx)
	{
		if(res == true) return;
		if(idx == nums.size())
		{
			if(curlen[0] == len && curlen[1] == len && curlen[2] == len)
			{
				res = true;
			}
			return;
		}
		for(int i = 0; i < 4; ++i)
		{
			if(curlen[i] + nums[idx] > len) continue;
			curlen[i] += nums[idx];
			dfs(nums, curlen, idx + 1);
			curlen[i] -= nums[idx];
		}

	}
};

int main()
{
	Solution S;
	ifstream fin("input.txt");

	//vector<int>nums({1,1,2,2,2});
	vector<int>nums({4,4,4,4,6,6,6,6,2,2,2,2,4,4,8});

	cout.setf(ios_base::boolalpha);
	cout << S.makesquare(nums) << endl; 

	return 0;
}