/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* right(TreeNode* root)
{
    if(root == NULL || root->right == NULL) return root;
    
    return right(root->right);
}
 
TreeNode* Solution::flatten(TreeNode* A) {
    if(A == NULL) return NULL;
    
    TreeNode* left_top = flatten(A->left);
    TreeNode* right_top = flatten(A->right);
    
    if(left_top)
    {
        TreeNode* left_last = right(left_top);
        left_last->right = right_top;
        A->right = left_top;
        A->left = NULL;
    }
    
    return A;
}
