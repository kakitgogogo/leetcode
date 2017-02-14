#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <climits>
#include <set>
using namespace std;

class Solution
{
public:
	int maxSumSubmatrix(vector<vector<int> >& matrix, int k)
	{
		int m = matrix.size(); if(m == 0) return 0;
		int n = matrix[0].size(); if(n == 0) return 0;
		int res = INT_MIN;

		for(int col = 0; col < n; ++col)
		{
			vector<int> row_sums(m, 0);
			for(int i = col; i < n; ++i)
			{
				for(int row = 0; row < m; ++row)
				{
					row_sums[row] += matrix[row][i];
				}

				int tmp_res = INT_MIN, accum = 0;
				set<int> accums; accums.insert(0);
				for(auto num:row_sums)
				{
					accum += num;
					auto iter = accums.lower_bound(accum - k);
					if(iter != accums.end()) tmp_res = max(tmp_res, accum - *iter);
					accums.insert(accum);
				}
				res = max(res, tmp_res);
			}
		}
		return res;
	}
};

int main()
{
	Solution S;
	ifstream fin("input.txt");

	int m, n, k;
	fin >> m >> n >> k;

	vector<vector<int> > matrix(m, vector<int>(n));
	for(auto& vec:matrix)
	{
		for(auto& item:vec)
		{
			fin >> item;
		}
	}
	cout << "here" << endl;

	cout << S.maxSumSubmatrix(matrix, k) << endl;

	return 0;
}