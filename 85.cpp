#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <stack>
using namespace std;

class Solution
{
public:
	int maximalRectangle(vector<vector<char> >& matrix) 
	{
		int m = matrix.size();
		if(m == 0) return 0;
		int n = matrix[0].size();
		if(n == 0) return 0;

		int res = 0;
		vector<int>heights(n, 0);
		for(int i = 0; i < m; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				heights[j] = (matrix[i][j] == '0' ? 0 : heights[j] + 1);
			}
			vector<int>tmp = heights;
			res = max(res, largestRectangleArea(tmp));
		}
		return res;
	}
private:
	int largestRectangleArea(vector<int>& heights) 
	{
		int n = heights.size();
		stack<int>stk;
		int res = 0, top = 0, pre;

		heights.push_back(0);

		for(int i = 0; i <= n; ++i)
		{
			if(!stk.empty()) top = stk.top();
			pre = i;
			while(!stk.empty() && heights[i] < heights[stk.top()])
			{
				res = max(res, ((heights[stk.top()] ) * (top - stk.top() + 1)));
				pre = stk.top();
				stk.pop();
			}
			heights[pre] = heights[i];
			if(pre != i) stk.push(pre);
			stk.push(i);
		}
		return res;
	}
};

int main()
{
	Solution S;
	ifstream fin("input.txt");

	int m, n;
	fin >> m >> n;
	vector<vector<char> >matrix(m, vector<char>(n));
	for(auto& vec:matrix)
	{
		for(auto& item:vec)
		{
			fin >> item ;
		}
	}
	cout << S.maximalRectangle(matrix) << endl;

	return 0;
}