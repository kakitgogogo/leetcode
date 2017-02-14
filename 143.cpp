#include <iostream>
#include "list.h"
using namespace std;

class Solution
{
public:
	void reorderList(ListNode* head) 
	{
		if(!head || !head->next || !head->next->next) return;
		ListNode* ptr = head, * mid = head;
		int size = 0;

		while(ptr)
		{
			++size;
			ptr = ptr->next;
		}

		ptr = head;
		for(int i = 0; i < (size - 1) / 2; ++i)
		{
			ptr = ptr->next;
		}
		mid = ptr->next;
		ptr->next = NULL;

		mid = reverseList(mid);

		mergeList(head, mid);
	}

	ListNode* reverseList(ListNode* head)
	{
		ListNode* tmp, * next = NULL;
		while(head->next)
		{
			tmp = head->next;
			head->next = next;
			next = head;
			head = tmp;
		}
		head->next = next;
		return head;
	}

	void mergeList(ListNode* head1, ListNode* head2)
	{
		while(head1 && head2)
		{
			ListNode* tmp1 = head1->next, * tmp2 = head2->next;
			head1->next = head2;
			head2->next = tmp1;

			head1 = tmp1;
			head2 = tmp2;
		}
	}
};

int main()
{
	Solution S;

	ListNode* head1 = build_list({1,2,3,4,5,6});
	ListNode* head2 = build_list({1,2,3,4,5});

	print_list(head1);

	//head = S.reverseList(head);

	S.mergeList(head1, head2);

	print_list(head1);

	cout << "===========================" << endl;

	ListNode* head = build_list({1,2,3,4,5,6,7});

	S.reorderList(head);

	print_list(head);

	return 0;
}