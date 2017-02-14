#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<pair<int, int> > reconstructQueue(vector<pair<int, int> >& people) 
	{
		auto cmp = [](const pair<int, int> &p1, const pair<int, int> &p2)
		{
			return (p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second));
		};
		sort(people.begin(), people.end(), cmp);
		vector<pair<int, int> >res;
		for(auto& p:people)
		{
			res.insert(res.begin() + p.second, p);
		}
		return res;
	}
};

int main()
{
	int n;
	cin >> n;
	vector<pair<int, int> >people(n);
	for(auto& p:people)
	{
		cin >> p.first >> p.second;
	}
	Solution S;
	vector<pair<int, int> >res = S.reconstructQueue(people);
	for(auto& r:res)
	{
		cout << r.first << " " << r.second << endl;
	}
}