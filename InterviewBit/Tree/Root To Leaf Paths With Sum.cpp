/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void pathSumHelper(TreeNode* root, vector<int> path, vector<vector<int> > &ans, int sum, int B)
{
    if(root == NULL)
    {
        return;
    }
    
    sum = sum + root->val;

    
    path.push_back(root->val);
    
    if(sum == B && root->left == NULL && root->right == NULL)
    {
        ans.push_back(path);
    }
    
    pathSumHelper(root->left, path, ans, sum, B);
    pathSumHelper(root->right, path, ans, sum, B);
    
}
 
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int> > res;
    vector<int> path;
    
    pathSumHelper(A, path, res, 0, B);
    
    return res;
}
