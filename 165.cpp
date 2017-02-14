#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

class Solution
{
public:
	int compareVersion(string version1, string version2)
	{
		int i1 = 0, i2 = 0, n1 = version1.size(), n2 = version2.size();

		while(i1 < n1 || i2 < n2)
		{
			int sum1 = 0, sum2 = 0;
			while(i1 < n1)
			{
				if(version1[i1] == '.') break;
				sum1 = sum1 * 10 + (version1[i1++] - '0');
			}
			while(i2 < n2)
			{
				if(version2[i2] == '.') break;
				sum2 = sum2 * 10 + (version2[i2++] - '0');
			}
			if(sum1 != sum2) return sum1 > sum2 ? 1 : -1;
			i1++;
			i2++;
		}
		return 0;
	}
};

int main()
{
	Solution S;
	ifstream fin("input.txt");

	string version1, version2;
	cin >> version1 >> version2;

	cout << S.compareVersion(version1, version2) << endl;

	return 0;
}