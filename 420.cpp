#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int strongPasswordChecker(string s)
	{
		int needUpper = 1, needLower = 1, needDigit = 1;
		vector<int>repeat;
		int cnt = 1, n = s.size(), needs = 0 ,chRepeat = 0;

		if(n == 0) return 6;

		for(int i = 0; i < n; ++i)
		{
			if(isupper(s[i])) needUpper = 0;
			if(islower(s[i])) needLower = 0;
			if(isdigit(s[i])) needDigit = 0;

			if(i == 0) continue;

			if(s[i] == s[i - 1])
			{
				++cnt;
			}
			else
			{
				if(cnt >= 3)
				{
					chRepeat += cnt / 3;
					repeat.push_back(cnt);
				}
				cnt = 1;
			}
		}
		if(cnt >= 3)
		{
			chRepeat += cnt / 3;
			repeat.push_back(cnt);
		}
		needs = needUpper + needLower + needDigit;

		if(n < 6)
		{
			return max(6 - n, max(chRepeat, needs));
		}
		else if(n <= 20)
		{
			return max(needs, chRepeat);
		} 
		else
		{
			int r = n - 20;
			chRepeat = 0;
			auto cmp = [](const int n1, const int n2){return (n1 % 3) < (n2 % 3);};
			sort(repeat.begin(), repeat.end(), cmp);

			for(int i = 0; i < repeat.size(); ++i)
			{
				if(repeat[i] % 3 == 2) break;
				int tmp = (repeat[i] % 3) + 1;
				if(r >= tmp) 
				{
					repeat[i] -= tmp;
					r -= tmp;
				}
				else
				{
					repeat[i] -= r;
					r = 0;
					break;
				}
			}
			for(int i = 0; i < repeat.size(); ++i)
			{
				int tmp = ((repeat[i] - 2) / 3) * 3;
				if(r != 0 && r >= tmp) 
				{
					r -= tmp;
				}
				else
				{
					chRepeat += (repeat[i] - r) / 3;
					r = 0;
				}
			}
			return n - 20 + max(needs, chRepeat);
		}
	}
};

int main()
{
	//string s = "ABABABABABABABABABAB1";
	//string s = "1234567890123456Baaaaa";
	string s = "aaaabbaaabbaaa123456A";
	//string s = "AAAAAABBBBBB123456789a";
	//string s = "hoAISJDBVWD09232UHJEPODKNLADU1";
	cout << s.size() << endl;
	//cin >> s;
	Solution S;
	cout << S.strongPasswordChecker(s) << endl;
}