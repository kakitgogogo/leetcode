#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstdio>
#include <climits>
#include <cmath>
using namespace std;
/*
class Solution {
public:
    int mySqrt(int x) 
    {
    	int left=0,right=46341,mid;
    	while(left<right)
    	{
    		mid=(left+right)/2;
    		if(mid*mid==x) return mid;
    		else if(mid*mid>x) right=mid-1;
    		else left=mid+1;
    	}
    	return (left*left<x)?left:left-1;
    }
};
*/
class Solution {
public:
    int mySqrt(int x) //用牛顿法
    {
    	long long y=x;
    	while(y*y>x) y=(y+x/y)/2;
    	return y;
    }
};

int main()
{
	//cout<<sqrt(INT_MAX)<<endl;
	Solution s;
	int n;
	cin>>n;
	int res=s.mySqrt(n);
	cout<<res<<" "<<res*res<<endl;
}