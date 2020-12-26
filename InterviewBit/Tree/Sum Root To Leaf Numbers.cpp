/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
#define MOD 1003 

void helper(TreeNode* root, long long &totalSum, long long pathSum)
{
    if(root == NULL)
    {
        return;
    }
    
    pathSum = (pathSum * 10 + root->val) % MOD;
    // leaf node found
    if(root->left == NULL && root->right == NULL)
    {
        totalSum = (totalSum + pathSum) % MOD;
        
        return;
    }
    
    
    helper(root->left, totalSum, pathSum);
    helper(root->right, totalSum, pathSum);
}
 
int Solution::sumNumbers(TreeNode* A) {
    long long totalSum = 0;
    
    helper(A, totalSum, 0);
    
    return totalSum;
}
