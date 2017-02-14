#include <iostream>
#include <vector>
using namespace std;

const int bad_version = 6;

bool isBadVersion(int version)
{
	return version >= bad_version;
}

class Solution
{
public:
	int firstBadVersion(int n) 
	{
		int l = 1, r = n;
		while(l < r)
		{
			int mid = (r - l) / 2 + l;
			if(isBadVersion(mid))
			{
				r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}
		return isBadVersion(l) ? l : l + 1;
	}
};

int main()
{
	int n;
	cin >> n;
	Solution S;
	cout << S.firstBadVersion(n) << endl;
}