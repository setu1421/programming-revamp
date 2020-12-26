/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int hasPathSumHelper(TreeNode* root, int B, int sum)
{
    if(root == NULL)
    {
        return 0;
    }
    
    sum = sum + root->val;
    // if sum is equal to B and this is the leaf node, so return true.
    if(sum == B && root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    // Check if going in left path or right path returns true or not.
    return (hasPathSumHelper(root->left, B, sum) || hasPathSumHelper(root->right, B, sum));
}

int Solution::hasPathSum(TreeNode* A, int B) {
    return hasPathSumHelper(A, B, 0);
}
