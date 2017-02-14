#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

class Solution
{
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) 
	{
		vector<string> res;
		if(words.empty()) return res;

		int n = words.size(), p = 0, len = 0, i = 0;
		words.push_back(" ");
		for(i; i <= n; ++i)
		{
			if(len + words[i].size() + i - p > maxWidth || i == n)
			{
				int r = maxWidth - len, space, addition, d = 1;
				if(i == n)
				{
					space = 1;
					addition = 0;
				}
				else if(i - p - 1 <= 0) 
				{
					space = r;
					addition = 0;
				}
				else
				{
					space = r / (i - p - 1);
					addition = r % (i - p - 1);
				}
				string tmp;
				for(p; p < i; ++p)
				{
					tmp += words[p];
					if(p == i - 1) continue;
					if(addition-- <= 0) d = 0;
					tmp += string(space + d, ' ');
				}
				while(tmp.size() < maxWidth) tmp += " ";
				res.push_back(tmp);
				len = 0;
			}
			len += words[i].size();
		}
		return res;
	}
};

int main()
{
	Solution S;
	ifstream fin("input.txt");

	//vector<string>words({"This", "is", "an", "example", "of", "text", "justification.","add"});
	vector<string>words({"What","must","be","shall","be."});
	vector<string> res;

	//res = S.fullJustify(words, 16);
	res = S.fullJustify(words, 12);

	for(auto item:res)
	{
		cout << item << endl;
	}

	return 0;
}
