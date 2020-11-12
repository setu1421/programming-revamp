/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
int getLength(ListNode* node)
{
    ListNode* curr = node;
    int count = 0;
    
    while(curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    
    return count;
}

void reverseList(ListNode* &head)
{
    ListNode *prev = NULL, *curr = head, *curr_next;
    
    while(curr != NULL)
    {
		// save the next element of current.
        curr_next = curr->next;
		// set prev as the next of current element.
        curr->next = prev;
		// Now, the previous element will be the current element
        prev = curr;
		// Update the current to it's next element.
        curr = curr_next;
    }
    
    head = prev;
}

int Solution::lPalin(ListNode* A) {
    if(A->next == NULL) return 1;
    
    ListNode *head1, *head2;
    int n = getLength(A);
    head1 = head2 = A;
    // Move the head2 to the second half of the list.
    for(int i = 0; i < n / 2; i++)
    {
        head2 = head2->next;
    }
	// if no of elements are odd, then skip the mid element.
    if(n & 1)
    {
        head2 = head2->next;
    }
    // Reverse the second half of the list.
    reverseList(head2);
    
	// Check the first half with reversed second half.
    while(head2 != NULL)
    {
        if(head1->val != head2->val)
        {
            return 0;
        } else
        {
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    
    return 1;
}
