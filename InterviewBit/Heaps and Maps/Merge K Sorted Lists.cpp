/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*> >, greater<pair<int, ListNode*> > > pq;
    
    for(int i = 0; i < A.size(); i++)
    {
        ListNode* head = A[i];
        ListNode* curr = head;
        
        while(curr != NULL)
        {
            pq.push(make_pair(curr->val, curr));
            curr = curr->next;
        }
    }
    
    ListNode* new_head = new ListNode(-1);
    ListNode* curr = new_head;
    
    while(pq.size() > 0)
    {
        pair<int, ListNode*> top = pq.top();
        pq.pop();
        
        curr->next = top.second;
        curr = curr->next;
    }
    
    curr->next = NULL;
    
    return new_head->next;
}

/* Efficient Approach: 
	1. We will only create a min_heap using the head nodes first.
	2. Then pop min element and push the next element of that min element into the heap.
That way, the heap size remains small.	
/*

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Compare
{
    public:
    bool operator()(ListNode* l1, ListNode* l2)
    {
        return l1->val > l2->val;
    }
};

ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
    
    for(int i = 0; i < A.size(); i++)
    {
        if(A[i] != NULL)
        {
            pq.push(A[i]);
        }
    }
    
    ListNode* new_head = new ListNode(-1);
    ListNode* temp = new_head;
    
    while(!pq.empty())
    {
        temp->next = pq.top();
        temp = temp->next;
        pq.pop();
        
        if(temp->next != NULL)
        {
            pq.push(temp->next);
        }
    }
    
    return new_head->next;
}

