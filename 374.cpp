#include <iostream>
#include <cstdlib>
using namespace std;

int pick;

int guess(int num)
{
	if(num == pick) return 0;
	return pick < num ? -1 : 1;
}

class Solution
{
public:
	int guessNumber(int n)
	{
		int l = 1, r = n;
		while(true)
		{
			int mid = (r - l) / 2 + l, val = guess(mid);
			if(val < 0)
			{
				r = mid - 1;
			}
			else if(val > 0)
			{
				l = mid + 1;
			}
			else
			{
				return mid;
			}
		}
	}
};

int main()
{
	int n;
	cin >> n >> pick;
	Solution S;
	cout << S.guessNumber(n) << endl;
}