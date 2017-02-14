#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	void sortColors(vector<int>& nums)
	{
		int color[3] = {0}, idx = 0;
		for(auto num:nums)
		{
			++color[num];
		}
		for(int i = 0; i < 3; ++i)
		{
			for(int j = 0; j < color[i]; ++j)
			{
				nums[idx++] = i;
			}
		}
	}
};

int main()
{
	vector<int>nums({0,1,2,1,0,1,2});
	Solution S;
	S.sortColors(nums);
	for(auto num:nums)
	{
		cout << num << endl;
	}
}