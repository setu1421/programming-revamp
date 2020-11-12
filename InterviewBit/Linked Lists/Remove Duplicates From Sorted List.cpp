/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode *curr = A, *prev = A;
    
    while(curr != NULL)
    {
        if(prev->val == curr->val)
        {
            curr = curr->next;
        } else
        {
			// if not same element, then set the current element as the next of last distinct previous element.
            prev->next = curr;
			// set current element as the previous element.
            prev = curr;
            curr = curr->next;
        }
    }
    // Handles 1->2->2->2 by setting next of first 2 as NULL
    prev->next = NULL;
    
    return A;
}
