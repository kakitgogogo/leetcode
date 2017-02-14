#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution 
{
public:
	int splitArray(vector<int>& nums, int m) 
	{
		int sum = 0, Max = 0;
		for(auto num:nums)
		{
			sum += num;
			Max = max(Max, num);
		}
		int l = Max, r = sum;
		while(l < r)
		{
			int mid = l + (r - l) / 2;
			bool b = isvalid(nums, m, mid);
			if(b)
			{
				r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}
		return isvalid(nums, m, l) ? l : l+1;
	}
private:
	bool isvalid(vector<int>& nums, int m, int d)
	{
		int sum = 0;
		for(auto num:nums)
		{
			if(sum + num > d)
			{
				--m;
				sum = 0;
			}
			if(m == 0) return false;
			sum += num;
		}
		return true;
	}
};

int main()
{
	Solution S;
	vector<int>nums({7,2,5,10,8});
	int m = 2;

	cout << S.splitArray(nums, m) << endl;

	return 0;
}