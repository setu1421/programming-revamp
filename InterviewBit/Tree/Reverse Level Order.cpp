/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A) {
    vector<int> res;
    stack<vector<int> > st;
    queue<TreeNode*> q;
    
    if(A == NULL)
    {
        return res;
    }
    
    q.push(A);
    st.push({A->val});
    
    while(!q.empty())
    {
        int size = q.size();
        vector<int> temp;
        
        while(size--)
        {
            TreeNode* curr = q.front();
            q.pop();
            
            if(curr->left != NULL)
            {
                q.push(curr->left);
                temp.push_back(curr->left->val);
            }
            
            if(curr->right != NULL)
            {
                q.push(curr->right);
                temp.push_back(curr->right->val);
            }
        }
        
        st.push(temp);
    }
    
    while(!st.empty())
    {
        for(auto value: st.top())
        {
            res.push_back(value);
        }
        
        st.pop();
    }
    
    return res;
}

// Another approach: without using stack.

vector<int> Solution::solve(TreeNode* A) {
    queue<TreeNode*> q;
    q.push(A);
    vector<int> ans;
    //normal level order traversal except pushing right child before left child and reverse whole vector
    while(!q.empty()){
        int sz=q.size();
        while(sz--){
            TreeNode* tmp = q.front();
            ans.push_back(tmp->val);
            q.pop();
            if(tmp->right!=NULL) q.push(tmp->right);
            if(tmp->left!=NULL) q.push(tmp->left);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
