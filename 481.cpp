#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

class Solution
{
public:
	int magicalString(int n)
	{
		string s = "122";
		int i = 2;
		while(s.size() < n)
		{
			s += string(s[i++] - '0', s.back() == '1' ? '2' : '1');
		}
		return count(s.begin(), s.begin() + n, '1');
	}
};

int main()
{
	Solution S;
	ifstream fin("input.txt");

	int n;
	cin >> n;

	cout << S.magicalString(n) << endl;

	return 0;
}