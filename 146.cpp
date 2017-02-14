#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache{
public:
	LRUCache(int capacity):Max(capacity)
	{
	}
    
	int get(int key) 
	{
		auto it=um.find(key);
		if(it==um.end()) return -1;
		auto lit=it->second;
		node newnode(lit->key,lit->val);
		ls.erase(lit);
		ls.push_front(newnode);
		um[key]=ls.begin();
		return ls.begin()->val;
	}
    
	void put(int key, int val) 
	{
		auto it=um.find(key);
		if(it==um.end())
		{
			if(ls.size()==Max)
			{
				um.erase(ls.back().key);
				ls.pop_back();
			}
			ls.push_front(node(key,val));
			um[key]=ls.begin();
		}
		else
		{
			auto lit=it->second;
			node newnode(key,val);
			ls.erase(lit);
			ls.push_front(newnode);
			um[key]=ls.begin();
		}
}
    
private:
	struct node
	{
		int key;
		int val;
		node(int k,int v):key(k),val(v){}
	};
	
	list<node>ls;
	unordered_map<int,list<node>::iterator>um;
	int Max;
};

int main()
{
	LRUCache cache( 2 /* capacity */ );

	cache.put(1, 1);
	cache.put(2, 2);
	cout << cache.get(1) << endl;       // returns 1
	cache.put(3, 3);    // evicts key 2
	cout << cache.get(2) << endl;;       // returns -1 (not found)
	cache.put(4, 4);    // evicts key 1
	cout << cache.get(1) << endl;;       // returns -1 (not found)
	cout << cache.get(3) << endl;;       // returns 3
	cout << cache.get(4) << endl;;       // returns 4	

	return 0;
}