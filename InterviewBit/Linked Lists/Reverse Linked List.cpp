// Using Iterative Approach
ListNode* Solution::reverseList(ListNode* A) {
    ListNode *current, *prev, *next;
    current = A;
    prev = NULL;
    
    while(current != NULL)
    {
		// Store the next element address
        next = current->next;
		// Link the prev element as the next element of current
        current->next = prev;
		// Current will be the prev.
        prev = current;
		// Next will be the current.
        current = next;
    }
    
	// Finally, prev will be the head of the list.
    A = prev;
    
    return A;
}

// Using Recursion:
ListNode* head;

ListNode* reverseListUsingRecursion(ListNode* node)
{
	// for empty list
    if(node == NULL) return NULL;
	// if this is the last node, then make it as head and return that node.
    if(node->next == NULL)
    {
        head = node;
        return node;
    }
    
    ListNode* temp = reverseListUsingRecursion(node->next);
	// Make current node as the next of temp node.
    temp->next = node;
	// set NULL as the next of current node.
    node->next = NULL;
    
    return node;
}
 
ListNode* Solution::reverseList(ListNode* A) {
    
    reverseListUsingRecursion(A);
    return head;
}