#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

struct BST
{
	int val;
	int count;
	BST *left,*right;
	BST(int v,int c=0,BST *l=NULL,BST *r=NULL):
		val(v),count(c),left(l),right(r){}
};

void insert(BST *&root,int num,int &ret)
{
	if(root==NULL)
	{
		root=new BST(num);
		return;
	}
	if(num>root->val)
	{
		ret+=root->count+1;
		insert(root->right,num,ret);
	}
	else
	{
		root->count++;
		insert(root->left,num,ret);
	}
}

vector<int> countSmaller(vector<int>& nums)
{
   vector<int>res;
	if(nums.empty()) return res;
	int n=nums.size();
	res.resize(n,0);
   BST *root=new BST(nums[n-1]);
   for(int i=n-2;i>=0;i--)
   {
	   insert(root,nums[i],res[i]);
   }
   return res;
}

int main()
{
	int n;
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector<int>res;
	res=countSmaller(a);
	for(int i=0;i<n;i++) cout<<res[i]<<endl;
}