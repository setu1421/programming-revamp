/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* removeHalfNodes(TreeNode* root)
{
    if(root == NULL || (root->left == NULL && root->right == NULL))
    {
        return root;
    }
    
    root->left = removeHalfNodes(root->left);
    root->right = removeHalfNodes(root->right);
    // Remove the node which has one child missing and return the non missing child.
    if(root->left == NULL ^ root->right == NULL)
    {
        if(root->left != NULL)
        {
            return root->left;
        } else
        {
            return root->right;
        }
    }
    // otherwise, return the root as both the children are present.
    return root;
}
 
TreeNode* Solution::solve(TreeNode* A) {
    if(A == NULL) return A;
    
    TreeNode* head = removeHalfNodes(A);

    return head;
}


// Another Approach:

TreeNode* Solution::solve(TreeNode* A) {
    if(A->left == NULL && A->right == NULL)return A;
    if(A->left == NULL)
        return solve(A->right);
    if(A->right == NULL)
        return solve(A->left);
    A->left = solve(A->left);
    A->right = solve(A->right);
    return A;
    
}