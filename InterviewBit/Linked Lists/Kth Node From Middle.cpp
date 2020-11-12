/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* A, int B) {
    ListNode *slow = A, *fast = A;
    int count = 1;
    // Find the middle point
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        count++;
    }
    // If B elements not present from the middle node
    if(B > count - 1)
    {
        return -1;
    }
    
    int diff = count - B - 1;
    
    for(int i = 0; i < diff; i++)
    {
        A = A->next;
    }
    
    return A->val;
}
