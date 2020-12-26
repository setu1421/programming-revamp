/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void preOrderTraverse(TreeNode* root, vector<int> &res)
{
    if(root == NULL) return;
    
    preOrderTraverse(root->left, res);
    res.push_back(root->val);
    preOrderTraverse(root->right, res);
}
 
int Solution::kthsmallest(TreeNode* A, int B) {
    vector<int> res;
    preOrderTraverse(A, res);
    return res[B - 1];
}

// Another Approach: We don't have to traverse all the nodes.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void preOrderTraverse(TreeNode* root, int &B, int &smallest_value)
{
    if(root == NULL || B == 0) return;
    
    preOrderTraverse(root->left, B, smallest_value);
    
    if(B > 0)
    {
        B = B - 1;
        smallest_value = root->val;
    }
    
    preOrderTraverse(root->right, B, smallest_value);
}
 
int Solution::kthsmallest(TreeNode* A, int B) {
    int smallest_value;
    
    preOrderTraverse(A, B, smallest_value);
    
    return smallest_value;
}

