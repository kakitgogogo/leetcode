#include <iostream>
#include <cstdlib>
#include <vector>
#include "tree.h"
#include <climits>
using namespace std;

class Solution
{
public:
	int maxPathSum(TreeNode* root)
	{
		Max = INT_MIN;
		dfs(root);
		return Max;
	}
private:
	int Max;
	int dfs(TreeNode* root)
	{
		if(!root) return 0;
		int l = dfs(root->left), r = dfs(root->right);
		l = l > 0 ? l : 0;
		r = r > 0 ? r : 0;
		Max = max(Max, root->val + l + r);
		return root->val + max(l, r);
	}
};

int main()
{
	//TreeNode* root = build_tree({"1", "2", "3"});
	//TreeNode* root = build_tree({"1", "100", "1", "null", "null", "99", "99", "99", "null", "null", "99"});
	TreeNode* root = build_tree({"2", "null", "-1"});
	print_tree(root);
	Solution S;
	cout << S.maxPathSum(root) << endl;
}