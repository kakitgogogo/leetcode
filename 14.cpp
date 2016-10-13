class Solution {
public:
string longestCommonPrefix(vector<string>& strs)
{
    string res;
    if(strs.empty()) return res;
	int n=strs.size();
	res=strs[0];
	int r=res.size();
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<r;j++)
		{
			if(res[j]!=strs[i][j])
			{
				r=j;
				break;
			}
		}
	}
	return res.substr(0,r);
}
};
