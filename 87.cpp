#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	bool isScramble(string s1, string s2)
	{
		if(s1 == s2) return true;
		int n1 = s1.size(), n2 = s2.size();
		if(n1 != n2) return false;

		int cnt[256] = {0};
		for(int i = 0; i < n1; ++i)
		{
			++cnt[s1[i]];
			--cnt[s2[i]];
		}
		for(int i = 0; i < 256; ++i)
		{
			if(cnt[i] != 0)
			{
				return false;
			}
		}

		for(int i = 1; i < n1; ++i)
		{
			if((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) 
				|| (isScramble(s1.substr(0, i), s2.substr(n2 - i)) && isScramble(s1.substr(i), s2.substr(0, n2 - i))) )
			{
				return true;
			}
		}
		return false;
	}
};

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	Solution S;
	cout.setf(ios_base::boolalpha);
	cout << S.isScramble(s1, s2) << endl;
}