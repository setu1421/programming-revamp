/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int getLength(ListNode* node)
{
    int count = 0;
    
    while(node != NULL)
    {
        count++;
        node = node->next;
    }
    
    return count;
}

ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    int m = getLength(A);
    int n = getLength(B);
    
    if(m < n)
    {
        ListNode *temp = A;
        A = B;
        B = temp;
    }
    
    int diff = abs(m - n);
    for(int i = 0; i < diff; i++)
    {
        A = A->next;
    }
    
    while(A != NULL && B != NULL)
    {
        if(A == B)
        {
            return A;
        }
        
        A = A->next;
        B = B->next;
    }
    
   return NULL;
}
