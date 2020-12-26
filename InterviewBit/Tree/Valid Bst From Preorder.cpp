// Time Complexity: O(nlogn) logn = height of tree.

struct BSTNode
{
    int data;
    BSTNode *left, *right;
    BSTNode(int x) : data(x), left(NULL), right(NULL) {}
};

int ans = 1;

BSTNode* insertNode(BSTNode* root, int data)
{
    if(root == NULL)
    {
        root = new BSTNode(data);
    } else if(data <= root->data)
    {
		// if right subtree is present and now we are finding node in left substree, then invalid.
        if(root->left == NULL && root->right != NULL)
        {
            ans = 0;
        } else
        {
            root->left = insertNode(root->left, data);
        }
    } else
    {
        root->right = insertNode(root->right, data);
    }
    
    return root;
}

int Solution::solve(vector<int> &A) {
    BSTNode* root = NULL;
    ans = 1;
    
    for(int i = 0; i < A.size(); i++)
    {
        if(ans == 1)
        {
            root = insertNode(root, A[i]);
        } else
        {
            break;
        }
    }
    
    return ans;
}

// Another Solution: O(n) using stack

int Solution::solve(vector<int> &A) {
    int n = A.size(), root = INT_MIN;
    stack<int> s;
    
    for(int i = 0; i < n; i++)
    {
        // If we find a node who is on right side and smaller than root, return false 
        if(A[i] <= root)
        {
            return false;
        }
        // If A[i] is in right subtree of stack top, 
        // Keep removing items smaller than A[i] 
        // and make the last removed item as new 
        // root. 
        while(!s.empty() && A[i] > s.top())
        {
            root = s.top();
            s.pop();
        }
        // At this point either stack is empty or 
        // A[i] is smaller than root, push A[i] 
        s.push(A[i]);
    }
    
    return true;
}
