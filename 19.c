struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
	int i = 0;
	struct ListNode* list_ptr_array[1000];
	struct ListNode* tmp = head;
	
	while(tmp)
	{
		list_ptr_array[i++] = tmp;
		tmp = tmp->next;
	}
	if(i - n == 0)
	{
		tmp = head->next;
		free(head);
		return tmp;
	}
	else
	{
		struct ListNode* remove_node_prev = list_ptr_array[i - n - 1];
		tmp = remove_node_prev->next;
		remove_node_prev->next = remove_node_prev->next->next;
		free(tmp);
		return head;		
	}	
}
