/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int FindHeightofTree(TreeNode* root, bool &flagBalanced)
{
    if(root == NULL) return -1;
    
    int leftSubTreeHeight = FindHeightofTree(root->left, flagBalanced);
    int rightSubTreeHeight = FindHeightofTree(root->right, flagBalanced);
    
    if(flagBalanced && abs(leftSubTreeHeight - rightSubTreeHeight) > 1)
    {
        flagBalanced = false;
    }
    
    return max(leftSubTreeHeight, rightSubTreeHeight) + 1;
}


int Solution::isBalanced(TreeNode* A) {
    bool flagBalanced = true;
    
    FindHeightofTree(A, flagBalanced);
    
    return flagBalanced;
}
