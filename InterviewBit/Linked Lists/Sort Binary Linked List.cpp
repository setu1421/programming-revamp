/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    ListNode* head = A;
    
    while(A != NULL && A->val == 0)
    {
        A = A->next;
    }
    
    ListNode *temp = A;
    
    while(A != NULL)
    {
        // if the value is zero, then swap the value with first one.
        if(A->val == 0)
        {
            temp->val = 0;
            A->val = 1;
			// move the current one's place.
            temp = temp->next;
        }
        
        A = A->next;
    }
    
    return head;
}
