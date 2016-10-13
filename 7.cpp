class Solution {
public:
    int reverse(int x) {
    
	if(x==1<<31) return 0;
	if(x==0) return 0;
	int isn=0;
	if(x<0) 
	{
	    isn=1;
	    x=~x+1;
	}
	vector<int>dig;
	while(x!=0)
	{
		dig.push_back(x%10);
		x/=10;
	}
	int i=0;
	while(dig[i]==0) i++;
	long long res=0;
	for(i;i<dig.size();i++)
	{
		res=res*10+dig[i];
	}
	if(res>=0x7FFFFFFF) return 0;
	return isn==1?-res:res;}
};
