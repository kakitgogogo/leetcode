bool isMatch(char* s, char* p)
{
	int i, j;
	int m, n;
	int **dp;
	
	m = strlen(s);
	n = strlen(p);
	
	dp = calloc((m + 1), sizeof(int*));
	dp[0] = calloc((n + 1), sizeof(int));
	
	dp[0][0] = 1;
	for(j = 1; j <= n; ++j)
	{
		if(p[j - 1] == '*')
		{
			dp[0][j] = dp[0][j - 1];
		}
	}
	for(i = 1; i <= m; ++i)
	{
		dp[i] = calloc((n + 1), sizeof(int));
		for(j = 1; j <= n; ++j)
		{
			if(p[j - 1] == '*')
			{
				dp[i][j] = (dp[i][j - 1] || dp[i - 1][j]);
			}
			else
			{
				dp[i][j] = (dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?'));
			}
		}
		free(dp[i - 1]);
	}
	return dp[m][n];
}
