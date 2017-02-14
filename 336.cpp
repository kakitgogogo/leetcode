#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<vector<int> > palindromePairs(vector<string>& words)
	{
		map<string, int> Map;
		vector<vector<int> >res;

		for(int i = 0; i < words.size(); ++i)
		{
			Map[reverse(words[i])] = i;
		}
		for(int i = 0; i < words.size(); ++i)
		{
			for(int k = 0; k <= words[i].size(); ++k)
			{
				string ss = words[i].substr(0, k);
				int n = words[i].size();
				if(k != n && Map.find(ss) != Map.end() && isPalindrome(words[i], k, n))
				{
					if(i != Map[ss]) 
						res.push_back(vector<int>({i, Map[ss]}));
				}

				ss = words[i].substr(k);
				if(Map.find(ss) != Map.end() && isPalindrome(words[i], 0, k))
				{
					if(i != Map[ss]) 
						res.push_back(vector<int>({Map[ss], i}));
				}
			}
		}
		return res;
	}
private:
	string reverse(const string& s)
	{
		string t = s;
		::reverse(t.begin(), t.end());
		return t;
	}
	bool isPalindrome(const string& s, int l, int r)
	{
		--r;
		while(l < r)
		{
			if(s[l++] != s[r--]) return false;
		}
		return true;
	}
};

int main()
{
	Solution S;
	//vector<string> words({"bat", "tab", "cat"});
	vector<string> words({"abcd", "dcba", "lls", "s", "sssll"});
	vector<vector<int> > res = S.palindromePairs(words);

	for(auto vec:res)
	{
		for(auto item:vec)
		{
			cout << item << " ";
		}
		cout << endl;
	}

	return 0;
}