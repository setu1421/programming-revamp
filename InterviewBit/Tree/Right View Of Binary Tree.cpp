/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// The Right view contains all nodes that are last nodes in their levels

vector<int> Solution::solve(TreeNode* A) {
    vector<int> res;
    queue<TreeNode*> q;
    
    q.push(A);
    
    while(!q.empty())
    {
        int size = q.size();
        
        while(size > 0)
        {
            TreeNode* curr = q.front();
            q.pop();
            
            if(curr->left != NULL)
            {
                q.push(curr->left);
            }
            
            if(curr->right != NULL)
            {
                q.push(curr->right);
            }
            
            if(size == 1)
            {
               res.push_back(curr->val);
            }
            
            size--;
        }
    }
    
    return res;
}
