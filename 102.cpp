#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <queue>
#include "tree.h"
using namespace std;

class Solution
{
public:
	vector<vector<int> > levelOrder(TreeNode* root) 
	{
		vector<vector<int> > res;
		if(!root) return res;
		queue<TreeNode*>q;
		q.push(root);
		while(!q.empty())
		{
			int n = q.size();
			vector<int> vec;
			for(int i = 0; i < n; ++i)
			{
				TreeNode* tmp = q.front();
				q.pop();
				vec.push_back(tmp->val);
				if(tmp->left) q.push(tmp->left);
				if(tmp->right) q.push(tmp->right);
			}
			res.push_back(vec);
		}
		return res;
	}
};

int main()
{
	Solution S;
	ifstream fin("input.txt");

	TreeNode* root = build_tree({"3","9","20","null","null","15","7"});

	vector<vector<int> > res = S.levelOrder(root);

	for(auto vec:res)
	{
		for(auto item:vec)
		{
			cout << item << " ";
		}
		cout << endl;
	}

	return 0;
}