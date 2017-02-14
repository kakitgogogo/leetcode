#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
	using strset = unordered_set<string>;
	using strmap = unordered_map<string, vector<string> >;
	vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList) 
	{
		strset beginSet, endSet, wordSet(wordList.begin(), wordList.end());
		vector<vector<string> > res;

		if(wordSet.find(endWord) == wordSet.end()) return res;

		beginSet.insert(beginWord);
		endSet.insert(endWord);
		wordSet.erase(beginWord);
		wordSet.erase(endWord);
		bool isfinish = false;

		while(!beginSet.empty() && !endSet.empty())
		{
			if(isfinish) break;
			strset *set1, *set2, set3;
			int choose = 1;
			if(beginSet.size() <= endSet.size()) { set1 = &beginSet; set2 = &endSet; }
			else { choose = 2; set2 = &beginSet; set1 = &endSet; }

			for(auto iter = set1->begin(); iter != set1->end(); ++iter)
			{
				string cur = *iter, dup = cur;
				for(int i = 0; i < cur.size(); ++i)
				{
					char tmp = cur[i];
					for(int j = 0; j < 26; ++j)
					{
						cur[i] = 'a' + j; 
						if(set2->find(cur) != set2->end()) 
						{
							isfinish = true;
							if(choose == 1) strMap[dup].push_back(cur);
							else strMap[cur].push_back(dup);
							continue;
						}
						if(wordSet.find(cur) != wordSet.end())
						{
							set3.insert(cur);
							if(choose == 1) strMap[dup].push_back(cur);
							else strMap[cur].push_back(dup);
						}
					}
					cur[i] = tmp;
				}
			}
			for(auto it = set3.begin(); it != set3.end(); ++it) wordSet.erase(*it);
			swap(*set1, set3);
		}

		vector<string> tmp(1, beginWord);
		dfs(beginWord, endWord, tmp, res);

		return res;
	}
private:
	strmap strMap;
	void dfs(const string& cur, const string& endWord, vector<string>& tmp, vector<vector<string> >& res)
	{
		if(cur == endWord)
		{
			res.push_back(tmp);
			return;
		}
		for(auto iter = strMap[cur].begin(); iter != strMap[cur].end(); ++iter)
		{
			tmp.push_back(*iter);
			dfs(*iter, endWord, tmp, res);
			tmp.pop_back();
		}
	}
};

int main()
{
	Solution S;
	ifstream fin("input.txt");

	//vector<string> wordList({"hot","dot","dog","lot","log","cog"});

	//vector<vector<string> > res = S.findLadders("hit", "cog", wordList);

	//vector<string> wordList({"a","b","c"});

	//vector<vector<string> > res = S.findLadders("a", "c", wordList);

	vector<string> wordList({"flail","halon","lexus","joint","pears","slabs","lorie","lapse","wroth","yalow","swear","cavil","piety","yogis","dhaka","laxer","tatum","provo","truss","tends","deana","dried","hutch","basho","flyby","miler","fries","floes","lingo","wider","scary","marks","perry","igloo","melts","lanny","satan","foamy","perks","denim","plugs","cloak","cyril","women","issue","rocky","marry","trash","merry","topic","hicks","dicky","prado","casio","lapel","diane","serer","paige","parry","elope","balds","dated","copra","earth","marty","slake","balms","daryl","loves","civet","sweat","daley","touch","maria","dacca","muggy","chore","felix","ogled","acids","terse","cults","darla","snubs","boats","recta","cohan","purse","joist","grosz","sheri","steam","manic","luisa","gluts","spits","boxer","abner","cooke","scowl","kenya","hasps","roger","edwin","black","terns","folks","demur","dingo","party","brian","numbs","forgo","gunny","waled","bucks","titan","ruffs","pizza","ravel","poole","suits","stoic","segre","white","lemur","belts","scums","parks","gusts","ozark","umped","heard","lorna","emile","orbit","onset","cruet","amiss","fumed","gelds","italy","rakes","loxed","kilts","mania","tombs","gaped","merge","molar","smith","tangs","misty","wefts","yawns","smile","scuff","width","paris","coded","sodom","shits","benny","pudgy","mayer","peary","curve","tulsa","ramos","thick","dogie","gourd","strop","ahmad","clove","tract","calyx","maris","wants","lipid","pearl","maybe","banjo","south","blend","diana","lanai","waged","shari","magic","duchy","decca","wried","maine","nutty","turns","satyr","holds","finks","twits","peaks","teems","peace","melon","czars","robby","tabby","shove","minty","marta","dregs","lacks","casts","aruba","stall","nurse","jewry","knuth"});

	vector<vector<string> > res = S.findLadders("magic", "pearl", wordList);

	for(auto vec:res)
	{
		for(auto item:vec)
		{
			cout << item << " ";
		}
		cout << endl;
	}

	return 0;
}
