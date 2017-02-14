#include<iostream>
#include<vector>
#include<cstring>
#include "leetcode_func.h"
using namespace std;

bool find(long long n1,long long n2,string s)
{
	int n=s.size();
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0') continue; 
		long long n3=stol(s.substr(0,i).c_str());
		cout<<"n3:"<<n3<<endl;
		if(n3>n2+n1) break;
		else if(n3==n1+n2)
		{
			if(i==n) return true;
			else 
			{
				if(find(n2,n3,s.substr(i,n-i))) return true;
			}
		}
	}
	return false;
}

bool isAdditiveNumber(string num)
{
	int len=num.size();
	if(len<3) return false;
	int flg1=0;
	if(num[0]=='0') flg1=1;
	for(int l1=1;l1<=(len/2);l1++)
	{
		long long n1=stol(num.substr(0,l1).c_str());
		cout<<"n1:"<<n1<<endl;
		int flg2=0;
		if(num[l1]=='0') flg2=1;
		for(int l2=1;l2<=(len-l1)/2;l2++)
		{
			if(num[l1+l2]=='0') continue;
			long long n2=stol(num.substr(l1,l2).c_str());
			cout<<"n2:"<<n2<<endl;
			if(find(n1,n2,num.substr(l1+l2,len-l2-l1))) return true;
			if(flg2==1) break;
		}
		if(flg1==1) break;
	}
	return false; 
}

int main()
{
	string s;
	cin>>s;
	bool res=isAdditiveNumber(s);
	if(res) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
}