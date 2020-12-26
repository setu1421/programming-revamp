/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* sortedArrayToBSTHelper(const vector<int> &A, int i, int j)
{
    if(i > j)
    {
        return NULL;
    }
    
    int mid = (i + j) / 2;
    
    TreeNode* root = new TreeNode(A[mid]);
    root->left = sortedArrayToBSTHelper(A, i, mid - 1);
    root->right = sortedArrayToBSTHelper(A, mid + 1, j);
    
    return root;
}
 
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    return sortedArrayToBSTHelper(A, 0, A.size() - 1);
}
