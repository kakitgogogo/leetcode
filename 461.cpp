#include <iostream>
#include <cstdlib>
using namespace std;

class Solution
{
public:
	int hammingDistance(int x, int y)
	{
		int mask = 1, cnt = 0;
		for(int i = 0; i < 32; ++i)
		{
			if((x & mask) != (y & mask))
			{
				++cnt;
			}
			x >>= 1;
			y >>= 1;
		}
		return cnt;
	}
};

int main()
{
	int x, y;
	cin >> x >> y;
	Solution S;
	cout << S.hammingDistance(x, y) << endl;
}