class Solution {
public:
	bool isValid(string s) {
		stack<char>sta;
		for(auto &x:s)
		{
			switch(x)
			{
			case '[':
			case '{':
			case '(':
				sta.push(x);
				break;
			case ']':
				if(sta.empty() || sta.top() != '[') return false;
				sta.pop();
				break;
			case '}':
				if(sta.empty() || sta.top() != '{') return false;
				sta.pop();
				break;
			case ')':
				if(sta.empty() || sta.top() != '(') return false;
				sta.pop();
				break;
			default:
				break;
			}
		}
		return sta.empty() ? true : false;
	}
};
