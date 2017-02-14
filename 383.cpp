#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <set>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
    	int count[300];
    	memset(count,0,sizeof(count));
    	for(auto& x:magazine)
    	{
    		count[x]++;
    	}
    	for(auto& x:ransomNote)
    	{
    		if(count[x]>0)
    		{
    			count[x]--;
    		}
    		else
    		{
    			return false;
    		}
    	}
    	return true;
    }
};

int main()
{
	Solution S;
	string s,t;
	cin>>s>>t;
	cout.setf(ios_base::boolalpha);
	cout<<S.canConstruct(s,t)<<endl;
}