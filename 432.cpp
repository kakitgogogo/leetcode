#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <list>
#include <climits>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class AllOne
{
	using set_t = unordered_set<string>;
	using list_t = list<pair<int,  set_t> >;
	using map_t = unordered_map<string, list_t::iterator>;
public:
	AllOne()
	{
	}

	void inc(string key)
	{
		auto iter = map.find(key);
		if(iter != map.end())
		{
			auto list_node = iter->second;
			list_node->second.erase(key);
			if(next(list_node) == ls.end() || next(list_node)->first != list_node->first + 1)
			{
				ls.insert(next(list_node), make_pair(list_node->first + 1, set_t({key})));
			}
			else
			{
				next(list_node)->second.insert(key);
			}
			map[key] = next(list_node);

			if(list_node->second.empty()) ls.erase(list_node);
		}
		else
		{
			if(ls.empty() || ls.front().first != 1)
			{
				ls.push_front(make_pair(1, set_t({key})));
			}
			else
			{
				ls.front().second.insert(key);
			}
			map[key] = ls.begin();
		}
	}

	void dec(string key)
	{
		auto iter = map.find(key);
		if(iter != map.end())
		{
			auto list_node = iter->second;
			list_node->second.erase(key);
			if(list_node->first == 1)
			{
				map.erase(iter);
			}
			else
			{
				if(list_node == ls.begin() || prev(list_node)->first != list_node->first - 1)
				{
					ls.insert(list_node, make_pair(list_node->first - 1, set_t({key})));
				}
				else
				{
					prev(list_node)->second.insert(key);
				}
				map[key] = prev(list_node);
			}
			if(list_node->second.empty()) ls.erase(list_node);
		}
	}

	string getMaxKey()
	{
		if(ls.empty()) return string("");
		return *(ls.back().second.begin());
	}

	string getMinKey()
	{
		if(ls.empty()) return string("");
		return *(ls.front().second.begin());
	}

	void show()
	{
		for(auto l:ls)
		{
			printf("count(%d):\t", l.first);
			for(auto p:l.second)
			{
				printf("%s\t", p.c_str());
			}
			printf("\n");
		}
	}

private:
	list_t ls;
	map_t map;

};

int main()
{
	AllOne obj;
	ifstream fin("input.txt");
/*
	obj.inc("1");
	obj.inc("2");
	obj.inc("2");

	cout << obj.getMinKey() << endl;
	cout << obj.getMaxKey() << endl;

	obj.dec("2");
	obj.dec("2");

	cout << obj.getMinKey() << endl;
	cout << obj.getMaxKey() << endl;

	obj.inc("hello");
	obj.inc("world");
	obj.inc("hello");
	obj.dec("world");
	obj.inc("hello");
	obj.inc("leet");

	obj.show();

	cout << obj.getMaxKey() << endl;

	obj.dec("hello");
	obj.dec("hello");
	obj.dec("hello");

	obj.show();

	cout << obj.getMaxKey() << endl;
*/
	obj.inc("a");
	obj.inc("b");
	obj.inc("b");
	obj.inc("c");
	obj.inc("c");
	obj.inc("c");
	obj.dec("b");
	obj.dec("b");

	obj.show();

	cout << obj.getMinKey() << endl;

	obj.dec("a");

	obj.show();

	cout << obj.getMaxKey() << endl;
	cout << obj.getMinKey() << endl;

	return 0;
}