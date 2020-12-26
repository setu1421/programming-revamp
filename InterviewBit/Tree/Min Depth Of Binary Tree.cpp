/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 

 
int Solution::minDepth(TreeNode* A) {
    if(A == NULL)
    {
        return 0;
    }
    // Reached to leaf node, so return 1.
    if(A->left == NULL && A->right == NULL)
    {
        return 1;
    }
    
    int leftDepth = minDepth(A->left);
    int rightDepth = minDepth(A->right);
    
    // Since the path has to end on a leaf node, so, we will take that depth which is ending
    // on a leaf node.
    if(leftDepth == 0 || rightDepth == 0)
    {
        return 1 + (leftDepth ^ rightDepth);
    } // if both the path ending on a leaf node, then take the minimum depth from both.
    else
    {
        return min(leftDepth, rightDepth) + 1;
    }
}
