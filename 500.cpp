#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <set>
using namespace std;

class Solution
{
public:
	vector<string> findWords(vector<string>& words) 
	{
		s = "QWERTYUIOP";
		make_map(1);
		s = "ASDFGHJKL";
		make_map(2);
		s = "ZXCVBNM";
		make_map(3);

		vector<string>res;
		for(auto word:words)
		{
			int n = 0;
			for(auto c:word)
			{
				int k = toupper(c) - 'A';
				if(n != 0 && n != map[k]) 
				{
					n = 4;
					break;
				}
				n = map[k];
			}
			if(n < 4) res.push_back(word);
		}
		return res;
	}
private:
	int map[26];
	string s;
	void make_map(int n)
	{
		for(auto c:s)
		{
			map[c-'A'] = n;
		}
	}
};

int main()
{
	Solution S;
	ifstream fin("input.txt");

	vector<string>words({"Hello", "Alaska", "Dad", "Peace"});

	vector<string>res = S.findWords(words);

	for(auto item:res)
	{
		cout << item << endl;
	}

	return 0;
}