/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(A == NULL || A->next == NULL)
    {
        return A;
    }
    
    ListNode *head = NULL, *prev = NULL, *curr = A;
    
    while(curr != NULL)
    {
        ListNode *temp = curr;
        bool duplicate_found = false;
        // Check if the current element has duplicates.
        while(curr->next != NULL && curr->next->val == temp->val)
        {
            curr = curr->next;
            duplicate_found = true;
        }
        // If the current element does not have duplicate, then take that element
		// Otherwise ignore the element.
        if(duplicate_found == false)
        {
			// if there is no previous element, then head of the list will start from this element.
            if(prev == NULL)
            {
                head = temp;
            } // Otherwise link the temp element as the previous's next.
			else
            {
                prev->next = temp;
            }
            // Finally, update the previous element.
            prev = temp;
        }
        
        curr = curr->next;
    }
    // Handles 1 2 4 4 condition where from previous element 2, the next element will be NULL.
    if(prev != NULL)
    {
        prev->next = NULL;
    }
    
    return head;
}
