/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int> res;
    stack<TreeNode*> st;
    
    TreeNode* curr = A;
    
    while(curr != NULL || !st.empty())
    {
		// Go to the left node first and push it to stack untill current node is null.
        while(curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        
        curr = st.top();
        // if the current node has right child, then visit right childs first before root.
        if(curr->right != NULL)
        {
            curr = curr->right;
        } // If the current node has no right child, then visit current node.
		else
        {
            res.push_back(curr->val);
            st.pop();
            // if the current node is in right of the stack top node, 
			// then we have visited all the nodes of right subtree of stack top node.
            while(!st.empty() && st.top()->right == curr)
            {
                curr = st.top();
                res.push_back(curr->val);
                st.pop();
            }
            // the next current node will be the right node of stack top.  
            if(!st.empty())
            {
                curr = st.top()->right;
            } else
            {
                curr = NULL;
            }
            
        }
    }
    
    return res;
}
