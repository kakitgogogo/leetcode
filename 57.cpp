#include <iostream>
#include <vector>
#include <cstdlib>
#include <functional>
using namespace std;

struct Interval 
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


void print(vector<Interval>&in)
{
	for(int i=0;i<in.size();i++)
	{
		cout<<"["<<in[i].start<<","<<in[i].end<<"]";
	}
	cout<<endl;
}
/*
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) 
    {
    	vector<Interval>::iterator it;
    	int s=newInterval.start,e=newInterval.end;
       vector<Interval>::iterator l,r;
       bool flg=true;
       for(it=intervals.begin();it!=intervals.end();it++)
        {
        	if((*it).end>=newInterval.start) 
        	{
        		flg=false;
        		l=it;
        		s=min(s,(*it).start);
        		break;
        	}
        }
       if(flg)
        {
    	   intervals.push_back(newInterval);
    	   return intervals;
        }
       if((*it).start>newInterval.end)
       {
    	   intervals.insert(it,newInterval);
    	   return intervals;
       }
       for(;it!=intervals.end();it++)
        {
    	   if((*it).start>=newInterval.end) 
    	   {
    		   break;
    	   }
		   e=max(e,(*it).end);
		   r=it;
        }
       intervals.erase(l,r);
       (*r).start=s;
    	(*r).end=e;
       return intervals;
    }
};
*/
class Solution 
{
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
	{
		vector<Interval>ret;
		vector<Interval>::iterator it;
		int s=newInterval.start,e=newInterval.end;
		for(it=intervals.begin();it!=intervals.end();it++)
		{
			if((*it).end<newInterval.start)
			{
				ret.push_back(*it);
			}
			else 
			{
				s=min(s,(*it).start);
				break;
			}
		}
		for(;it!=intervals.end();it++)
		{
			if((*it).start>newInterval.end)
			{
				break;
			}
			e=max(e,(*it).end);
		}
		ret.push_back(Interval(s,e));
		for(;it!=intervals.end();it++)
		{
			ret.push_back(*it);
		}
		return ret;
	}
};

int main()
{
	vector<Interval>in;
	in.push_back(Interval(1,3));
	in.push_back(Interval(6,9));
	Solution s;
	in=s.insert(in,Interval(0,15));
	print(in);
}