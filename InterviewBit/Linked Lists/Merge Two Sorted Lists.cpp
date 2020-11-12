/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    if(A == NULL) return B;
    if(B == NULL) return A;
    
    ListNode* newHead;
    
    if(A->val <= B->val)
    {
        newHead = A;
        A = A->next;
    } else
    {
        newHead = B;
        B = B->next;
    }
    
    ListNode* temp = newHead;
    
    while(A != NULL && B != NULL)
    {
        if(A->val <= B->val)
        {
            temp->next = A;
            temp = A;
            A = A->next;
        } else
        {
            temp->next = B;
            temp = B;
            B = B->next;
        }
    }
    
    if(A == NULL) temp->next = B;
    if(B == NULL) temp->next = A;
    
    return newHead;
}
