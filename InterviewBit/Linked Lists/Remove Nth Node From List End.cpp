/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int getLength(ListNode* head)
{
    ListNode* curr = head;
    int count = 0;
    
    while(curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    
    return count;
}

ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    int n = getLength(A);
    // Remove head node if B >= n
    if(B >= n)
    {
        A = A->next;
        return A;
    }
    
    int posFromFirst = n - B;
    ListNode* curr = A;
	// Go to the previous element of the element to be removed.
    for(int i = 0; i < posFromFirst - 1; i++)
    {
        curr = curr->next;
    }
    // Remove the element.
    curr->next = curr->next->next;
    
    return A;
}

// Another Approach: Using Fast Pointers
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    
    ListNode *slow, *fast;
    fast = A;
    slow = A;
    // Move ahead B elements first.
    while(B > 0 && fast != NULL)
    {
        fast = fast->next;
        B--;
    }
    // If we have moved B or more than B elements, then remove first element.
    if(fast == NULL)
    {
        return slow->next;
    }
    // Move slow and fast pointers untill the last element.
    while(fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    // Remove the element after the slow element.
    slow->next = slow->next->next;
    
    return A;
}
