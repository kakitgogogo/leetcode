#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> readBinaryWatch(int num)
	{
		vector<string> res;
		for(int i = 0; i < 12; ++i)
		{
			for(int j = 0; j < 60; ++j)
			{
				if(count1(i << 6 | j) == num)
				{
					res.push_back(to_string(i) + (j < 10 ? ":0" : ":") + to_string(j));
				}
			}
		}
		return res;
	}
private:
	int count1(int n)
	{
		int cnt = 0;
		while(n)
		{
			n &= (n - 1);
			++cnt;
		}
		return cnt;
	}
};

int main()
{
	int n;
	cin >> n;

	vector<string> res;
	Solution S;
	res = S.readBinaryWatch(n);
	for(auto& s:res)
	{
		cout << s << endl;
	}
}