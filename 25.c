struct ListNode* reverseKGroup(struct ListNode* head, int k)
{
	if(head == NULL) return NULL;
	int i;
	struct ListNode *tmp = head;
	for(i = 0; i < k && tmp; ++i)
	{
		tmp = tmp->next;
	}
	if(i != k) return head;
	struct ListNode *prev = head, *tail = head;
	for(i = 0; i < k && head; ++i)
	{
		tmp = head->next;
		head->next = prev;
		prev = head;
		head = tmp;
	}
	tail->next = reverseKGroup(head, k);
	return prev;
}
