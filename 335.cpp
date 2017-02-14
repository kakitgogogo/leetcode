#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <queue>
#include <climits>
using namespace std;

class Solution
{
public:
	bool isSelfCrossing(vector<int>& x) 
	{
		for(int i = 3; i < x.size(); ++i)
		{
			if(x[i - 1] <= x[i - 3] && x[i] >= x[i - 2]) return true;
			if(i >= 4 && x[i - 1] == x[i - 3] && x[i] + x[i - 4] >= x[i - 2]) return true;
			if(i >= 5 && x[i - 1] <= x[i - 3] && x[i - 2] > x[i - 4] && x[i - 1] + x[i - 5] >= x[i - 3] && x[i] + x[i - 4] >= x[i - 2]) return true;
		}
		return false;
	}
};

int main()
{
	Solution S;
	ifstream fin("input.txt");

	//vector<int>x({1,1,1,1});
	//vector<int>x({1,1,2,1,1});
	//vector<int>x({2,1,3,2,2,2});
	vector<int>x({1,1,2,2,3,3,4,4,10,4,4,3,3,2,2,1,1});

	cout.setf(ios_base::boolalpha);
	cout << S.isSelfCrossing(x) << endl;

	return 0;
}