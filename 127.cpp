#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
	{
		using strset = unordered_set<string>;
		strset beginSet, endSet, wordSet(wordList.begin(), wordList.end());
		if(wordSet.find(endWord) == wordSet.end()) return 0;

		beginSet.insert(beginWord);
		endSet.insert(endWord);
		wordSet.erase(endWord);
		int res = 2;

		while(!beginSet.empty() && !endSet.empty())
		{
			strset *set1, *set2, set3;
			if(beginSet.size() <= endSet.size()) { set1 = &beginSet; set2 = &endSet; }
			else { set2 = &beginSet; set1 = &endSet; }
			for(auto iter = set1->begin(); iter != set1->end(); ++iter)
			{
				string cur = *iter;
				for(int i = 0; i < cur.size(); ++i)
				{
					char tmp = cur[i];
					for(int j = 0; j < 26; ++j)
					{
						cur[i] = 'a' + j; 
						if(set2->find(cur) != set2->end()) return res;
						if(wordSet.find(cur) != wordSet.end())
						{
							set3.insert(cur);
							wordSet.erase(cur);
						}
					}
					cur[i] = tmp;
				}
			}
			swap(*set1, set3);
			++res;
		}
		return 0;
	}
};

int main()
{
	Solution S;
	ifstream fin("input.txt");

	vector<string> wordList({"hot","dot","dog","lot","log","cog"});

	cout << S.ladderLength("hit", "cog", wordList) << endl;

	return 0;
}