/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int Solution::solve(TreeNode* A) {
    queue<TreeNode*> q;
    
    q.push(A);
    int max_sum = A->val;
    
    while(!q.empty())
    {
        int size = q.size();
        int level_sum = 0;
        
        while(size--)
        {
            TreeNode* top = q.front();
            q.pop();
            
            level_sum += top->val;
            
            if(top->left != NULL)
            {
                q.push(top->left);
            }
            
            if(top->right != NULL)
            {
                q.push(top->right);
            }
        }
        
        max_sum = max(max_sum, level_sum);
    }
    
    return max_sum;
}