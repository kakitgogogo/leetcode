#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

static TreeNode* build_node(string s)
{
	if(s == "null")
	{
		return NULL; 
	}
	else
	{
		TreeNode *node = new TreeNode(stoi(s));
		return node;
	}
}

TreeNode* build_tree(initializer_list<string>list)
{
	auto it = list.begin();
	if(it == list.end()) return NULL;
	TreeNode* root = build_node(*(it++));
	queue<TreeNode*>q;
	q.push(root);
	while(!q.empty())
	{
		TreeNode* tmp = q.front();
		q.pop();
		if(it == list.end()) break;
		tmp->left = build_node(*(it++));
		if(tmp->left) q.push(tmp->left);
		if(it == list.end()) break;
		tmp->right = build_node(*(it++));
		if(tmp->right) q.push(tmp->right);
	}
	return root;
}

void print_tree(TreeNode* root)
{
	queue<TreeNode*>q;
	q.push(root);
	while(!q.empty())
	{
		TreeNode* tmp = q.front();
		q.pop();
		printf("%d ", tmp->val);
		if(tmp->left) q.push(tmp->left);
		if(tmp->right) q.push(tmp->right);
	}
	cout << endl;
}