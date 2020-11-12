/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode *smallerHead = NULL, *smallerLast = NULL, *greaterHead = NULL, *greaterLast = NULL;
    
    while(A != NULL)
    {
        if(A->val < B)
        {
            if(smallerHead == NULL)
            {
                smallerHead = smallerLast = A;
            } else
            {
                smallerLast->next = A;
                smallerLast = A;
            }
        } else
        {
            if(greaterHead == NULL)
            {
                greaterHead = greaterLast = A;
            } else
            {
                greaterLast->next = A;
                greaterLast = A;
            }
        }
        
        A = A->next;
    }
    
	// If greater list is not empty, then set next of greater last to NULL to mark end of list.
    if(greaterLast != NULL)
    {
        greaterLast->next = NULL;
    }
    // If smaller list is empty, then return greater list head.
    if(smallerHead == NULL)
    {
        return greaterHead;
    } else
    {
        smallerLast->next = greaterHead;
        return smallerHead;
    }
}
