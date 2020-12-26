// Space Complexity: O(h)
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
 
struct NodePair
{
    TreeNode* node;
    int status = 0;
    
    NodePair(TreeNode* x, int s): node(x), status(s) {}
};
 
TreeNode* getNext(stack<NodePair> &st)
{
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
                st.push(NodePair(top.node->right, 0));
            }
            
            return temp.node;
        }
    }
    
    return NULL;
}
 
vector<int> Solution::recoverTree(TreeNode* A) {
    vector<int> res;
    stack<NodePair> st;
    // When only one or no element present in the tree.
    if(A == NULL || (A->left == NULL && A->right == NULL))
    {
        return res;
    }
    
    st.push(NodePair(A, 0));
    
    TreeNode *firstNode = NULL, *secondNode = NULL, *prevNode = NULL;
    
    while(!st.empty())
    {
        TreeNode* currNode = getNext(st);
        
        if(prevNode != NULL && prevNode->val > currNode->val)
        {
            if(firstNode == NULL)
            {
                firstNode = prevNode;
            }
            
            secondNode = currNode;
        }
        
        prevNode = currNode;
    }
    
    if(firstNode != NULL)
    {
        res.push_back(secondNode->val);
        res.push_back(firstNode->val);
    }
    
    return res;
}

// Another approach: using morris inorder traversal
// https://www.youtube.com/watch?v=wGXB9OWhPTg&t=193s
// Space Complexity: O(1)
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
 
pair<TreeNode*, TreeNode*> getNext(TreeNode* root)
{
    TreeNode* curr = root;
    
    while(curr != NULL)
    {
		 //left is null, then return and next node will be the right of current.
        if(curr->left == NULL)
        {
            break;
        } else
        {
			 //find the predecessor.
            TreeNode* predecessor = curr->left;
            //To find predecessor keep going right till right node is not null or right node is not current.
            while(predecessor->right != curr && predecessor->right != NULL)
            {
                predecessor = predecessor->right;
            }
            //if right node is null then go left after establishing link from predecessor to current.
            if(predecessor->right == NULL)
            {
                predecessor->right = curr;
                curr = curr->left;
            } //left is already visit. Go rigth after visiting current.
			else
            {
                predecessor->right = NULL;
                break;
            }
        }
    }
    
    return make_pair(curr, curr->right);
}
 
vector<int> Solution::recoverTree(TreeNode* A) {
    vector<int> res;
    // When only one or no element present in the tree.
    if(A == NULL || (A->left == NULL && A->right == NULL))
    {
        return res;
    }
    
    TreeNode *firstNode = NULL, *secondNode = NULL, *prevNode = NULL, *curr = A;
    
    while(curr != NULL)
    {
        pair<TreeNode*, TreeNode*> ret = getNext(curr);
        
        if(prevNode != NULL && prevNode->val > ret.first->val)
        {
            if(firstNode == NULL)
            {
                firstNode = prevNode;
            }
            
            secondNode = ret.first;
        }
        
        prevNode = ret.first;
        curr = ret.second;
    }
    
    if(firstNode != NULL)
    {
        res.push_back(secondNode->val);
        res.push_back(firstNode->val);
    }
 
    
    return res;
}

