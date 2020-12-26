/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> res;
    stack<TreeNode*> st;
    
    TreeNode* curr = A;
    
    while(curr != NULL || !st.empty())
    {
        // visit the current node. Push the right node of current node in stack and go left.
        while(curr != NULL)
        {
            res.push_back(curr->val);
            if(curr->right != NULL)
            {
                st.push(curr->right);
            }
            curr = curr->left;
        }
        // if all the left and current node is visited, 
        // current will be stack top(which is the right node)
        if(!st.empty())
        {
            curr = st.top();
            st.pop(); 
        } else
        {
            curr = NULL;
        }
    }
    
    return res;
}
