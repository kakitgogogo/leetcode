#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Solution {
public:
	bool isSubsequence(string s, string t)
	{
		if(s.empty()) return true;
		int i = 0, l = s.size();
		for(auto& c:t)
		{
			if(s[i] == c)
			{
				++i;
			}
			if(i == l)
			{
				return true;
			}
		}
		return false;
	}
};

int main()
{
	string s, t;
	cin >> s >> t;
	Solution S;
	cout.setf(ios_base::boolalpha);
	cout << S.isSubsequence(s, t) << endl;
}