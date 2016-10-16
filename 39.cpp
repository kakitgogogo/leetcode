class Solution
{
public:
	vector<vector<int> > combinationSum(vector<int>& candidate,int target)
	{
		if(candidate.empty()) return res;
		sort(candidate.begin(),candidate.end());
		auto endp=unique(candidate.begin(),candidate.end());
		candidate.erase(endp,candidate.end());
		n=candidate.size();
		vector<int>path;
		dfs(candidate,target,0,0,path);
		return res;
	}
private:
	vector<vector<int> >res;
	int n;
	void dfs(vector<int>&candidate,int target,int cur,int sum,vector<int>path)
	{
		if(sum==target)
		{
			res.push_back(path);
			return;
		}
		if(cur==n) 
		{
			return;
		}
		if(sum>target)
		{
			return;
		}
		dfs(candidate,target,cur+1,sum,path);
		for(int i=1;;i++)
		{
			sum+=candidate[cur];
			if(sum>target) return;
			path.push_back(candidate[cur]);
			dfs(candidate,target,cur+1,sum,path);
		}
	}
};
