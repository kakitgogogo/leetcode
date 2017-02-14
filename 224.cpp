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
	int calculate(string s)
	{
		if(s.empty()) return 0;
		int n = s.size(), i = 0, res = 0;
		nums.push(0);

		while(i < n)
		{
			int tmp = 0;
			while(i < n && isdigit(s[i]))
			{
				tmp = tmp * 10 + (s[i++] - '0');
			}
			nums.push(tmp);
			if(!oper.empty() && (oper.top() == '+' || oper.top() == '-')) 
			{
				nums.push(cal());
			}
			
			if(i == n) break;
			while(i < n && !isdigit(s[i]))
			{
				if(s[i] == ')')
				{
					oper.pop();
					if(!oper.empty() && (oper.top() == '+' || oper.top() == '-')) 
					{
						nums.push(cal());
					}
				}
				else if(s[i] != ' ') 
				{
					oper.push(s[i]);
				}
				++i;
			}
		}
		while(!oper.empty())
		{
			nums.push(cal());
		}
		return nums.top();
	}
private:
	stack<int>nums;
	stack<char>oper;
	int cal()
	{
		int num2 = nums.top();
		nums.pop();
		int num1 = nums.top();
		nums.pop();
		char op = oper.top();
		oper.pop();
		return op == '+' ? num1 + num2 : num1 - num2;
	}
};

int main()
{
	Solution S;
	ifstream fin("input.txt");

	cout << S.calculate("2 - 1 + 1") << endl;
	cout << S.calculate("2 - 1 + 1(1+(4+5+2)-3)+(6+8)") << endl;
	cout << S.calculate("(7)-(0)+(4)") << endl;

	return 0;
}