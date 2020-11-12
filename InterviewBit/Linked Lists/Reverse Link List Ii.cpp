/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Reverse the sublist and return the head of the sublist.
ListNode* reverseList(ListNode* head, int count)
{
    ListNode *curr = head, *prev = NULL, *next = NULL;
    
    while(count >=0 && curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        
        count--;
    }
    // Link the last element of the reversed list with the next element.
    head->next = next;
    
    return prev;
}
 
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    ListNode *curr = A, *list_prev = NULL;
    // Go to the start node of reversing.
    for(int i = 1; i < B; i++)
    {
        list_prev = curr;
        curr = curr->next;
    }
    
    ListNode *rev_head = reverseList(curr, C - B);
    // if there is no element present before, then reverse head will be the head of the list.
    if(list_prev == NULL)
    {
        A = rev_head;
    } // Otherwise, reverse head will be the next element of the previous element of the list.
	else
    {
        list_prev->next = rev_head;
    }
    
    return A;
}
