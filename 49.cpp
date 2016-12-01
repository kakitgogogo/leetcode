class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs)
{
	int n=strs.size();
	vector<vector<string> >res;
	unordered_map<string,multiset<string> >m;
	for(int i=0;i<n;i++)
	{
		string tmp=strs[i];
		sort(tmp.begin(),tmp.end());
		m[tmp].insert(strs[i]);
	} 
	unordered_map<string,multiset<string> >::iterator it;
	for(it=m.begin();it!=m.end();it++)
	{
		vector<string>vec((*it).second.begin(),(*it).second.end());
		res.push_back(vec);
	}
	return res;
}
};
