// https://www.techiedelight.com/construct-binary-tree-from-inorder-postorder-traversals/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* buildTreeHelper(int start, int end, int &pIndex, vector<int> &postOrder, unordered_map<int, int> &mp)
{
    if(start > end)
    {
        return NULL;
    }
    
    int rootValue = postOrder[pIndex--];
    TreeNode* root = new TreeNode(rootValue);
    int inOrderPos = mp[rootValue];
    root->right = buildTreeHelper(inOrderPos + 1, end, pIndex, postOrder, mp);
    root->left = buildTreeHelper(start, inOrderPos - 1, pIndex, postOrder, mp);
    
    return root;
}
 
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int n = A.size();
    
    if(n == 0)
    {
        return NULL;
    }
    
    unordered_map<int, int> mp;
    
    for(int i = 0; i < n; i++)
    {
        mp.insert(make_pair(A[i], i));
    }
    
    int pIndex = n - 1;
    return buildTreeHelper(0, n - 1, pIndex, B, mp);
}
