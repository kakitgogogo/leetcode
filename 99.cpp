#include <iostream>
#include <climits>
#include "tree.h"
using namespace std;

class Solution
{
public:
	void recoverTree(TreeNode* root) 
	{
		pre = new TreeNode(INT_MIN);
		inOrder(root);
		if(errs.size() == 1)
		{
			swap(errs[0], pres[0]);
		}
		else if(errs.size() == 2)
		{
			swap(pres[0], errs[1]);
		}
	}
private:
	vector<TreeNode*>errs, pres;
	TreeNode* pre;
	void inOrder(TreeNode* root)
	{
		if(!root) return;
		inOrder(root->left);
		if(pre->val > root->val) 
		{
			pres.push_back(pre);
			errs.push_back(root);
		}
		pre = root;
		inOrder(root->right);
	}
	void swap(TreeNode* n1, TreeNode* n2)
	{
		::swap(n1->val, n2->val);
	}
};

int main()
{
	TreeNode *root = build_tree({"6", "2", "4", "1", "3", "5", "7"});
	print_tree(root);
	Solution S;
	S.recoverTree(root);
	print_tree(root);
}