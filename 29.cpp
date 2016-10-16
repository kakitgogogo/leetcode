class Solution {
public:
    int divide(int dividend, int divisor) 
	{
        if(divisor==0||(dividend==INT_MIN&&divisor==-1)) return INT_MAX;
        int sign=((dividend<0)^(divisor<0))?-1:1;
        long long dd=labs(dividend),ds=labs(divisor);
        int res=0;
        while(dd-ds>=0)
        {
        	long long tmp=ds,mul=1;
        	while(dd-(tmp<<1)>=0)
        	{
        		tmp<<=1;
        		mul<<=1;
			}
			dd-=tmp;
			res+=mul;
		}
		return sign==-1?-res:res;
    }
};
