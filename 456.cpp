#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

class Solution
{
public:
	bool find132pattern(vector<int>& nums)
	{
		int n = nums.size();
		if(n < 3) return false;
		stack<int>stk;
		int n3 = INT_MIN;
		for(int i = n - 1; i >= 0; --i)
		{
			if(nums[i] < n3)
			{
				return true;
			}
			while(!stk.empty() && nums[i] > stk.top())
			{
				n3 = stk.top();
				stk.pop();
			}
			stk.push(nums[i]);
		}
		return false;
	}
};

int main()
{
	Solution S;
	//vector<int> nums({1, 2, 3, 4});
	//vector<int> nums({3, 1, 4, 2});
	vector<int> nums({-1, 3, 2, 0});
	cout.setf(ios_base::boolalpha);
	cout << S.find132pattern(nums) << endl;
}