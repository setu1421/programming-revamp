// Recursive approach

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void invertTreeHelper(TreeNode* A)
{
    if(root == NULL)
    {
        return;
    }
    
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    invertTreeHelper(root->left);
    invertTreeHelper(root->right);
}
 
TreeNode* Solution::invertTree(TreeNode* A) {
    invertTreeHelper(A);
    
    return A;
}

// Iterative Function to invert given binary Tree using queue
void invertBinaryTree(TreeNode* root)
{
    // base case: if tree is empty
    if (root == NULL)
        return;
 
    // maintain a queue and push push root node
    queue<TreeNode*> q;
    q.push(root);
 
    // loop till queue is empty
    while (!q.empty())
    {
        // pop top node from queue
        TreeNode* curr = q.front();
        q.pop();
 
        // swap left child with right child
        swap(curr->left, curr->right);
 
        // push left child of popped node to the queue
        if (curr->left)
            q.push(curr->left);
 
        // push right child of popped node to the queue
        if (curr->right)
            q.push(curr->right);
    }
}
