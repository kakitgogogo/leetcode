#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) 
    {
    	int tmp=a;
        a=a^b;
        b=(tmp&b)<<1;
        while(b)
        {
        	tmp=a;
        	a=a^b;
        	b=(tmp&b)<<1;
        }
        return a;
    }
};

int main()
{
	Solution s;
	int a,b;
	cin>>a>>b;
	cout<<s.getSum(a,b)<<endl;
	return 0;
}