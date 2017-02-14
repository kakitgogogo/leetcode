#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

class Solution
{
public:
	int reversePairs(vector<int>& nums) 
	{
		return merge_count(nums.begin(), nums.end());
	}
private:
	int merge_count(vector<int>::iterator begin, vector<int>::iterator end)
	{
		if(end - begin <= 1) return 0;
		auto mid = begin + (end - begin) / 2;
		int cnt = merge_count(begin, mid) + merge_count(mid, end);
		for(auto i = begin, j = mid; i != mid; ++i)
		{
			while(j != end && *i > 2L * *j)
			{
				++j;
			}
			cnt += (j - mid);
		}
		inplace_merge(begin, mid, end);
		return cnt;
	}
};

int main()
{
	Solution S;
	ifstream fin("input.txt");

	vector<int>nums({2147483647,2147483647,2147483647,2147483647,2147483647,2147483647});

	cout << S.reversePairs(nums) << endl;

	return 0;
}