#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution1
{
public:
	string multiply(string num1, string num2)
	{
		int m = num1.size(), n = num2.size();
		if(m == 0 || n == 0) return 0;
		string res(m + n, '0');

		for(int i = m-1; i >=0; --i)
		{
			int r = 0;
			for(int j = n-1; j >= 0; --j)
			{
				int tmp = (res[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + r;
				res[i + j + 1] = tmp % 10 + '0';
				r = tmp / 10;
			}
			res[i] += r;
		}

		size_t pos = res.find_first_not_of("0");
		if(pos != string::npos)
		{
			return res.substr(pos);
		}

		return "0";
	}
};

class Solution
{
public:
	string multiply(string num1, string num2)
	{
		int m = num1.size(), n = num2.size();
		if(m == 0 || n == 0) return 0;
		string res(m + n, '0');

		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());

		for(int i = 0; i < m; ++i)
		{
			int r = 0;
			for(int j = 0; j < n; ++j)
			{
				int tmp = (res[i + j] - '0') + (num1[i] - '0') * (num2[j] - '0') + r;
				res[i + j] = tmp % 10 + '0';
				r = tmp / 10;
			}
			res[i + n] += r;
		}

		reverse(res.begin(), res.end());

		size_t pos = res.find_first_not_of("0");
		if(pos != string::npos)
		{
			return res.substr(pos);
		}

		return "0";
	}
};

int main()
{
	Solution S;

	cout << S.multiply("250", "4") << endl;;

	return 0;
}