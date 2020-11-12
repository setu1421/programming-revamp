/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// Using Floyd's cycle detection algorithm
// https://www.youtube.com/watch?v=LUm2ABqAs1w 
ListNode* Solution::detectCycle(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    ListNode *slow = A, *fast = A;
    bool cyclePresent = false;
    
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast)
        {
            cyclePresent = true;
            break;
        }
    }
    
    if(!cyclePresent)
    {
        return NULL;
    }
    
    slow = A;
    
    while(slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow;
}
