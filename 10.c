bool isMatch(char* s, char* p) 
{
    if(*p == 0) return *s == 0;
    if(p[1] == '*')
    {
    	return isMatch(s, p + 2) || ((*s != 0 && (s[0] == p[0] || p[0] == '.')) && isMatch(s + 1, p));
	}
	else
	{
		return ((*s != 0 && (s[0] == p[0] || p[0] == '.')) && isMatch(s + 1, p + 1));
	}
}
