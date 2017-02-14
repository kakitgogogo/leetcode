#include<iostream>
#include<set>
#include <tr1/unordered_map>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
using namespace std::tr1;

vector<int> topKFrequent(vector<int>& nums, int k)
{
	vector<int>res;
	unordered_map<int,int>m;
	for(int i=0;i<nums.size();i++) m[nums[i]]++;
	unordered_map<int,int>::iterator it;
	priority_queue<pair<int,int> >q;
	for(it =m.begin();it!=m.end();it++)
	{
		q.push(make_pair(it->second,it->first) );
		if(q.size()>(int)m.size()-k)
		{
			res.push_back(q.top().second);
			q.pop();
		}
	}
	return res;
}

int main()
{
	int n,k;
	cin>>n>>k;
	vector<int>a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector<int>res;
	res=topKFrequent(a,k);
	for(int i=0;i<k;i++) cout<<res[i]<<endl;
}