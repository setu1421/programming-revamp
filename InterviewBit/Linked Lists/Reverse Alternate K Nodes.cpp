/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Reverse the sub list and return the head and tail of the sublist. 
pair<ListNode*, ListNode*> reverseList(ListNode* head)
{
    ListNode *curr = head, *prev = NULL, *next = NULL;
    
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return make_pair(prev, head);
}

ListNode* Solution::solve(ListNode* A, int B) {
    ListNode *newHead = NULL, *mainPrev = NULL, *curr = A, *currNext, *currHead;
    bool isAlternate = true;
    
    while(curr != NULL)
    {
        currHead = curr;
        for(int i = 1; i < B; i++)
        {
            curr = curr->next;
        }
        // save the next element of the next sublist window.
        currNext = curr->next;
		// End the current sub list
        curr->next = NULL;
        
        if(isAlternate)
        {
            isAlternate = false;
            pair<ListNode*, ListNode*> mp = reverseList(currHead);
			// if head is null, then update the head.
			// Otherwise, head of sublist will be the next element of the last element of previous sublist window.
            if(newHead == NULL)
            {
                newHead = mp.first;
            } else
            {
                mainPrev->next = mp.first;
            }
            // Update the last element of previous sublist window.
            mainPrev = mp.second;
        } // No need to reverse. Just skip B items and add a sublist window.
		else
        {
            isAlternate = true;
            mainPrev->next = currHead;
            mainPrev = curr;
        }
        
        curr = currNext;
    }
    
    return newHead;
}

// Another Solution: Using recursion

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverseList(ListNode* A, int B) {
    ListNode *curr = A, *prev = NULL, *next = NULL;
    int cnt =0;
    
     while(cnt < B && curr) {
         next = curr->next;
         curr->next = prev;
         prev = curr;
         curr = next;
         cnt++;
     }
	 // If next sublist is present, then skip one sublist and then reverse another sublist and add with the previus sublist.
     if(next) {
         cnt = 0;
         A->next = next;
         while(cnt < B && A)
         {
             A = A->next;
             cnt++;
         }
         
         if(A != NULL & A->next != NULL)
         {
            A->next = reverseList(A->next, B); 
         }
     }
	 // prev is the new head of the sublist
     return prev;
}

ListNode* Solution::solve(ListNode* A, int B) {
    return reverseList(A, B);
}

