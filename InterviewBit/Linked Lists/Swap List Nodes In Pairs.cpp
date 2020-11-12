/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
pair<ListNode*, ListNode*> reverseSubList(ListNode* head)
{
    ListNode *curr = head, *prev = NULL, *next;
    
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return make_pair(prev, head);
}
 
ListNode* Solution::swapPairs(ListNode* A) {
    ListNode *curr = A, *main_prev = NULL, *next, *curr_head, *new_head;
    
    while(curr != NULL)
    {
        curr_head = curr;
        
        for(int i = 1; curr->next != NULL && i < 2; i++)
        {
            curr = curr->next;
        }
        
        next = curr->next;
        curr->next = NULL;
        
        pair<ListNode*, ListNode*> rev = reverseSubList(curr_head);
        
        if(main_prev == NULL)
        {
            new_head = rev.first;
        } else
        {
            main_prev->next = rev.first;
        }
        
        main_prev = rev.second;
        curr = next;
    }
    
    return new_head;
}

// Another Approach: https://www.youtube.com/watch?v=jiLloHVmLDc

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* Solution::swapPairs(ListNode* A) {
    if(A == NULL || A->next == NULL)
    {
        return A;
    }
    
    ListNode *prev = A, *curr = A->next, *next;
    ListNode *new_head = curr;
    
    while(true)
    {
        next = curr->next;
        curr->next = prev;
        // Handles if there is no set of next pairs. 1->2->NULL (next is NULL)
        // Handles if there is odd element present in the list. 1->2->3->NULL (next is 3)
        if(next == NULL || next->next == NULL)
        {
            prev->next = next;
            break;
        }
		
        prev->next = next->next;
        prev = next;
        curr = next->next;
    }

    
    return new_head;
}

