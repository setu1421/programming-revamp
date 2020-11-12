/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
    Given List: 1->2->3->4->5->6
    Make Two List: 1->2-3
                   4->5->6
	Reverse the second list: 6->5->4
    Add the two list: 	1->2-3
	                    6->5->4
	Final List: 1->6->2->5->3->4					
	                     
				  
*/
ListNode* reverseList(ListNode* head)
{
    ListNode *curr = head, *prev = NULL, *next;
    
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}
 
ListNode* Solution::reorderList(ListNode* A) {
    if(A == NULL || A->next == NULL)
    {
        return A;
    }
    
    ListNode* slow = A, *fast = A, *prev = NULL;
    // Break the list into two halves. 
    while(fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    prev->next = NULL;
    
	// Reverse the second sublist.
    ListNode *l1 = A;
    ListNode *l2 = reverseList(slow);
    ListNode *l1Next, *l2Next;
    
	// Finally merge the two sublist into one list.
    while(l1 != NULL)
    {
		// Save the next nodes of both sublist.
        l1Next = l1->next;
        l2Next = l2->next;
        
        l1->next = l2;
        // if next element of first list is empty, then we are done.
        if(l1Next == NULL)
        {
            break;
        }
        // Put the next element of l2 as the next element of l1 and make l1Next as the l1.
        l2->next = l1Next;
        l1 = l1Next;
        l2 = l2Next;
    }
    
    return A;
}
