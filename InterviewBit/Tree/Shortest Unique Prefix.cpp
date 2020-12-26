struct node
{
    bool endMarked;
    int counter;
    node* next[26 + 1];

    node()
    {
        for(int i = 0; i < 26; i++)
        {
            next[i] = NULL;
        }
        endMarked = false;
        counter = 0;
    }
} *root;

void buildTrie(string word)
{
    int n = word.length();
    node* curr = root;

    for(int i = 0; i < n; i++)
    {
        int id = word[i] - 'a';

        if(curr->next[id] == NULL)
        {
            curr->next[id] = new node();
        }

        curr->counter++;
        curr = curr->next[id];
    }

    curr->endMarked = true;
}

string searchTrie(string word)
{
    string res = "";
    int n = word.length();
    node* curr = root;

    for(int i = 0; i < n; i++)
    {
        int id = word[i] - 'a';

        if(curr->counter > 1)
        {
            curr = curr->next[id];
        } else
        {
            return res;
        }

        res += word[i];
    }

    return res;
}

void delTrie(node* curr)
{
    for(int i = 0; i < 26; i++)
    {
        if(curr->next[i] != NULL)
        {
            delTrie(curr->next[i]);
        }
    }

    delete(curr);
}

vector<string> Solution::prefix(vector<string> &A) {
    vector<string> res;
    int n = A.size();
    root = new node();

    for(int i = 0; i < n; i++)
    {
        buildTrie(A[i]);
    }

    for(int i = 0; i < n; i++)
    {
        res.push_back(searchTrie(A[i]));
    }

    delTrie(root);

    return res;
}
