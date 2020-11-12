/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int getListLength(ListNode* head)
{
    ListNode *curr = head;
    int count = 0;
    
    while(curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    
    return count;
}
 
ListNode* Solution::rotateRight(ListNode* A, int B) {
    int n = getListLength(A);
    // If B is a multiple of length of the list, 
	// then we will get the same list after rotating B times.
    if(B % n == 0)
    {
        return A;
    }
    // Find the tail of the rotated list.
    int diff = n - (B % n);
    
    ListNode *curr = A, *next, *new_head;
    
    for(int i = 1; i < diff; i++)
    {
        curr = curr->next;
    }
    // Head will be the next element of the current.
    new_head = curr->next;
	// End the list with the current element as tail of the list.
    curr->next = NULL;
    
    ListNode* temp = new_head;
    
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    // Next element of the last element of the list will be the current element.
	// For example: 1->2->3->4->5
	// We cut at 1->2->3->NULL and 4->5 will be added at the first. 4->5->1->2->3->NULL
    temp->next = A;
    
    return new_head;
}
