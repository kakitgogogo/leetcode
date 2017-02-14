#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class Solution 
{
public:
	string licenseKeyFormatting(string S, int K) 
	{
		string res, tmp;
		if(S.empty()) return res; 
		for(auto &c:S)
		{
			if(c != '-')
			{
				tmp += toupper(c);
			}
		}
		int cnt = tmp.size(), i = cnt % K;
		res = tmp.substr(0, i);
		for(int j = 0; j < cnt / K; ++j)
		{
			if(i != 0) res += '-';
			res += tmp.substr(i, K);
			i += K;
		}
		return res;
	}
};

int main()
{
	string s;
	int k;

	cin >> s >> k;
	Solution S;
	cout << S.licenseKeyFormatting(s, k) << endl;
}