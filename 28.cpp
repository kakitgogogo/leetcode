class Solution {
public:
vector<int> gain_next(string s)
{
	int n=s.size();
	vector<int>next(n);
	int cur,back;
	next[0]=0;
	for(cur=1;cur<n;cur++)
	{
		back=next[cur-1];
		while(back>0&&s[cur]!=s[back])
		{
			back=next[back-1];
		}
		if(s[cur]==s[back]) back++;
		next[cur]=back;
	} 
    return next;
}

int strStr(string s, string t) {
	int n=s.size(),m=t.size();
	if(m==0) return 0;
	if(n<m) return -1;
	vector<int>next;
	next=gain_next(t);
	int i=0,j=0;
	while(i<n&&j<m)
	{
		if(s[i]==t[j]) 
		{
			i++;
			j++;
		}
		else 
		{
			if(j==0) i++;
			else j=next[j-1];
		}
	}
	if(j==m) return i-j; 
	else return -1;         
    }
};
