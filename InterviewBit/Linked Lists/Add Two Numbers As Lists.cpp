/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode* new_head = new ListNode(-1);
    ListNode* temp = new_head;
    int carry = 0;
    // Run until A is NULL, B is NULL and carry 0. If carry is 1, we should add to the last. 
    while(A || B || carry)
    {
        int sum = (A ? A->val : 0) + (B ? B->val : 0) + carry;
        carry = sum / 10;
        
        temp->next = new ListNode(sum % 10);
        temp = temp->next;
        // Set A or B to it's next element only if A or B is not NULL.
        A = (A ? A->next: NULL);
        B = (B ? B->next: NULL);
    }
    // Finally, remove the fast element and return head.
    return new_head->next;
}
