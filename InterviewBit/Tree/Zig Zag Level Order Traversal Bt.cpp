/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int> > res;
    queue<TreeNode*> q;
    
    if(A == NULL)
    {
        return res;
    }
    
    q.push(A);
    res.push_back({A->val});
    
    bool fromRight = true;
    
    while(!q.empty())
    {
        int size = q.size();
        vector<int> temp;
        
        while(size--)
        {
            TreeNode* curr = q.front();
            q.pop();
            
            if(curr->left != NULL)
            {
                temp.push_back(curr->left->val);
                q.push(curr->left);
            }
            
            if(curr->right != NULL)
            {
                temp.push_back(curr->right->val);
                q.push(curr->right);
            }
        }
        
        if(temp.size() > 0)
        {
            if(fromRight)
            {
                reverse(temp.begin(), temp.end());
            }
        
            res.push_back(temp);
        }
        
        fromRight = !fromRight;
    }
    
    return res;
}
