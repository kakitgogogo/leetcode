#include <iostream>
#include <vector>
#include <cstdlib>
#include <climits>
#include <queue>
#include <stack>
using namespace std;

#define t cout << "ss: " << sta.size() << " res: " << res << endl

class Solution {
public:
	int trap(vector<int>& height) 
	{
		int res = 0, i, n = height.size();
		stack<bar>sta;
		if(n <= 1) return 0;
		int line = 0;
		sta.push(bar(0, height[0]));
		for(i=1; i<n; ++i)
		{
			if(height[i] < height[i-1])
			{
				sta.push(bar(i, height[i]));
				line = height[i];
			}
			else
			{
				bar tmp;
				while(!sta.empty())
				{
					tmp = sta.top();
					if(tmp.h > height[i])
					{
						res += (height[i] - line) * (i - tmp.pos - 1);
						line = height[i];
						break;
					}
					else
					{
						res += (tmp.h - line) * (i - tmp.pos - 1);
						line = tmp.h;
						sta.pop();
					}
				}
				sta.push(bar(i, height[i]));
			}
		}
		return res;
	}
private:
	struct bar
	{
		int pos;
		int h;
		bar(): pos(0),h(0) {}
		bar(int n,int m): pos(n),h(m) {}
	};
};

int main()
{
	Solution s;
	vector<int>v({5,5,1,7,1,1,5,2,7,6});
	cout<<s.trap(v);
}