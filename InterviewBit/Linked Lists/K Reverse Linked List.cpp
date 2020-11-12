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
    // returns the head and tail of the reverse sub list.
    return make_pair(prev, head);
}
 
ListNode* Solution::reverseList(ListNode* A, int B) {
    if(B == 1)
    {
        return A;
    }
    
    ListNode *curr = A, *main_prev = NULL, *curr_head, *new_head, *next;
    
    while(curr != NULL)
    {
        curr_head = curr;
        
        for(int i = 1; i < B; i++)
        {
            curr = curr->next;
        }
        // saving first element of the next sublist
        next = curr->next;
        // setting NULL will detach the current sublist from the next sublist
        curr->next = NULL;
        
        pair<ListNode*, ListNode*> rev = reverseSubList(curr_head);
        // if this is the first sublist, then update the new head.
        // Otherwise, add the new sublist with newlist.
        if(main_prev == NULL)
        {
            new_head = rev.first;
        } else
        {
            main_prev->next = rev.first;
        }
        // update the last element to the tail of the sublist for concating next sublist after that
        main_prev = rev.second;
        // set the current to the previously saved first element of next sublist.
        curr = next;
    }
    
    return new_head;
}
