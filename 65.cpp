#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <boost/lexical_cast.hpp>
using namespace std;
/*
class Solution
{
public:
	bool isNumber(string s)
	{
		using namespace boost;
		try
		{
			double d=lexical_cast<double>(s);
		}
		catch(bad_lexical_cast & e)
		{
			return false;
		}
		return true;
	}
};

class Solution
{
public:
	bool isNumber(string s)
	{
		replace_if(s.begin(),s.end(),[](const char& c){return c==' ';},'1');
		char *end;
		double d=strtod(s.c_str(),&end);
		if(strlen(end)>0) return false;
		else return true;
	}
};
*/

class Solution
{
public:
	bool isNumber(string s)
	{
		s.erase(0,s.find_first_not_of(" "));
		s.erase(s.find_last_not_of(" ") + 1);
		if(s.empty()) return false;
		auto isvalid=[](const char& c){return c==' ';};
		char *end;
		double d=strtod(s.c_str(),&end);
		if(strlen(end)>0) return false;
		else return true;
	}
};

int main()
{
	Solution s;
	string str;
	getline(cin,str);
	cout.setf(ios_base::boolalpha);
	cout<<s.isNumber(str)<<endl;
}