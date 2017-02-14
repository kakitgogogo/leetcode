#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* build_list(initializer_list<int>list)
{
	if(list.size() == 0) return NULL;
	auto iter = list.begin();
	ListNode* head = new ListNode(*iter++), * pre = head;
	while(iter != list.end())
	{
		pre->next = new ListNode(*iter++);
		pre = pre->next;
	}
	return head;
}

void print_list(ListNode* head)
{
	ListNode* cur = head;
	while(cur)
	{
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;
}