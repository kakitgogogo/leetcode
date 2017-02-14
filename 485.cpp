#include <iostream>
#include <vector>
using namespace std;

class Solution1
{
public:
	int findMaxConsecutiveOnes(vector<int>& nums)
	{
		int Max = 0, cnt = 0;
		for(auto n:nums)
		{
			if(n == 1)
			{
				++cnt;
			}
			else
			{
				Max = max(Max, cnt);
				cnt = 0;
			}
		}
		Max = max(Max, cnt);
		return Max;
	}
};

class Solution
{
public:
	int findMaxConsecutiveOnes(vector<int>& nums)
	{
		int Max = 0, cnt = 0;
		for(auto n:nums)
		{
			cnt = (cnt + 1) * n;
			Max = max(Max, cnt);
		}
		return Max;
	}
};

int main()
{
	vector<int>nums({1,1,0,1,1,1});
	Solution S;
	cout << S.findMaxConsecutiveOnes(nums) << endl;
}