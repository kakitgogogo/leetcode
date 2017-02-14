#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

class Solution
{
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) 
	{
		m = matrix.size(); if(m == 0) return 0;
		n = matrix[0].size(); if(n == 0) return 0;
		int res = 1;

		records.resize(m, vector<int>(n, 0));

		for(int i = 0; i < m; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				res = max(res, dfs(matrix, i, j));
			}
		}
		return res;
	}
private:
	int m, n;
	vector<vector<int> >records;
	int dfs(vector<vector<int> > &matrix, int i, int j)
	{
		if(records[i][j]) return records[i][j];
		if(i == -1 || i == m || j == -1 || j == n) return 0;	
		int up = 0, down = 0, left = 0, right = 0;
		if(i > 0 && matrix[i-1][j] > matrix[i][j]) up = dfs(matrix, i-1, j);
		if(i < m-1 && matrix[i+1][j] > matrix[i][j]) down = dfs(matrix, i+1, j);
		if(j > 0 && matrix[i][j-1] > matrix[i][j]) left = dfs(matrix, i, j-1);
		if(j < n-1 && matrix[i][j+1] > matrix[i][j]) right = dfs(matrix, i, j+1);
		records[i][j] = max(max(up, down), max(left, right)) + 1;
		return records[i][j];
	}
};

int main()
{
	Solution S;
	ifstream fin("input.txt");

	int m, n;
	fin >> m >> n;
	vector<vector<int> >matrix(m, vector<int>(n));

	for(auto& vec:matrix)
	{
		for(auto& item:vec)
		{
			fin >> item;
		}
	}

	cout << S.longestIncreasingPath(matrix) << endl;

	return 0;
}