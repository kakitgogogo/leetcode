class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int>res;
		if(words.empty()) return res;
		int n = words.size(), m = words[0].size(), ssize = s.size(), id = 0;
		map<string, int>wordMap;
		for(auto &x:words)
		{
			if(wordMap.find(x) == wordMap.end())
			{
				wordMap[x] = id++;
			}
		} 
		vector<int>wordCount(wordMap.size(), 0);
		for(auto &x:words)
		{
			++wordCount[wordMap[x]];
		}
		vector<int>ssub(ssize, -1);
		for(int i = 0; i < ssize-m+1; ++i)
		{
			auto it = wordMap.find(s.substr(i, m));
			if(it != wordMap.end())
			{
				ssub[i] = it->second;
			}
		}
		
		for(int i = 0; i < m; ++i)
		{
			vector<int>count(wordMap.size());
			int curLen = 0;
			
			for(int j = i; j < ssize; j += m)
			{
				int index = ssub[j];
				if(index >= 0)
				{
					if(count[index] < wordCount[index])
					{
						++curLen;
						++count[index];
					}
					else
					{
						while(ssub[j - curLen * m] != index)
						{
							--count[ssub[j - curLen * m]];
							--curLen;
						}
					}
					
					if(curLen == n)
					{
						res.push_back(j - (n - 1) * m);
					}
				}
				else
				{
					memset(count.data(), 0, sizeof(int) * count.size());
					curLen = 0;
				}
			}
		}
		return res;
	}
};
