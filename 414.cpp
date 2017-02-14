#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int thirdMax(vector<int>& nums) 
	{
		set<int> big3;
		for(auto num:nums)
		{
			big3.insert(num);
			if(big3.size() > 3)
			{
				big3.erase(big3.begin());
			}
		}
		return big3.size() == 3 ? *big3.begin() : *big3.rbegin();
	}
};

int main()
{
	Solution S;
	vector<int>nums({3,2,1});
	cout << S.thirdMax(nums) << endl;
}