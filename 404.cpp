#include <iostream>
#include "tree.h"
using namespace std;

class Solution
{
public:
	int sumOfLeftLeaves(TreeNode* root)
	{
		return dfs(root, false);
	}
private:
	int dfs(TreeNode* root, bool isleft)
	{
		if(!root) return 0;
		if(!root->left && !root->right)
		{
			return isleft ? root->val : 0;
		}
		return dfs(root->left, true) + dfs(root->right, false);
	}
};

int main()
{
	TreeNode* root = build_tree({"3", "9", "20", "null", "null", "15", "7"});
	//TreeNode* root = build_tree({"1"});
	Solution S;
	cout << S.sumOfLeftLeaves(root) << endl;
}