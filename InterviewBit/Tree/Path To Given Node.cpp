/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
bool Find(vector<int> &res, TreeNode* root, int B)
{
    if(root == NULL)
    {
        return false;
    }
    // Push the node of the path
    res.push_back(root->val);
    
    if(root->val == B)
    {
        return true;
    }
    
    bool leftFound = Find(res, root->left, B);
    
    if(leftFound)
    {
        return true;
    } else
    {
        bool rightFound = Find(res, root->right, B);
        // if not found in left or right sub tree, then pop the node of this path.
        if(!rightFound)
        {
            res.pop_back();
            return false;
        }
        
        return true;
    }
}

vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> res;
    
    Find(res, A, B);
    
    return res;
    
}
