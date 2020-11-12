/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*  
 The idea is to connect the odd nodes and even nodes. Even nodes will be connected in reverse order. Finally join the two list.
 For example: 1->2->3->4->5->6
 odd: 1->3->5
 even: 6->4->2 (in reversed)
 add: 1->6->3->4->5->2 
 */
 
ListNode* Solution::solve(ListNode* A) {
    if(A == NULL || A->next == NULL)
    {
        return A;
    }
    
    ListNode *curr = A->next, *even_head = NULL, *odd_head = A, *odd = A, *next;
    
    while(curr != NULL)
    {
        next = curr->next;
        odd->next = next;
        odd = next;
        curr->next = even_head;
        even_head = curr;
        
        if(next == NULL) break;
        curr = odd->next;
    }
    
    //Merge the odd and reversed even list
    ListNode *l1 = odd_head, *l2 = even_head, *l1Next, *l2Next;
    
    while(l1 != NULL && l2 != NULL)
    {
        l1Next = l1->next;
        l2Next = l2->next;
        
        l1->next = l2;
        
        if(l1Next == NULL) break;
        
        l2->next = l1Next;
        
        l1 = l1Next;
        l2 = l2Next;
    }
    
    return A;
}
