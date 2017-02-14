#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <map>
#include <climits>
using namespace std;

class Solution
{
public:
	bool isRectangleCover(vector<vector<int> >& rectangles) 
	{
		if(rectangles.empty()) return false;
		map<pair<int, int>, int> point_map;
		int up = INT_MAX, down = INT_MIN, left = INT_MAX, right = INT_MIN, sum_area = 0;
		for(auto rect:rectangles)
		{
			up = min(up, min(rect[1], rect[3]));
			down = max(down, max(rect[1], rect[3]));
			left  = min(left, min(rect[0], rect[2]));
			right = max(right, max(rect[0], rect[2]));
			++point_map[pair<int, int>(rect[0], rect[1])];
			++point_map[pair<int, int>(rect[0], rect[3])];
			++point_map[pair<int, int>(rect[2], rect[1])];
			++point_map[pair<int, int>(rect[2], rect[3])];
			sum_area += (rect[2] - rect[0]) * (rect[3] - rect[1]);
		}
		int cnt = 0;
		bool isvalid = true;
		for(auto iter:point_map)
		{
			if(iter.second == 1)
			{
				++cnt;
			}
			else if(iter.second % 2 == 1)
			{
				isvalid = false;
			}
		}
		return isvalid && cnt == 4 && point_map[pair<int, int>(left, up)] == 1 
			&& point_map[pair<int, int>(right, down)] == 1 && ((down - up) * (right - left) == sum_area);
	}
};

int main()
{
	Solution S;
	ifstream fin("input.txt");

	int m, n;
	fin >> m >> n;

	vector<vector<int> > rectangles(m, vector<int>(n));
	for(int i = 0; i < m; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			fin >> rectangles[i][j];
		}
	}

	cout << S.isRectangleCover(rectangles) << endl;

	return 0;
}