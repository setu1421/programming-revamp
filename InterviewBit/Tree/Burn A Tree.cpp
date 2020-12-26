// https://www.geeksforgeeks.org/minimum-time-to-burn-a-tree-starting-from-a-leaf-node/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
struct Info
{
    int t;
    int lDepth, rDepth;
    bool contains;
    
    Info()
    {
        t = -1;
        lDepth = rDepth = 0;
        contains = false;
    }
};

void calculateTime(TreeNode* root, Info &info, int target, int &res)
{
    if(root == NULL) return;
    
    if(root->left == NULL && root->right == NULL)
    {
        if(root->val == target)
        {
            info.t = 0;
            info.contains = true;
        }
        
        return;
    }
    
    Info leftInfo;
    calculateTime(root->left, leftInfo, target, res);
    
    Info rightInfo;
    calculateTime(root->right, rightInfo, target, res);
    
    info.t = (leftInfo.contains) ? (1 + leftInfo.t) : -1;
    if(info.t == -1)
    {
       info.t = (rightInfo.contains) ? (1 + rightInfo.t) : -1; 
    }
    
    info.contains = (leftInfo.contains || rightInfo.contains);
    
    info.lDepth = (root->left) ? (1 + max(leftInfo.lDepth, leftInfo.rDepth)) : 0;
    info.rDepth = (root->right) ? (1 + max(rightInfo.lDepth, rightInfo.rDepth)) : 0;
    
    
    if(info.contains)
    {
        if(leftInfo.contains)
        {
            res = max(res, info.t + info.rDepth);
        } else
        {
            res = max(res, info.t + info.lDepth);
        }
    }
}
 
int Solution::solve(TreeNode* A, int B) {
    Info info;
    int res;
    
    calculateTime(A, info, B, res);
    
    return res;
}
