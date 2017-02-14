#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	vector<string> restoreIpAddresses(string s)
	{
		string t;
		backTracking(s, t, 4);
		return res;
	}
private:
	vector<string> res;
	void backTracking(string s, string t, int n)
	{
		if(n == 0)
		{
			if(s.size() == 0)
			{
				res.push_back(t.substr(0, t.size()-1));
			}
			return;
		}
		if(s.size() > n * 3)
		{
			return;
		}
		if(s[0] == '0') 
		{
			backTracking(s.substr(1), t + "0.", n - 1);
			return;
		}
		for(int i = 1; i <= 3; ++i)
		{
			if(s.size() < i + n - 1 || stoi(s.substr(0, i)) > 255) return;
			backTracking(s.substr(i), t + s.substr(0, i) + ".", n - 1);
		}
	}
};



int main()
{
	Solution S;
	//vector<string>res = S.restoreIpAddresses("0000");
	//vector<string>res = S.restoreIpAddresses("010010");
	vector<string>res = S.restoreIpAddresses("25525511135");
	for(auto s:res)
	{
		cout << s << endl;
	}
}