/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode* head;
 
void reverse(ListNode* node)
{
    if(node->next == NULL)
    {
        head = node;
        return;
    }
    
    reverse(node->next);
    
    node->next->next = node;
    node->next = NULL;
}
 
ListNode* Solution::reverseList(ListNode* A) {
    if(A == NULL || A->next == NULL)
    {
        return A;
    }
    
    reverse(A);
    
    return head;
}
