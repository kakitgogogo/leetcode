#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
	int maximumGap(vector<int>& nums) 
	{
		int Max = INT_MIN, Min = INT_MAX, len = nums.size();
		if(nums.size() < 2) return 0;

		for(auto num:nums)
		{
			Max = max(Max, num);
			Min = min(Min, num);
		}

		int bucket_size = max(1, (Max - Min) / (len - 1));
		int bucket_num = (Max - Min) / bucket_size + 1;
		vector<int>bucket_cnt(bucket_num, 0);
		vector<int>bucket_max(bucket_num, INT_MIN);
		vector<int>bucket_min(bucket_num, INT_MAX);

		for(auto num:nums)
		{
			int bucket_id = (num - Min) / bucket_size;
			++bucket_cnt[bucket_id];
			bucket_min[bucket_id] = min(bucket_min[bucket_id], num);
			bucket_max[bucket_id] = max(bucket_max[bucket_id], num);
		}

		int pre = Min, res = 0;
		for(int i = 0; i < bucket_num; ++i)
		{
			if(bucket_cnt[i] > 0)
			{
				res = max(res, bucket_min[i] - pre);
				pre = bucket_max[i];
			}
		}
		return res;
	}
};

int main()
{
	vector<int>nums({1,10,5,7,18,21});
	Solution S;
	cout << S.maximumGap(nums) << endl;
}