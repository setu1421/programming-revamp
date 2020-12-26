/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// https://www.youtube.com/watch?v=5cPbNCrdotA

TreeNode* Find(TreeNode* root, int data)
{
   if(root == NULL)
   {
       return NULL;
   } else if(root->val == data)
   {
       return root;
   } else if(data < root->val)
   {
       return Find(root->left, data);
   } else
   {
       return Find(root->right, data);
   }
}

TreeNode* FindMin(TreeNode* root)
{
    if(root == NULL) return NULL;

    if(root->left == NULL)
    {
        return root;
    } else
    {
        return FindMin(root->left);
    }
}
 
TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    TreeNode* searchedNode = Find(A, B);
    
    if(searchedNode == NULL) return NULL;
    // if right node is present, then next greater element will be the min element of right sub tree.
    if(searchedNode->right != NULL)
    {
        return FindMin(searchedNode->right);
    } else
    {
        TreeNode *successor = NULL, *ancestor = A;
        
        while(ancestor != searchedNode)
        {
            if(searchedNode->val < ancestor->val)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            } else
            {
                ancestor = ancestor->right;
            }
        }
        
        return successor;
    }
}
