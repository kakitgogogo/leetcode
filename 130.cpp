#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

class Solution1
{
public:
	void solve(vector<vector<char> >& board) 
	{
		m = board.size();
		if(m == 0) return;
		n = board[0].size();
		if(n == 0) return;

		vector<vector<bool> > isvis(m, vector<bool>(n, false));
		
		for(int i = 0; i < m; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				if(!isvis[i][j] && board[i][j] == 'O')
				{
					surround = true;
					dfs(board, i, j, isvis);
					if(surround)
					{
						for(auto p:points)
						{
							board[p.first][p.second] = 'X';
						}
					}
					points.clear();
				}
			}
		}

	}
private:
	int m, n;
	bool surround;
	vector<pair<int, int> >points;
	void dfs(vector<vector<char> >& board, int i, int j, vector<vector<bool> > &isvis)
	{
		if(i <= 0 || i >= m - 1 || j <= 0 || j >= n - 1) 
		{
			surround = false;
			return;
		}
		isvis[i][j] = true;
		points.push_back(pair<int, int>(i, j));
		if(!isvis[i-1][j] && board[i-1][j] == 'O') dfs(board, i-1, j, isvis);
		if(!isvis[i+1][j] && board[i+1][j] == 'O') dfs(board, i+1, j, isvis);
		if(!isvis[i][j-1] && board[i][j-1] == 'O') dfs(board, i, j-1, isvis);
		if(!isvis[i][j+1] && board[i][j+1] == 'O') dfs(board, i, j+1, isvis);
	}
};

class Solution
{
public:
	void solve(vector<vector<char> >& board) 
	{
		m = board.size();
		if(m == 0) return;
		n = board[0].size();
		if(n == 0) return;
		
		for(int i = 0; i < m; ++i)
		{
			dfs(board, i, 0);
			dfs(board, i, n - 1);
		}
		for(int j = 1; j < n - 1; ++j)
		{
			dfs(board, 0, j);
			dfs(board, m - 1, j);
		}

		for(int i = 0; i < m; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				if(board[i][j] == 'O') board[i][j] = 'X';
				else if(board[i][j] == 'Q') board[i][j] = 'O';
			}
		}
	}
private:
	int m, n;
	void dfs(vector<vector<char> >& board, int i, int j)
	{
		if(board[i][j] != 'O') return;
		board[i][j] = 'Q';
		if(i > 1 && board[i-1][j] == 'O') dfs(board, i-1, j);
		if(i < m - 2 && board[i+1][j] == 'O') dfs(board, i+1, j);
		if(j > 1 && board[i][j-1] == 'O') dfs(board, i, j-1);
		if(j < n - 2 && board[i][j+1] == 'O') dfs(board, i, j+1);
	}
};

int main()
{
	Solution S;
	ifstream fin("input.txt");

	int m, n;
	fin >> m >> n;
	vector<vector<char> > board(m, vector<char>(n));

	for(int i = 0; i < m; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			fin >> board[i][j];
		}
	}

	S.solve(board);

	for(int i = 0; i < m; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}