#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

class Solution
{
public:
	vector<string> fizzBuzz(int n) 
	{
		vector<string>res(n);
		for(int i = 1; i <= n; ++i)
		{
			if(i % 3 == 0 && i % 5 == 0) res[i-1] = "FizzBuzz";
			else if(i % 3 == 0) res[i-1] = "Fizz";
			else if(i % 5 == 0) res[i-1] = "Buzz";
			else res[i-1] = to_string(i);
		}
		return res;
	}
};

int main()
{
	Solution S;
	ifstream fin("input.txt");

	int n;
	cin >> n;

	vector<string> res = S.fizzBuzz(n);

	for(auto item:res)
	{
		cout << item << endl;
	}

	return 0;
}