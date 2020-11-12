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

ListNode* sortedMerge(ListNode* &head1, ListNode* &head2)
{
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;
    
    ListNode *newHead, *temp;
    
    if(head1->val <= head2->val)
    {
        temp = head1;
        head1 = head1->next;
    } else
    {
        temp = head2;
        head2 = head2->next;
    }
    
    newHead = temp;
    
    while(head1 != NULL && head2 != NULL)
    {
        if(head1->val <= head2->val)
        {
            temp->next = head1;
            temp = head1;
            head1 = head1->next;
        } else
        {
            temp->next = head2;
            temp = head2;
            head2 = head2->next;
        }
    }
    
    if(head1 == NULL) temp->next = head2;
    if(head2 == NULL) temp->next = head1;
    
    return newHead;
}

void mergeSort(ListNode* &head)
{
    if(head->next != NULL)
    {
        ListNode* head1;
        ListNode* head2 = head;
        
        int n = getLength(head);
        for(int i = 0; i < n/2; i++)
        {
            head1 = head2;
            head2 = head2->next;
        }
        
        head1->next = NULL;
        head1 = head;
        
        mergeSort(head1);
        mergeSort(head2);
        
        head = sortedMerge(head1, head2);
    }
}
 
ListNode* Solution::sortList(ListNode* A) {
    //Base Case: List with zero or one element.
    if(A == NULL || A->next == NULL)
    {
        return A;
    }
    
    mergeSort(A);
    
    return A;
}

// Sorted Merge in Recursion
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
 
ListNode* sortedMerge(ListNode* &head1, ListNode* &head2)
{
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;
    
    ListNode* newHead;
    
    if(head1->val <= head2->val)
    {
        newHead = head1;
        newHead->next = sortedMerge(head1->next, head2);
    } else
    {
        newHead = head2;
        newHead->next = sortedMerge(head1, head2->next);
    }
    
    return newHead;
}
 
void mergeSort(ListNode* &head)
{
    if(head->next != NULL)
    {
        ListNode* head1;
        ListNode* head2 = head;
        
        int n = getLength(head);
        for(int i = 0; i < n/2; i++)
        {
            head1 = head2;
            head2 = head2->next;
        }
        
        head1->next = NULL;
        head1 = head;
        
        mergeSort(head1);
        mergeSort(head2);
        
        head = sortedMerge(head1, head2);
    }
}
 
ListNode* Solution::sortList(ListNode* A) {
    //Base Case: List with zero or one element.
    if(A == NULL || A->next == NULL)
    {
        return A;
    }
    
    mergeSort(A);
    
    return A;
}
