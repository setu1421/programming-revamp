// https://www.youtube.com/watch?v=jCu-Pd0IjIA
struct node
{
    node* left;
    node* right;

    node()
    {
        left = right = NULL;
    }
} *root;

void buildTrie(int n)
{
    node* curr = root;

    for(int i = 31; i >= 0; i--)
    {
        int b = (n >> i) & 1;

        if(b == 0)
        {
            if(curr->left == NULL)
            {
                curr->left = new node();
            }

            curr = curr->left;
        } else
        {
            if(curr->right == NULL)
            {
                curr->right = new node();
            }

            curr = curr->right;
        }
    }
}

void delTrie(node* root)
{
    if(root == NULL)
    {
        return;
    }

    delTrie(root->left);
    delTrie(root->right);

    delete(root);
}

int calculateMaxXOR(int n)
{
    node* curr = root;
    int currXor = 0;

    for(int i = 31; i >= 0; i--)
    {
        int b = (n >> i) & 1;

        if(b == 0)
        {
            if(curr->right != NULL)
            {
                currXor += pow(2, i);
                curr = curr->right;
            } else
            {
                curr = curr->left;
            }
        } else
        {
            if(curr->left != NULL)
            {
                currXor += pow(2, i);
                curr = curr->left;
            } else
            {
                curr = curr->right;
            }
        }
    }

    return currXor;
}

int Solution::solve(vector<int> &A, vector<int> &B) {
    int maxXOR = INT_MIN;
    root = new node();

    for(int i = 0; i < A.size(); i++)
    {
        buildTrie(A[i]);
    }

    for(int i = 0; i < B.size(); i++)
    {
        maxXOR = max(maxXOR, calculateMaxXOR(B[i]));
    }

    delTrie(root);

    return maxXOR;
}