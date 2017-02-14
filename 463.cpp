#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int islandPerimeter(vector<vector<int> >& grid) 
	{
		int m = grid.size();
		if(m == 0) return 0;
		int n = grid[0].size();
		if(n == 0) return 0;

		int cnt = 0;
		for(int i = 0; i < m; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				if(grid[i][j] == 1)
				{
					cnt += (4 
						- (i == 0 ? 0 : grid[i - 1][j])
						- (i == m - 1 ? 0 : grid[i + 1][j])
						- (j == 0 ? 0 : grid[i][j - 1])
						- (j == n - 1 ? 0 : grid[i][j + 1]));
				}
			}
		}
		return cnt;
	}
};

int main()
{
	int m, n;
	cin >> m >> n;
	vector<vector<int> >a(m, vector<int>(n));
	for(auto& v:a)
	{
		for(auto& i:v)
		{
			cin >> i;
		}
	}
	Solution S;
	cout << S.islandPerimeter(a) << endl;
}