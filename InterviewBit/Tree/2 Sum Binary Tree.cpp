// https://youtu.be/iK2VFYxFC4o

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// Time Complexity: O(n)
// Space Complexity: O(h) - h -> height of the tree 
 
struct NodePair
{
    TreeNode* node;
    int status = 0;
    
    NodePair(TreeNode* x, int s): node(x), status(s) {}
};

TreeNode* getNextElemFromNormalInorder(stack<NodePair> &ls)
{
    while(!ls.empty())
    {
        NodePair &top = ls.top();
        
        if(top.status == 0)
        {
            if(top.node->left != NULL)
            {
                ls.push(NodePair(top.node->left, 0));
            }
            top.status++;
        } else if(top.status == 1)
        {
            if(top.node->right != NULL)
            {
                ls.push(NodePair(top.node->right, 0));
            }
            
            top.status++;
            
            return top.node;
        } else
        {
            ls.pop();
        }
    }
    
    return NULL;
}

TreeNode* getNextElemFromReverseInorder(stack<NodePair> &rs)
{
    while(!rs.empty())
    {
        NodePair &top = rs.top();
        
        if(top.status == 0)
        {
            if(top.node->right != NULL)
            {
                rs.push(NodePair(top.node->right, 0));
            }
            
            top.status++;
        } else if(top.status == 1)
        {
            if(top.node->left != NULL)
            {
                rs.push(NodePair(top.node->left, 0));
            }
            
            top.status++;
            
            return top.node;
        } else
        {
            rs.pop();
        }
    }
    
    return NULL;
}
 
int Solution::t2Sum(TreeNode* A, int B) {
    stack<NodePair>ls, rs;
    
    ls.push(NodePair(A, 0));
    rs.push(NodePair(A, 0));
    
    TreeNode* leftNode = getNextElemFromNormalInorder(ls);
    TreeNode* rightNode = getNextElemFromReverseInorder(rs);
    // Apply binary search/two pointer approach
    while(leftNode->val < rightNode->val)
    {
        int sum = leftNode->val + rightNode->val;
        
        if(sum == B)
        {
            return 1;
        } else if(sum < B)
        {
            leftNode = getNextElemFromNormalInorder(ls);
        } else
        {
            rightNode = getNextElemFromReverseInorder(rs);
        }
    }
    
    return 0;
}
