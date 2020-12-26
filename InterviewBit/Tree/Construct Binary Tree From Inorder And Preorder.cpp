/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// The preorder has the root at the first index of the binary tree. And we can find that node in the inorder tree. So, from that index,
// the left part will be the left subtree and the right part will the right subtree of root.
 
TreeNode* buildTreeHelper(int start, int end, int &pIndex, vector<int> &B, unordered_map<int, int> &mp)
{
    if(start > end)
    {
        return NULL;
    }
    
    int rootValue = B[pIndex];
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
    
    int pIndex = 0;
    return buildTreeHelper(0, n - 1, pIndex, B, mp);
}
