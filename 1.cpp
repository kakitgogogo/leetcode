struct point
{
	int data;
	int key;
}; 

bool cmp(const point&p1,const point&p2)
{
 	return p1.data<p2.data;
}


class Solution {
public:

vector<int> twoSum(vector<int>& nums, int target) {
    int n=nums.size();
    vector<point>num(n);
    for(int i=0;i<n;i++)
 	{
 		num[i].data=nums[i];
 		num[i].key=i;
	}
 	sort(num.begin(),num.end(),cmp);
 	int left=0,right=n-1;
 	while(left<right)
	{
		while(num[left].data+num[right].data<target) left++;
		if(num[left].data+num[right].data==target) break;
		while(num[left].data+num[right].data>target) right--;
		if(num[left].data+num[right].data==target) break;
    }
 	vector<int>res(2);
 	res[0]=num[left].key;res[1]=num[right].key;
 	return res;
}
};
