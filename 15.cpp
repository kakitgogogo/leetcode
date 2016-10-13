class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size(),target=0;
        sort(nums.begin(),nums.end());
        vector<vector<int> >res;
        if(n<3) return res;
        for(int i=0;i<n-2;++i)
        {
        	if(i>0&&nums[i]==nums[i-1]) continue;
        	if(nums[i]+nums[i+1]+nums[i+2]>target) break;
        	if(nums[i]+nums[n-2]+nums[n-1]<target) continue;
        	int left=i+1,right=n-1;
        	while(left<right)
        	{
        		int sum=nums[i]+nums[left]+nums[right];
        		if(sum==target)
        		{
        			res.push_back(vector<int>{nums[i],nums[left],nums[right]});
        			++left;--right;
        			while(nums[left]==nums[left-1]) ++left;
        			while(nums[right]==nums[right+1]) --right;
        		}
        		else if(sum<target)
        		{
        			++left;
        			while(nums[left]==nums[left-1]) ++left;
        		}
        		else
        		{
        			--right;
        			while(nums[right]==nums[right+1]) --right;
        		}
        	}
        }
        return res;
    }
};
