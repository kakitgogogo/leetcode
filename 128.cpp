#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
	int longestConsecutive(vector<int>& nums)
	{
		int res = 0;
		unordered_set<int> umap(nums.begin(), nums.end());
		for(auto num:nums)
		{
			if(umap.find(num) == umap.end()) continue;
			int tmp = num - 1, cnt = 1;
			while(umap.find(tmp) != umap.end()) 
			{
				umap.erase(tmp--);
				++cnt;
			}
			tmp = num + 1;
			while(umap.find(tmp) != umap.end()) 
			{
				umap.erase(tmp++);
				++cnt;
			}
			res = max(res, cnt);
		}
		return res;
	}
};

int main()
{
	Solution S;
	ifstream fin("input.txt");

	vector<int>nums({100,4,200,1,3,2});

	cout << S.longestConsecutive(nums) << endl;

	return 0;
}