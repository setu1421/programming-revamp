/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct NodePair
{
    TreeNode* node;
    int status = 0;
    
    NodePair(TreeNode* x, int s): node(x), status(s) {}
};

stack<NodePair> st;

void clearStack()
{
    while(!st.empty())
    {
        st.pop();
    }
}

BSTIterator::BSTIterator(TreeNode *root) {
    clearStack();
    if(root != NULL)
    {
        st.push(NodePair(root, 0));
    }
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return !st.empty();
}

/** @return the next smallest number */
int BSTIterator::next() {
    while(!st.empty())
    {
        NodePair &top = st.top();
        
        if(top.status == 0)
        {
            if(top.node->left != NULL)
            {
                st.push(NodePair(top.node->left, 0));
            }
            
            top.status++;
        } else
        {
            NodePair temp = top;
            st.pop();
            
            if(temp.node->right != NULL)
            {
                st.push(NodePair(temp.node->right, 0));
            }
        
            return temp.node->val;
        }
    }
    
    return -1;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
