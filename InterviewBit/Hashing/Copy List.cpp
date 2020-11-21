/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    RandomListNode *new_head = new RandomListNode(-1);
    RandomListNode *temp = new_head, *curr = A;
    
    unordered_map<RandomListNode*, RandomListNode*> mp;
    
    while(curr != NULL)
    {
        RandomListNode *a, *b;
        // Check if the current node's deep copy is present or not in the hash.
		// If not present, then create a new node with the current node's value.
        if(mp.find(curr) == mp.end())
        {
            a = new RandomListNode(curr->label);
            mp[curr] = a;
        } else
        {
            a = mp[curr];
        }
        // Check if the current nodes random node deep copy is present or not in the hash
        if(curr->random == NULL)
        {
            b = NULL;
        } else if(mp.find(curr->random) == mp.end())
        {
            b = new RandomListNode(curr->random->label);
            mp[curr->random] = b;
        } else
        {
            b = mp[curr->random];
        }
        // Set the next node of temp to a and random node of a to b.
        temp->next = a;
        a->random = b;
        // update temp to a and curr to current's next.
        temp = a;
        curr = curr->next;
    }
    
    return new_head->next;
}
