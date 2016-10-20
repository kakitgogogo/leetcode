class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
    	int n = matrix.size(), l = 0, r = n-1;
    	if(n <= 1) return;
        for(int i=0; i<n/2; ++i)
        {
        	for(int j=l; j<r; ++j)
        	{
        		int tmp(std::move(matrix[n-1-j][i]));
        		matrix[n-1-j][i] = std::move(matrix[n-1-i][n-1-j]);
        		matrix[n-1-i][n-1-j] = std::move(matrix[j][n-1-i]);
        		matrix[j][n-1-i] = std::move(matrix[i][j]);
        		matrix[i][j] = std::move(tmp);        		
			}
			--r;
			++l;
		}
    }
};
