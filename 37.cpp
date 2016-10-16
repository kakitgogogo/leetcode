class Solution {
public:
bool flg=false;
bool rows[9][10],cols[9][10],squares[9][10];

void dfs(vector<vector<char> >&board,int i,int j)
{
	if(flg) return;
	if(i>=9) 
	{
		flg=true;
		return;
	}
	int i1=i+(j+1)/9,j1=(j+1)%9;
	if(board[i][j]=='.')
	{
		for(int k=1;k<=9;k++)
		{
			if((!rows[i][k])&&(!cols[j][k])&&(!squares[(i/3)*3+j/3][k]))
			{
				board[i][j]=k+'0';
				rows[i][k]=cols[j][k]=squares[(i/3)*3+j/3][k]=true;
	            dfs(board,i1,j1);
	            rows[i][k]=cols[j][k]=squares[(i/3)*3+j/3][k]=false;
	            if(flg) return;
			}
		}
		board[i][j]='.';
	}
	else dfs(board,i1,j1);
}

void solveSudoku(vector<vector<char> >& board)
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(board[i][j]!='.') 
			{
				int num=board[i][j]-'0';
				rows[i][num]=cols[j][num]=squares[(i/3)*3+j/3][num]=true;
			}
		}
	}
	dfs(board,0,0);
}
};
