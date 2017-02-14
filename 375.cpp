#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
	int getMoneyAmount(int n)
	{
		vector<vector<int> >dp(n + 1, vector<int>(n + 1, 0));
		for(int i = 2; i <= n; ++i)
		{
			for(int j = i - 1; j >= 1; --j)
			{
				int Min = INT_MAX;
				for(int k = j + 1; k <= i - 1; ++k)
				{
					int Max = k + max(dp[j][k-1], dp[k+1][i]);
					Min = min(Min, Max);
				}
				dp[j][i] = j+1 == i ? j : Min;
			}
		}
		return dp[1][n];
	}
};

int main(int argc, char const *argv[])
{
	Solution S;
	int n;
	cin>>n;
	cout << S.getMoneyAmount(n) << endl;
	return 0;
}