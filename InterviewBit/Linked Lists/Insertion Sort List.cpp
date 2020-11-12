/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* insertSorted(ListNode* sorted_head, ListNode* new_node)
{
	// If the new_node should be the first element
    if(sorted_head == NULL || sorted_head->val > new_node->val)
    {
        new_node->next = sorted_head;
        sorted_head = new_node;
    } else
    {
        ListNode* curr = sorted_head;
        // Traverse the sorted head untill the next element is bigger than the new node.
        while(curr->next != NULL && curr->next->val <= new_node->val)
        {
            curr = curr->next;
        }
		// Make the next of current to the new nodes next
		// And place new node as next of current element.
        new_node->next = curr->next;
        curr->next = new_node;
    }
    
    return sorted_head;
}
 
ListNode* Solution::insertionSortList(ListNode* A) {
    ListNode *curr = A, *sorted_head = NULL, *curr_next;
    
    while(curr != NULL)
    {
		/*Store the next of current element as the next of current element 
		  may change while placing in sorted array.
		*/
        curr_next = curr->next;
        sorted_head = insertSorted(sorted_head, curr);
        curr = curr_next;
    }
    
    return sorted_head;
}
