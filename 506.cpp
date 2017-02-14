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
	vector<string> findRelativeRanks(vector<int>& nums)
	{
		vector<pair<int, int> > vec;
		vector<string> res(nums.size());
		string ranks[3] = {"Gold Medal", "Silver Medal", "Bronze Medal"};

		for(int i = 0; i < nums.size(); ++i) 
			vec.push_back(pair<int, int>(i, nums[i]));
		auto cmp = [](const pair<int, int>& p1, const pair<int, int>& p2) { return p1.second > p2.second; };
		sort(vec.begin(), vec.end(), cmp);

		for(int i = 0; i < nums.size(); ++i)
		{
			if(i < 3) res[vec[i].first] = ranks[i];
			else res[vec[i].first] = to_string(i+1);
		}
		return res;
	}
};

int main()
{
	Solution S;
	ifstream fin("input.txt");

	int n;
	cin >> n;
	vector<int> nums(n);
	for(auto& num:nums) cin >> num;

	vector<string> res = S.findRelativeRanks(nums);

	for(auto r:res) cout << r << endl;

	return 0;
}