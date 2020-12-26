/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A) {
    vector<int> res;
    queue<TreeNode*> q;
    
    TreeNode* curr;
    q.push(A);
    
    while(!q.empty())
    {
        int size = q.size();
        
        while(size--)
        {
            curr = q.front();
            q.pop();
            while(curr != NULL)
            {
                res.push_back(curr->val);
                if(curr->left != NULL)
                {
                    q.push(curr->left);
                }
                curr = curr->right;
            }
        }
    }
    
    return res;
}
