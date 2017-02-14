#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <list>
#include <unordered_map>
using namespace std;

class LFUCache{
	using outer_list = list<pair<int, list<pair<int, int> > > >;
	using inner_list = list<pair<int, int> >;
	using umap = unordered_map<int, pair<outer_list::iterator, inner_list::iterator> >;
public:
	LFUCache(int capacity):size(0), max_size(capacity)
	{
	}
    
	int get(int key) 
	{
		auto iter = map.find(key);
		if(iter == map.end()) return -1;
		update(iter);
		return iter->second.second->second;
	}
    
	void put(int key, int val) 
	{
		if(max_size <= 0) return;

		auto iter = map.find(key);
		if(iter != map.end())
		{
			iter->second.second->second = val;
			update(iter);
		}
		else
		{
			if(size == max_size)
			{
				map.erase(ls.back().second.back().first);
				ls.back().second.pop_back();
				push_back(key, val);
			}
			else
			{
				push_back(key, val);
				++size;
			}
			map[key] = make_pair(prev(ls.end()), ls.back().second.begin());
		}
	}

	void update(umap::iterator& iter)
	{
		outer_list::iterator outer_iter = iter->second.first;
		inner_list::iterator inner_iter = iter->second.second;
		int freq = outer_iter->first, key = inner_iter->first, val = inner_iter->second;
		if(outer_iter == ls.begin() || prev(outer_iter)->first != freq + 1)
		{
			ls.insert(outer_iter, make_pair(freq + 1, inner_list(1, make_pair(key, val))));
		}
		else
		{
			prev(outer_iter)->second.push_front(make_pair(key, val));
		}
		map[key] = make_pair(prev(outer_iter), prev(outer_iter)->second.begin());
		outer_iter->second.erase(inner_iter);
		if(outer_iter->second.empty()) ls.erase(outer_iter);
	}

	void push_back(int key, int val)
	{
		if(ls.empty() || ls.back().first != 1) 
		{
			ls.push_back(make_pair(1, inner_list(1, make_pair(key, val))));
		}
		else
		{
			ls.back().second.push_front(make_pair(key, val));
		}
	}

	void show()
	{
		for(auto l:ls)
		{
			printf("freq(%d):\t", l.first);
			for(auto p:l.second)
			{
				printf("(%d, %d)\t", p.first, p.second);
			}
			printf("\n");
		}
	}
private:
	outer_list ls;
	umap map;
	int size;
	int max_size;
};

int main()
{
	LFUCache cache( 2 /* capacity */ );

	cache.put(1, 1);
	cache.put(2, 2);
	cout << cache.get(1) << endl;       // returns 1
	cache.put(3, 3);    // evicts key 2
	cache.show();
	cout << cache.get(2) << endl;       // returns -1 (not found)
	cout << cache.get(3) << endl;       // returns 3.
	cache.put(4, 4);    // evicts key 1.
	cout << cache.get(1) << endl;       // returns -1 (not found)
	cout << cache.get(3) << endl;       // returns 3
	cout << cache.get(4) << endl;       // returns 4

	return 0;
}