// https://www.youtube.com/watch?v=b8YKQqPG9Gs&t=341s
// Time Complexity: O(n)

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
pair<int, int> findMaxElement(vector<int> &A, int i, int j)
{
    int max_element = INT_MIN, index = -1;
    
    for(int k = i; k <= j; k++)
    {
        if(A[k] > max_element)
        {
            max_element = A[k];
            index = k;
        }
    }
    
    return make_pair(max_element, index);
}

TreeNode* buildTreeHelper(vector<int> &A, int i, int j)
{
    if(i > j)
    {
        return NULL;
    }
    
    pair<int, int> max_element = findMaxElement(A, i, j);
    
    TreeNode* root = new TreeNode(max_element.first);
    root->left = buildTreeHelper(A, i, max_element.second - 1);
    root->right = buildTreeHelper(A, max_element.second + 1, j);
    
    return root;
}
 
TreeNode* Solution::buildTree(vector<int> &A) {
    return buildTreeHelper(A, 0, A.size() - 1);
}
