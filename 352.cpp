#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
using namespace std;

struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};
 
struct cmp
{
	bool operator()(const Interval& i1,const Interval& i2)
	{
	    if(i1.start!=i2.start) return i1.start<i2.start;
	    else return i1.end<i2.end;
	}
};
 
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
    }
    
    void addNum(int val) {
    	Interval itv(val,val);
        if(Set.empty())
        {
        	Set.insert(itv);
        	return;
	}
	auto lb=Set.lower_bound(itv);
	if(lb!=Set.begin())
	{
		if(prev(lb)->end>=val-1)
		{
			itv.start=prev(lb)->start;
			itv.end=max(itv.end,prev(lb)->end);
			Set.erase(prev(lb));
		}
	}
	if(lb!=Set.end())
	{
		if(lb->start<=val+1)
		{
			itv.start=min(lb->start,itv.start);
			itv.end=lb->end;
			Set.erase(lb);
		}
	}
	Set.insert(itv);
    }
    
    vector<Interval> getIntervals() {
        return vector<Interval>(Set.begin(),Set.end());
    }
private:
	set<Interval,cmp>Set;
};

void print(SummaryRanges sr)
{
	vector<Interval>res=sr.getIntervals();
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i].start<<" "<<res[i].end<<endl;
	}
}

int main()
{
	SummaryRanges sr;
	print(sr);
	sr.addNum(1);
	sr.addNum(3);
	sr.addNum(7);
	sr.addNum(2);
	sr.addNum(6);
	print(sr);
}