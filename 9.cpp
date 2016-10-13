class Solution {
public:
    bool isPalindrome(int x) 
  {
    if(x<0) return false;
	long long y=0;
	int tmp=x;
	while(tmp!=0)
	{
		y=10*y+tmp%10;
		tmp/=10;
	}  
	if(y>=0x7FFFFFFFF) return false;
	else return x==y?true:false;  
}
};
