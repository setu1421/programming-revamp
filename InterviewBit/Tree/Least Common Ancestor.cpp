/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
/*
Linear solution using path calculation :

1) Find path from root to n1 and store it in a vector or array.
2) Find path from root to n2 and store it in another vector or array.
3) Traverse both paths till the values in arrays are same. Return the common element just before the mismatch

*/
 
bool findPath(TreeNode* root, int value, vector<int> &path)
{
    if(root == NULL)
    {
        return false;
    }
    
    path.push_back(root->val);
    
    if(root->val == value)
    {
        return true;
    }
    
    if(findPath(root->left, value, path) || findPath(root->right, value, path))
    {
        return true;
    }
    
    path.pop_back();
    
    return false;
}

int findLeastCommonAncestor(vector<int> pathB, vector<int> pathC)
{
    int nB = pathB.size(), nC = pathC.size();
    int diff = abs(nB - nC), count = nB;
    
    if(nB > nC)
    {
        for(int i = 0; i  < diff; i++)
        {
            pathB.pop_back();
        }
        
        count = nC;
    } else
    {   
        for(int i = 0; i  < diff; i++)
        {
            pathC.pop_back();
        }
        
        count = nB;
    }
    
    
    while(count-- > 0)
    {
        if(pathB.back() == pathC.back())
        {
            return pathB.back();
        } else
        {
            pathB.pop_back();
            pathC.pop_back();
        }
    }
    
    return -1;
}
 
int Solution::lca(TreeNode* A, int B, int C) {
    if(A == NULL)
    {
        return -1;
    }
    
    vector<int>pathB, pathC;
    
    bool isBFound = findPath(A, B, pathB);
    
    if(isBFound)
    {
        bool isCFound = findPath(A, C, pathC);
        
        if(isCFound)
        {
            return findLeastCommonAncestor(pathB, pathC);
        }
    }
    
    return -1;
}

// Another Approach: Without using extra memory.
// https://www.youtube.com/watch?v=13m9ZCB8gjw

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int lcaHelper(TreeNode* root, int B, int C)
{
    if(root == NULL) return -1;
    if(root->val == B || root->val == C) return root->val;
    
    int left = lcaHelper(root->left, B, C);
    int right = lcaHelper(root->right, B, C);
    
    if(left != -1 && right != -1)
    {
        return root->val;
    }
    
    return ((left != -1) ? left: right);
}

bool find(TreeNode* root, int value)
{
    if(root == NULL) return false;
    if(root->val == value) return true;
    
    return (find(root->left, value) || find(root->right, value));
}

int Solution::lca(TreeNode* A, int B, int C) {
    
    if(A == NULL) return -1;
    if(!find(A, B) || !find(A, C)) return -1;
    
    return lcaHelper(A, B, C);
}

// Another Variant: Lowest Common Ancestor of Binary Search Tree
// https://www.youtube.com/watch?v=TIoCCStdiFo&t=190s

TreeNode* lca(TreeNode* root, int n1, int n2) 
{ 
    if (root == NULL) return NULL; 
  
    // If both n1 and n2 are smaller than root, then LCA lies in left 
    if (root->data > n1 && root->data > n2) 
        return lca(root->left, n1, n2); 
  
    // If both n1 and n2 are greater than root, then LCA lies in right 
    if (root->data < n1 && root->data < n2) 
        return lca(root->right, n1, n2); 
  
    return root; 
}



