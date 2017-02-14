#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
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
	vector<int>heights({2,1,5,6,2,3});
	//vector<int>heights({1,1,1,5,2,1,1,1,1});
	//vector<int>heights({1,1,1,10,2,1,1,1,1});
	//vector<int>heights({1,1,1,10,3,3,3,1,1});
	cout << S.largestRectangleArea(heights) << endl;
}