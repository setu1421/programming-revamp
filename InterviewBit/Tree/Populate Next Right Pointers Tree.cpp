/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
// https://www.youtube.com/watch?v=5GS17j6tcOk&t=700s 
 
void Solution::connect(TreeLinkNode* A) {
    TreeLinkNode* head = A;
    
    while(head != NULL)
    {
        TreeLinkNode *curr = NULL, *curr_level_head = NULL;
        
        while(head != NULL)
        {
            if(head->left != NULL)
            {
                if(curr == NULL)
                {
                    curr = head->left;
                    curr_level_head = head->left;
                } else
                {
                    curr->next = head->left;
                    curr = curr->next;
                }
            }
            
            if(head->right != NULL)
            {
                if(curr == NULL)
                {
                    curr = head->right;
                    curr_level_head = head->right;
                } else
                {
                    curr->next = head->right;
                    curr = curr->next;
                }
            }
            
            head = head->next;
        }
        
        head = curr_level_head;
    }
}
