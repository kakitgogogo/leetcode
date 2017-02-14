#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

class Solution
{
public:
	using ull = unsigned long long;
	string smallestGoodBase(string n) 
	{
		ull num = (ull)stoll(n);
		for(int i = 63; i >= 1; --i)
		{
			if(((ull)(1) << i) >= num) continue;
			ull ret = solve(num, i+1);
			if(ret != 0) return to_string(ret);
		}
		return to_string(num - 1);
	}
private:
	int solve(ull num, int n)
	{
		int l = 2, r = (int)(pow(num, 1.0/(n-1)) + 1);
		//cout << n << " " << r << endl;
		while(l <= r)
		{
			int mid = (r - l) / 2 + l, ret = cmp(num, mid, n);
			if(ret == 0) return mid;
			else if(ret < 0) 
			{
				l = mid + 1;
			}
			else
			{
				r = mid - 1;
			}
		}
		return 0;
	}
	int cmp(ull num, ull base, int n)
	{
		ull sum = 0, d = 1;
		while( --n >= 0) 
		{
			sum += d;
			if(sum > num) return 1;
			d *= base;
		}
		return sum == num ? 0 : -1;
	}
};

int main()
{
	Solution S;
	ifstream fin("input.txt");

	string s;
	cin >> s;
	cout << S.smallestGoodBase(s) << endl;

	return 0;
}