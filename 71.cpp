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
	string simplifyPath(string path)
	{
		size_t left, right;
		stack<string>stk;

		path += "/";

		left = 1; right = path.find('/', 1);

		while(right != string::npos)
		{
			string tmp = path.substr(left, right - left);
			if(tmp == "..")
			{
				if(!stk.empty()) stk.pop();
			}
			else if(tmp != "." && !tmp.empty())
			{
				stk.push(tmp);
			}

			left = right + 1; 
			right = path.find('/', left);
		}

		string res;
		while(!stk.empty())
		{
			res = "/" + stk.top() + res;
			stk.pop();
		}

		if(res.empty()) res = "/";

		return res;
	} 
};

int main()
{
	Solution S;
	ifstream fin("input.txt");

	//cout << S.simplifyPath("/home/") << endl;
	//cout << S.simplifyPath("/a/./b/../../c/") << endl;
	//cout << S.simplifyPath("/../") << endl;
	//cout << S.simplifyPath("/...") << endl;
	cout << S.simplifyPath("/a//b/") << endl;

	return 0;
}
