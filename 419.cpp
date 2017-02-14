#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int countBattleships(vector<vector<char> >& board)
	{
		int m = board.size();
		if(m == 0) return 0;
		int n = board[0].size();
		if(n == 0) return 0;

		int res = 0;

		for(int i = 0; i < m; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				if(board[i][j] == 'X' && (i == 0 || board[i - 1][j] != 'X') && (j == 0 || board[i][j - 1] != 'X'))
				{
					++res;
				}
			}
		} 
		return res;
	}
};

int main()
{
	int m, n;
	cin >> m >> n;
	vector<vector<char> >board(m, vector<char>(n));
	for(int i = 0; i < m; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			cin >> board[i][j];
		}
	}
	Solution S;
	cout << S.countBattleships(board) << endl;
}