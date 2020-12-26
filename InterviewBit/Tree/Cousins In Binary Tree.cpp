/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> res;

	// If no node or only root present, then there is no cousin.
    if(A == NULL || A->val == B)
    {
        return res;
    }
    // queue of a pair of the node and parent node of that node.
    queue<pair<TreeNode*, TreeNode*> > q;
    bool isFound = false;
    TreeNode* parentNode = NULL;
    
    q.push(make_pair(A, A));
    
    while(!q.empty())
    {
        int size = q.size();
        
        while(size--)
        {
            pair<TreeNode*, TreeNode*> curr = q.front();
            q.pop();
            
            if(curr.first->left != NULL)
            {
                q.push(make_pair(curr.first->left, curr.first));
				// if the left node is the searched node, then we have found the children.
				// we will save the parent node.
                if(curr.first->left->val == B)
                {
                    isFound = true;
                    parentNode = curr.first;
                }
            }
            
            if(curr.first->right != NULL)
            {
                q.push(make_pair(curr.first->right, curr.first));
                // if the right node is the searched node, then we have found the children.
				// we will save the parent node.
                if(curr.first->right->val == B)
                {
                    isFound = true;
                    parentNode = curr.first;
                }
            }
        }
        // If found, then we have all the children of that level.
        if(isFound)
        {
            break;
        }
    }
	
    while(!q.empty())
    {
        pair<TreeNode*, TreeNode*> curr = q.front();
        q.pop();
        // if the current node is not sibling and not the searched node itself, then it is a cousin.
        if(curr.second != parentNode && curr.first->val != B)
        {
            res.push_back(curr.first->val);
        }
    }
    
    return res;
}
