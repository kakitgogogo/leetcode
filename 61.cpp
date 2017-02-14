#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include "list.h"
using namespace std;

class Solution
{
public:
	ListNode* rotateRight(ListNode* head, int k)
	{
		if(!head) return NULL;
		int size = 0;
		ListNode* ptr = head, * tail, * pre;
		do
		{
			size++;
			tail = ptr;
		}
		while(ptr = ptr->next);

		k = size - (k % size);
		if(k == size) return head;

		ptr = head;
		for(int i = 0; i < k; ++i)
		{
			pre = ptr;
			ptr = ptr->next;
		}

		pre->next = NULL;
		tail->next = head;
		head = ptr;
		return head;
	}
};

int main()
{
	Solution S;
	ifstream fin("input.txt");

	ListNode* head = build_list({1,2,3,4,5,6,7,8,9});

	int k;

	print_list(head);

	cin >> k;

	head = S.rotateRight(head, k);

	print_list(head);

	return 0;
}